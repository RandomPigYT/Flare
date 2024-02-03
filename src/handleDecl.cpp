#include "handleDecl.hpp"

#include <clang/AST/ASTContext.h>
#include <clang/AST/Decl.h>
#include <clang/AST/RecordLayout.h>

void Reflection::handleRecordDecl(clang::RecordDecl *rd,
                                  struct context_t &ctx) {
  if (!rd->isStruct() && !rd->isUnion()) return;

  if (rd->isAnonymousStructOrUnion()) return;

  Reflection::typeInfo_t t;

  t.ID = rd->getID();
  t.fileName.assign(ctx.filename);
  t.name = rd->getNameAsString();
  t.recordType = rd->isStruct() ? RECORD_TYPE_STRUCT : RECORD_TYPE_UNION;

  ctx.typeinfo.emplace_back(t);
}

void Reflection::handleTypedefDecl(clang::TypedefDecl *td,
                                   struct context_t &ctx) {
  clang::QualType q = td->getUnderlyingType();

  clang::RecordDecl *rd = q->getAsRecordDecl();
  if (!rd || (!rd->isStruct() && !rd->isUnion())) return;

  for (uint64_t i = 0; i < ctx.typeinfo.size(); i++) {
    if (ctx.typeinfo[i].fileName != ctx.filename ||
        ctx.typeinfo[i].ID != rd->getID())
      continue;

    ctx.typeinfo[i].aliases.emplace_back(td->getNameAsString());
  }
}

void Reflection::handleFieldDecl(clang::FieldDecl *fd, struct context_t &ctx) {
  const clang::ASTRecordLayout &layout =
      ctx.context->getASTRecordLayout(clang::dyn_cast<clang::RecordDecl>(fd));
}
