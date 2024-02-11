
#include "handleDecl.hpp"

#include <clang/AST/ASTContext.h>
#include <clang/AST/Decl.h>
#include <clang/AST/Expr.h>
#include <clang/AST/RecordLayout.h>
#include <clang/AST/Type.h>
#include <llvm/IR/DerivedTypes.h>

#include "ast.hpp"
#include "constructSpec.hpp"

void Reflection::handleRecordDecl(clang::RecordDecl *rd, struct context &ctx) {
  if (!rd->isStruct() && !rd->isUnion()) return;

  if (rd->isAnonymousStructOrUnion()) return;

  struct Reflection::typeInfo t;

  t.ID = rd->getID();
  t.fileName.assign(ctx.filename);
  t.name = rd->getNameAsString();
  t.recordType = rd->isStruct() ? RECORD_TYPE_STRUCT : RECORD_TYPE_UNION;

  ctx.typeinfo.emplace_back(t);
}

void Reflection::handleTypedefDecl(clang::TypedefDecl *td,
                                   struct context &ctx) {
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

static enum Reflection::types getFieldType(clang::FieldDecl *fd,
                                           clang::QualType type) {
  if (fd->isBitField()) {
    return Reflection::FIELD_TYPE_BITFIELD;
  }

  if (type->isRecordType()) {
    return Reflection::FIELD_TYPE_RECORD;
  }

  if (type->isArrayType()) {
    return Reflection::FIELD_TYPE_ARRAY;
  }

  if (type->isPointerType()) {
    return Reflection::FIELD_TYPE_PTR;
  }

  if (type->isEnumeralType()) {
    return Reflection::FIELD_TYPE_ENUM;
  }

  if (type->isFunctionType()) {
    return Reflection::FIELD_TYPE_FUNCTION;
  }

  // TODO: Test for primitive types

  return Reflection::NONE;
}

// For arrays and pointers

static int64_t findRecord(int64_t ID, std::string filename,
                          const struct Reflection::context &ctx) {
  for (uint64_t i = 0; i < ctx.typeinfo.size(); i++) {
    if (ctx.typeinfo[i].ID == ID && ctx.typeinfo[i].fileName == filename)
      return i;
  }

  return -1;
}

void Reflection::handleFieldDecl(clang::FieldDecl *fd, struct context &ctx,
                                 clang::RecordDecl *p, int64_t offset) {
  if (fd->getParent()->isAnonymousStructOrUnion() && p == nullptr) {
    return;
  }

  clang::RecordDecl *parent = !p ? fd->getParent() : p;
  if (parent->isInvalidDecl()) return;

  const clang::ASTRecordLayout &layout =
      ctx.context->getASTRecordLayout(parent);

  struct Reflection::field f;
  f.name = fd->getNameAsString();
  f.offset =
      (offset == -1 ? layout.getFieldOffset(fd->getFieldIndex()) : offset);
  f.type.type = Reflection::NONE;

  clang::QualType fieldType = fd->getType();

  enum Reflection::types typeEnum = getFieldType(fd, fieldType);

  // Experimentation
  // if (fieldType->isArrayType() && fieldType->isConstantArrayType())
  //   printf("array size: %ld\n",
  //          clang::dyn_cast<clang::ConstantArrayType>(fieldType.getTypePtr())
  //              ->getSize()
  //              .getSExtValue());
  // else if (fieldType->isArrayType())
  //   printf("Not constant array type: %s\tparent: %s\tfilename: %s\n",
  //          fd->getNameAsString().c_str(), parent->getNameAsString().c_str(),
  //          ctx.filename);

  if (typeEnum == Reflection::FIELD_TYPE_BITFIELD) {
    f.type = Reflection::constructBitFieldSpec(fd, ctx.context);
  }

  else if (typeEnum == Reflection::FIELD_TYPE_RECORD) {
    f.type = Reflection::constructRecordSpec(fieldType->getAsRecordDecl(),
                                             ctx.filename);
  }

  else if (typeEnum == Reflection::FIELD_TYPE_PTR) {
    f.type = Reflection::constructPtrSpec(
        clang::dyn_cast<clang::PointerType>(fieldType.getTypePtr()), ctx);
  }

  int64_t typeIndex = findRecord(parent->getID(), ctx.filename, ctx);
  if (typeIndex < 0) {
    fprintf(stderr, "Fatal: Failed to find type: %ld\t%s\t%s\n",
            parent->getID(), parent->getNameAsString().c_str(), ctx.filename);
    exit(EXIT_FAILURE);
  }

  ctx.typeinfo[typeIndex].fields.emplace_back(f);

  // clang::Decl *declForField =
  // clang::dyn_cast<clang::Decl>(fd->getUnderlyingDecl());
}
