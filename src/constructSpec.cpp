#include "constructSpec.hpp"

#include <stdio.h>

struct Reflection::typeSpecifier
Reflection::constructRecordSpec(clang::RecordDecl *rd, const char *filename) {
  struct Reflection::typeSpecifier spec;
  spec.type = rd->isStruct() ? Reflection::FIELD_TYPE_STRUCT
                             : Reflection::FIELD_TYPE_UNION;

  spec.info = malloc(sizeof(struct Reflection::recordRef));

  struct Reflection::recordRef *temp =
    (struct Reflection::recordRef *)spec.info;
  temp->ID = rd->getID();
  temp->fileName = strdup(filename);

  return spec;
}

struct Reflection::typeSpecifier
Reflection::constructBitFieldSpec(clang::FieldDecl *fd,
                                  const clang::ASTContext *context) {
  struct Reflection::typeSpecifier spec;
  spec.type = Reflection::FIELD_TYPE_BITFIELD;

  spec.info = malloc(sizeof(struct Reflection::bitFieldRef));

  struct Reflection::bitFieldRef *temp =
    (struct Reflection::bitFieldRef *)spec.info;

  clang::Expr::EvalResult res;
  fd->getBitWidth()->EvaluateAsInt(res, *context);

  temp->bitWidth = res.Val.getInt().getExtValue();

  return spec;
}

static enum Reflection::types getPointeeType(clang::QualType type) {
  if (type->isRecordType()) {
    return Reflection::FIELD_TYPE_RECORD;
  }

  // if (type->isPointerType()) {
  //   return Reflection::FIELD_TYPE_PTR;
  // }

  if (type->isArrayType()) {
    return Reflection::FIELD_TYPE_ARRAY;
  }

  if (type->isEnumeralType()) {
    return Reflection::FIELD_TYPE_ENUM;
  }

  if (type->isFunctionType()) {
    return Reflection::FIELD_TYPE_FUNCTION;
  }

  // TODO: Test for primitive types

  return Reflection::FIELD_TYPE_PRIMITIVE;
}

static void setPtrRef(struct Reflection::ptrRef *p,
                      const clang::PointerType *type,
                      const struct Reflection::context &ctx) {
  clang::QualType temp = type->getPointeeType();
  uint32_t level = 1;
  while (temp->isPointerType()) {
    temp = temp->getPointeeType();
    level++;
  }

  p->level = level;

  enum Reflection::types typeEnum = getPointeeType(temp);

  if (typeEnum == Reflection::FIELD_TYPE_RECORD) {
    clang::RecordDecl *rd = temp->getAsRecordDecl();
    p->type = Reflection::constructRecordSpec(rd, ctx.filename);
  }

  // TODO: primitive types
}

struct Reflection::typeSpecifier
Reflection::constructPtrSpec(const clang::PointerType *type,
                             const struct Reflection::context &ctx) {
  struct Reflection::typeSpecifier spec;
  spec.type = Reflection::FIELD_TYPE_PTR;

  spec.info = malloc(sizeof(struct Reflection::ptrRef));

  struct Reflection::ptrRef *temp = (struct Reflection::ptrRef *)spec.info;

  setPtrRef(temp, type, ctx);

  // std::cout << "record type? " << type->getPointeeType()->isFunctionType()
  //           << std::endl;

  return spec;
}

struct Reflection::typeSpecifier
Reflection::constructPrimitiveSpec(clang::QualType) {
  struct Reflection::typeSpecifier spec;

  // TODO: Implement this, you lazy procrastinating fuck

  return spec;
}
