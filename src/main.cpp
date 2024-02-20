#include <clang/AST/Type.h>
#include <clang/Frontend/FrontendAction.h>
#include <clang/Frontend/FrontendActions.h>
#include <clang/Tooling/CommonOptionsParser.h>
#include <clang/Tooling/Tooling.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <filesystem>

#include "ast.hpp"
#include "handleDecl.hpp"
#include "typeinfo.hpp"
#include "context.hpp"
#include "emit.hpp"

#define START_OPTIONS "--opts"
#define OUT_FILE "--out"
#define REFLECTION_HEADER "--header"

bool parseArgs(struct Reflection::context &ctx, uint64_t *optionStart) {
  std::vector<const char *> &args = ctx.args;

  bool reachedOptions = false;
  bool gotOutFile = false;
  bool gotIncludeFile = false;

  for (uint64_t i = 0; i < args.size(); i++) {
    if (std::string(args[i]) == START_OPTIONS) {
      reachedOptions = true;
      *optionStart = i;
      continue;
    }

    if (!reachedOptions) {
      continue;
    }

    std::string temp(args[i]);

    if (temp == OUT_FILE) {
      if (i == args.size() - 1) {
        return false;
      }
      ctx.outFile = std::string(args[i + 1]);
      gotOutFile = true;
      i++;
    }

    if (temp == REFLECTION_HEADER) {
      if (i == args.size() - 1) {
        return false;
      }
      ctx.reflectionHeader = std::string(args[i + 1]);
      gotIncludeFile = true;
      i++;
    }
  }

  return (gotOutFile && gotIncludeFile);
}

int main(int argc, char **argv) {
  if (argc <= 1) {
    fprintf(stderr, "Bad usage\n");
    return EXIT_FAILURE;
  }

  llvm::cl::OptionCategory catagory("Reflection");

  Reflection::context ctx;
  ctx.filename = nullptr;

  for (int i = 0; i < argc; i++) {
    ctx.args.push_back(argv[i]);
  }

  uint64_t optionsStart;
  if (parseArgs(ctx, &optionsStart)) {
    printf("\nOut file: %s\nReflection header: %s\n", ctx.outFile.c_str(),
           ctx.reflectionHeader.c_str());
  }

  else {
    fprintf(stderr, "Bad usage\n");
    return EXIT_FAILURE;
  }

  int numArgs = optionsStart;
  llvm::Expected<clang::tooling::CommonOptionsParser> optionsParser =
    clang::tooling::CommonOptionsParser::create(numArgs, (const char **)argv,
                                                catagory);

  clang::tooling::ClangTool tool(optionsParser->getCompilations(),
                                 optionsParser->getSourcePathList());

  tool.run(Reflection::customFrontendActionFactory(ctx).get());

  //for (auto i : ctx.typeinfo) {
  //  std::cout
  //    << "Type: "
  //    << (i.recordType == Reflection::RECORD_TYPE_STRUCT ? "Struct" : "Union")
  //    << "\t";
  //  std::cout << "Name: " << (i.name.length() ? i.name : "(Unnamed)")
  //            << "\tTypedefs: ";
  //  for (auto j : i.aliases) {
  //    std::cout << j << "\t";
  //  }

  //  std::cout << std::endl << "Fields" << std::endl;
  //  std::cout << "\t";
  //  for (auto j : i.fields) {
  //    std::cout << "Name: " << (j.name.length() ? j.name : "(Unnamed)") << "\t"
  //              << "Type: " << (j.type.type & (0xffffffff ^ (1 << 31))) << "\t"
  //              << ((j.type.type & (1 << 31)) ? "complex" : "") << "\n\t";
  //  }
  //  std::cout << std::endl;
  //}

  //for (auto i : ctx.enumInfo) {
  //  std::cout << "Enum name: " << (i.name.length() ? i.name : "(Unnamed)")
  //            << "\t";
  //  std::cout << "Typedefs: ";
  //  for (auto j : i.aliases) {
  //    std::cout << j << "\t";
  //  }
  //  std::cout << std::endl << "Constants" << std::endl << "\t";

  //  for (auto j : i.constants) {
  //    std::cout << "Name: " << j.name << "\t"
  //              << "Value: " << j.value << "\n\t";
  //  }
  //  std::cout << std::endl;
  //}

  Reflection::emit(ctx);
  return 0;
}
