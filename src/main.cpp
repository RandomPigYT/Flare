#include <clang/AST/ASTConsumer.h>
#include <clang/AST/RecursiveASTVisitor.h>
#include <clang/Frontend/FrontendAction.h>
#include <clang/Frontend/FrontendActions.h>
#include <clang/Tooling/CommonOptionsParser.h>
#include <clang/Tooling/Tooling.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>

#include "handleDecl.hpp"
#include "typeinfo.hpp"

struct context_t {
  using typeInfoVec = std::vector<Reflection::typeInfo_t>;

  typeInfoVec typeinfo;
  std::vector<const char *> args;
  char *filename;
};

// Define a visitor for traversing the AST
class ASTDeclVisitor : public clang::RecursiveASTVisitor<ASTDeclVisitor> {
  struct context_t &m_ctx;

 public:
  ASTDeclVisitor(struct context_t &ctx) : m_ctx(ctx) {}

  ~ASTDeclVisitor() { free(m_ctx.filename); }

  // Override method for visiting all AST nodes
  bool TraverseDecl(clang::Decl *D) {
    if (clang::TranslationUnitDecl *tr =
            clang::dyn_cast<clang::TranslationUnitDecl>(D)) {
      printf("file: %s\n\nTranslation ID: %ld\n", m_ctx.filename, tr->getID());
    }

    // D->dump(llvm::outs());

    if (clang::RecordDecl *rd = clang::dyn_cast<clang::RecordDecl>(D)) {
      printf("%s\t%ld\n", rd->getNameAsString().c_str(), rd->getID());

      Reflection::handleRecordDecl(rd, m_ctx.filename, m_ctx.typeinfo);
    }

    if (clang::TypedefDecl *td = clang::dyn_cast<clang::TypedefDecl>(D)) {
      Reflection::handleTypedefDecl(td, m_ctx.filename, m_ctx.typeinfo);

      clang::QualType q = td->getUnderlyingType();
      clang::RecordDecl *rd = q->getAsRecordDecl();

      if (rd) printf("typedef: %s\t", td->getNameAsString().c_str());
      if (rd) printf("%ld\n", rd->getID());
    }
    return RecursiveASTVisitor<ASTDeclVisitor>::TraverseDecl(D);
  }
};

// Define an ASTConsumer for processing the AST
class MyASTConsumer : public clang::ASTConsumer {
  ASTDeclVisitor Visitor;

 public:
  MyASTConsumer(struct context_t &ctx) : Visitor(ctx) {}

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

  struct context_t &m_ctx;

 public:
  ReflectionASTAction(struct context_t &ctx) : m_ctx(ctx){};

 protected:
  // Override method for creating the AST consumer
  std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(
      clang::CompilerInstance &, clang::StringRef file) override {
    m_ctx.filename = strdup(file.str().c_str());
    return std::make_unique<MyASTConsumer>(m_ctx);
  }
};

std::unique_ptr<clang::tooling::FrontendActionFactory>
customFrontendActionFactory(struct context_t &ctx) {
  class SimpleFrontendActionFactory
      : public clang::tooling::FrontendActionFactory {
   public:
    SimpleFrontendActionFactory(struct context_t &ctx) : m_ctx(ctx) {}

    std::unique_ptr<clang::FrontendAction> create() override {
      return std::make_unique<ReflectionASTAction>(m_ctx);
    }

   private:
    struct context_t &m_ctx;
  };

  return std::unique_ptr<clang::tooling::FrontendActionFactory>(
      new SimpleFrontendActionFactory(ctx));
}

int main(int argc, char **argv) {
  if (argc <= 1) {
    fprintf(stderr, "Bad usage\n");
    return EXIT_FAILURE;
  }

  llvm::cl::OptionCategory catagory("Reflection");

  struct context_t ctx;
  ctx.filename = nullptr;

  for (int i = 0; i < argc; i++) {
    ctx.args.emplace_back(argv[i]);
  }

  llvm::Expected<clang::tooling::CommonOptionsParser> optionsParser =
      clang::tooling::CommonOptionsParser::create(argc, (const char **)argv,
                                                  catagory);

  clang::tooling::ClangTool tool(optionsParser->getCompilations(),
                                 optionsParser->getSourcePathList());

  tool.run(customFrontendActionFactory(ctx).get());

  for (auto i : ctx.typeinfo) {
    std::cout << i.fileName << std::endl;
  }

  return 0;
}
