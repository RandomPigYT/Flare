#include <clang/AST/AST.h>
#include <clang/AST/ASTConsumer.h>
#include <clang/AST/RecursiveASTVisitor.h>
#include <clang/Basic/IdentifierTable.h>
#include <clang/Basic/LangOptions.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Frontend/FrontendAction.h>
#include <clang/Frontend/FrontendActions.h>
#include <clang/Frontend/FrontendPluginRegistry.h>
#include <clang/Tooling/CommonOptionsParser.h>
#include <clang/Tooling/Tooling.h>
#include <llvm/ADT/StringRef.h>
#include <llvm/IR/Value.h>
#include <llvm/Support/CommandLine.h>
#include <llvm/Support/raw_ostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>

#include "handleDecl.hpp"
#include "typeinfo.hpp"

// Define a visitor for traversing the AST
class ASTDeclVisitor : public clang::RecursiveASTVisitor<ASTDeclVisitor> {
  using typeInfoVec = std::vector<Reflection::typeInfo_t>;

  char *filename;
  typeInfoVec &m_typeinfo;

 public:
  ASTDeclVisitor(typeInfoVec &typeinfo, char *file) : m_typeinfo(typeinfo) {
    filename = file;
  }

  ~ASTDeclVisitor() { free(filename); }

  // Override method for visiting all AST nodes
  bool TraverseDecl(clang::Decl *D) {
    if (clang::TranslationUnitDecl *tr =
            clang::dyn_cast<clang::TranslationUnitDecl>(D)) {
      printf("file: %s\n\nTranslation ID: %ld\n", filename, tr->getID());
    }

    // D->dump(llvm::outs());

    if (clang::RecordDecl *rd = clang::dyn_cast<clang::RecordDecl>(D)) {
      printf("%s\t%ld\n", rd->getNameAsString().c_str(), rd->getID());

      Reflection::handleRecordDecl(rd, filename, m_typeinfo);
    }

    if (clang::TypedefDecl *td = clang::dyn_cast<clang::TypedefDecl>(D)) {
      Reflection::handleTypedefDecl(td, filename, m_typeinfo);

      clang::QualType q = td->getUnderlyingType();
      clang::RecordDecl *rd = q->getAsRecordDecl();

      if (rd) printf("typedef: %s\t", td->getNameAsString().c_str());
      if (rd) printf("%ld\n", rd->getID());
    }
    return RecursiveASTVisitor::TraverseDecl(D);
  }
};

// Define an ASTConsumer for processing the AST
class MyASTConsumer : public clang::ASTConsumer {
  using typeInfoVec = std::vector<Reflection::typeInfo_t>;

  char *filename;
  ASTDeclVisitor Visitor;

 public:
  MyASTConsumer(typeInfoVec &typeinfo, char *file)
      : filename(file), Visitor(typeinfo, filename) {}

  // Override method for setting up the AST visitor
  void HandleTranslationUnit(clang::ASTContext &Context) override {
    if (Visitor.TraverseDecl(Context.getTranslationUnitDecl())) {
      printf("Done!\n");
    }
  }
};

// Define a FrontendAction for the plugin
class ReflectionASTAction : public clang::ASTFrontendAction {
  using typeInfoVec = std::vector<Reflection::typeInfo_t>;

  typeInfoVec &m_typeinfo;

 public:
  ReflectionASTAction(typeInfoVec &typeinfo) : m_typeinfo(typeinfo){};

 protected:
  // Override method for creating the AST consumer
  std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(
      clang::CompilerInstance &, clang::StringRef file) override {
    return std::make_unique<MyASTConsumer>(m_typeinfo,
                                           strdup((char *)file.str().c_str()));
  }
};

std::unique_ptr<clang::tooling::FrontendActionFactory>
customFrontendActionFactory(std::vector<Reflection::typeInfo_t> &typeinfo) {
  using typeInfoVec = std::vector<Reflection::typeInfo_t>;

  class SimpleFrontendActionFactory
      : public clang::tooling::FrontendActionFactory {
   public:
    SimpleFrontendActionFactory(typeInfoVec &typeinfo) : m_typeinfo(typeinfo) {}

    std::unique_ptr<clang::FrontendAction> create() override {
      return std::make_unique<ReflectionASTAction>(m_typeinfo);
    }

   private:
    typeInfoVec &m_typeinfo;
  };

  return std::unique_ptr<clang::tooling::FrontendActionFactory>(
      new SimpleFrontendActionFactory(typeinfo));
}

int main(int argc, char **argv) {
  if (argc <= 1) {
    fprintf(stderr, "Bad usage\n");
    return EXIT_FAILURE;
  }

  llvm::cl::OptionCategory catagory("Reflection");

  std::vector<Reflection::typeInfo_t> typeinfo;

  llvm::Expected<clang::tooling::CommonOptionsParser> optionsParser =
      clang::tooling::CommonOptionsParser::create(argc, (const char **)argv,
                                                  catagory);

  clang::tooling::ClangTool tool(optionsParser->getCompilations(),
                                 optionsParser->getSourcePathList());

  tool.run(customFrontendActionFactory(typeinfo).get());
  return 0;
}
