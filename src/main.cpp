#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>

#include "clang/AST/AST.h"
#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Basic/IdentifierTable.h"
#include "clang/Basic/LangOptions.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendAction.h"
#include "clang/Frontend/FrontendActions.h"
#include "clang/Frontend/FrontendPluginRegistry.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/IR/Value.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/raw_ostream.h"

using namespace clang;

// Define a visitor for traversing the AST
class ASTDeclVisitor : public RecursiveASTVisitor<ASTDeclVisitor> {
  char *filename;

 public:
  ASTDeclVisitor(char *file) {
    filename = (char *)malloc(strlen(file));
    strcpy(filename, file);
  }

  ~ASTDeclVisitor() { free(filename); }

  // Override method for visiting all AST nodes
  bool TraverseDecl(Decl *D) {
    if (TranslationUnitDecl *tr = dyn_cast<TranslationUnitDecl>(D)) {
      printf("file: %s\n", filename);
    }

    // D->dump(llvm::outs());
    RecordDecl *rd = clang::dyn_cast<RecordDecl>(D);

    if (rd) {
      printf("%s\t%ld\n", rd->getNameAsString().c_str(), rd->getID());
    }

    if (TypedefDecl *TD = dyn_cast<TypedefDecl>(D)) {
      QualType q = TD->getUnderlyingType();
      rd = q->getAsRecordDecl();

      if (rd) printf("typedef: %s\t", TD->getNameAsString().c_str());
      if (rd) printf("%ld\n", rd->getID());
    }
    return RecursiveASTVisitor::TraverseDecl(D);
  }
};

// Define an ASTConsumer for processing the AST
class MyASTConsumer : public ASTConsumer {
  char *filename;
  ASTDeclVisitor Visitor;

 public:
  MyASTConsumer(char *file) : filename(file), Visitor(filename) {}

  // Override method for setting up the AST visitor
  void HandleTranslationUnit(ASTContext &Context) override {
    if (Visitor.TraverseDecl(Context.getTranslationUnitDecl())) {
      printf("Done!\n");
    }
  }
};

// Define a FrontendAction for the plugin
class Reflection : public ASTFrontendAction {
  std::vector<std::string> args;

 protected:
  // Override method for creating the AST consumer
  std::unique_ptr<ASTConsumer> CreateASTConsumer(CompilerInstance &,
                                                 StringRef file) override {
    return std::make_unique<MyASTConsumer>((char *)file.str().c_str());
  }
};

llvm::cl::OptionCategory catagory("Reflection");

int main(int argc, char **argv) {
  if (argc <= 1) {
    fprintf(stderr, "Bad usage\n");
    return EXIT_FAILURE;
  }

  llvm::Expected<clang::tooling::CommonOptionsParser> optionsParser =
      clang::tooling::CommonOptionsParser::create(argc, (const char **)argv,
                                                  catagory);

  clang::tooling::ClangTool tool(optionsParser->getCompilations(),
                                 optionsParser->getSourcePathList());

  tool.run(clang::tooling::newFrontendActionFactory<Reflection>().get());

  return 0;
}
