#ifndef REFLECTION_AST_H
#define REFLECTION_AST_H

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

namespace Reflection {

struct context_t {
  using typeInfoVec = std::vector<Reflection::typeInfo_t>;

  typeInfoVec typeinfo;
  std::vector<const char *> args;
  char *filename;
};

std::unique_ptr<clang::tooling::FrontendActionFactory>
customFrontendActionFactory(struct context_t &ctx);

class ASTDeclVisitor : public clang::RecursiveASTVisitor<ASTDeclVisitor> {
  struct context_t &m_ctx;

 public:
  ASTDeclVisitor(struct context_t &ctx) : m_ctx(ctx) {}

  ~ASTDeclVisitor() { free(m_ctx.filename); }

  bool TraverseDecl(clang::Decl *D);
};

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

}  // namespace Reflection

#endif
