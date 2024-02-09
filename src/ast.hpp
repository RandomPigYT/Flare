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

#include "typeinfo.hpp"

namespace Reflection {

struct context {
  using typeInfoVec = std::vector<struct Reflection::typeInfo_t>;

  typeInfoVec typeinfo;
  std::vector<const char *> args;
  char *filename;

  clang::ASTContext *context;
};

std::unique_ptr<clang::tooling::FrontendActionFactory>
customFrontendActionFactory(struct context &ctx);

class ASTDeclVisitor : public clang::RecursiveASTVisitor<ASTDeclVisitor> {
  struct context &m_ctx;

 public:
  ASTDeclVisitor(struct context &ctx) : m_ctx(ctx) {}

  ~ASTDeclVisitor() { free(m_ctx.filename); }

  bool TraverseDecl(clang::Decl *D);
};

class MyASTConsumer : public clang::ASTConsumer {
  ASTDeclVisitor Visitor;
  struct context &m_ctx;

 public:
  MyASTConsumer(struct context &ctx) : Visitor(ctx), m_ctx(ctx) {}

  // Override method for setting up the AST visitor
  void HandleTranslationUnit(clang::ASTContext &Context) override {
    m_ctx.context = &Context;

    if (Visitor.TraverseDecl(m_ctx.context->getTranslationUnitDecl())) {
      printf("Done!\n");
    }
  }
};

class ReflectionASTAction : public clang::ASTFrontendAction {
  using typeInfoVec = std::vector<Reflection::typeInfo_t>;

  struct context &m_ctx;

 public:
  ReflectionASTAction(struct context &ctx) : m_ctx(ctx){};

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
