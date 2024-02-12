#include <clang/Frontend/FrontendAction.h>
#include <clang/Frontend/FrontendActions.h>
#include <clang/Tooling/CommonOptionsParser.h>
#include <clang/Tooling/Tooling.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>

#include "ast.hpp"
#include "handleDecl.hpp"
#include "typeinfo.hpp"
#include "context.hpp"

int main(int argc, char **argv) {
  if (argc <= 1) {
    fprintf(stderr, "Bad usage\n");
    return EXIT_FAILURE;
  }

  llvm::cl::OptionCategory catagory("Reflection");

  Reflection::context ctx;
  ctx.filename = nullptr;

  for (int i = 0; i < argc; i++) {
    ctx.args.emplace_back(argv[i]);
  }

  llvm::Expected<clang::tooling::CommonOptionsParser> optionsParser =
    clang::tooling::CommonOptionsParser::create(argc, (const char **)argv,
                                                catagory);

  clang::tooling::ClangTool tool(optionsParser->getCompilations(),
                                 optionsParser->getSourcePathList());

  tool.run(Reflection::customFrontendActionFactory(ctx).get());

  for (auto i : ctx.typeinfo) {
    std::cout
      << "Type: "
      << (i.recordType == Reflection::RECORD_TYPE_STRUCT ? "Struct" : "Union")
      << "\t";
    std::cout << "Name: " << (i.name.length() ? i.name : "(Unnamed)")
              << "\tTypedefs: ";
    for (auto j : i.aliases) {
      std::cout << j << "\t";
    }

    std::cout << std::endl << "Fields" << std::endl;
    std::cout << "\t";
    for (auto j : i.fields) {
      std::cout << "Name: " << (j.name.length() ? j.name : "(Unnamed)") << "\t"
                << "Type: " << j.type.type << "\n\t";
    }
    std::cout << std::endl;
  }

  for (auto i : ctx.enumInfo) {
    std::cout << "Enum name: " << (i.name.length() ? i.name : "(Unnamed)")
              << "\t";
    std::cout << "Typedefs: ";
    for (auto j : i.aliases) {
      std::cout << j << "\t";
    }
    std::cout << std::endl << "Constants" << std::endl << "\t";

    for (auto j : i.constants) {
      std::cout << "Name: " << j.name << "\t"
                << "Value: " << j.value << "\n\t";
    }
    std::cout << std::endl;
  }

  // for (uint64_t i = 0; i < ctx.typeinfo.size(); i++) {
  //   for (uint64_t j = 0; j < ctx.typeinfo[i].fields.size(); j++) {
  //     if (ctx.typeinfo[i].fields[j].type.type ==
  //     Reflection::FIELD_TYPE_STRUCT)
  //       free(((struct Reflection::recordRef_t *)ctx.typeinfo[i]
  //                 .fields[j]
  //                 .type.info)
  //                ->fileName);

  //    if (ctx.typeinfo[i].fields[j].type.type ==
  //            Reflection::FIELD_TYPE_STRUCT ||
  //        ctx.typeinfo[i].fields[j].type.type ==
  //            Reflection::FIELD_TYPE_BITFIELD)
  //      free(ctx.typeinfo[i].fields[j].type.info);
  //  }
  //}

  return 0;
}
