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

int main(int argc, char **argv) {
  if (argc <= 1) {
    fprintf(stderr, "Bad usage\n");
    return EXIT_FAILURE;
  }

  llvm::cl::OptionCategory catagory("Reflection");

  Reflection::context_t ctx;
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
    std::cout << "Type: "
              << (i.recordType == Reflection::RECORD_TYPE_STRUCT ? "Struct"
                                                                 : "Union")
              << "\t";
    std::cout << "Name: " << (i.name.length() ? i.name : "(Unnamed)")
              << "\tTypedefs: ";
    for (auto j : i.aliases) {
      std::cout << j << "\t";
    }
    std::cout << std::endl;
  }

  return 0;
}
