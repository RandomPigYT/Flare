#include "constructSpec.hpp"
#include <clang/AST/Decl.h>
#include <clang/AST/Type.h>

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
Reflection::constructEnumSpec(clang::EnumDecl *ed, const char *filename) {
  struct Reflection::typeSpecifier spec;
  spec.type = Reflection::FIELD_TYPE_ENUM;
  spec.info = malloc(sizeof(struct Reflection::enumRef));

  struct Reflection::enumRef *temp = (struct Reflection::enumRef *)spec.info;
  temp->ID = ed->getID();
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

struct Reflection::typeSpecifier
Reflection::constructPrimitiveSpec(clang::QualType type) {
  struct Reflection::typeSpecifier spec;

  if (type->isVectorType()) {
    // TODO: Add support for vector types declared with __attribute__ ((vector_size (n)))
  }

  else if (!type->isAnyComplexType()) {
    spec.type = (enum Reflection::types)clang::dyn_cast<clang::BuiltinType>(
                  type.getTypePtr())
                  ->getKind();
  }

  else {
    const clang::ComplexType *ct =
      clang::dyn_cast<clang::ComplexType>(type.getTypePtr());

    enum Reflection::types typeEnum =
      (enum Reflection::types)clang::dyn_cast<clang::BuiltinType>(
        ct->getElementType().getTypePtr())
        ->getKind();

    spec.type = (enum Reflection::types)REF_MAKE_COMPLEX(typeEnum);
  }

  return spec;
}

static enum Reflection::types getPointeeType(clang::QualType type) {
  if (type->isRecordType()) {
    return Reflection::FIELD_TYPE_RECORD;
  }

  if (type->isPointerType()) {
    return Reflection::FIELD_TYPE_PTR;
  }

  if (type->isArrayType()) {
    return Reflection::FIELD_TYPE_ARRAY;
  }

  if (type->isEnumeralType()) {
    return Reflection::FIELD_TYPE_ENUM;
  }

  if (type->isFunctionType()) {
    return Reflection::FIELD_TYPE_FUNCTION;
  }

  if (type->isBuiltinType() || type->isAnyComplexType() ||
      type->isVectorType()) {
    return Reflection::FIELD_TYPE_PRIMITIVE;
  }

  return Reflection::NONE;
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

  else if (typeEnum == Reflection::FIELD_TYPE_PRIMITIVE) {
    p->type = Reflection::constructPrimitiveSpec(temp);
  }

  else if (typeEnum == Reflection::FIELD_TYPE_ENUM) {
    clang::EnumDecl *ed =
      clang::dyn_cast<clang::EnumDecl>(temp->getAsTagDecl());
    p->type = Reflection::constructEnumSpec(ed, ctx.filename);
  }
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

static void setArrayRef(struct Reflection::arrayRef *a,
                        const clang::ArrayType *type,
                        const struct Reflection::context &ctx) {
  if (type->isConstantArrayType()) {
    const clang::ConstantArrayType *cat =
      clang::dyn_cast<clang::ConstantArrayType>(type);
    a->size = cat->getSize().getSExtValue();
  }

  clang::QualType temp = type->getElementType();
  enum Reflection::types typeEnum = getPointeeType(temp);

  if (typeEnum == Reflection::FIELD_TYPE_RECORD) {
    clang::RecordDecl *rd = temp->getAsRecordDecl();
    a->type = Reflection::constructRecordSpec(rd, ctx.filename);
  }

  else if (typeEnum == Reflection::FIELD_TYPE_ENUM) {
    clang::EnumDecl *ed =
      clang::dyn_cast<clang::EnumDecl>(temp->getAsTagDecl());
    a->type = Reflection::constructEnumSpec(ed, ctx.filename);
  }

  else if (typeEnum == Reflection::FIELD_TYPE_PTR) {
    a->type = Reflection::constructPtrSpec(
      clang::dyn_cast<clang::PointerType>(temp.getTypePtr()), ctx);
  }

  else if (typeEnum == Reflection::FIELD_TYPE_PRIMITIVE) {
    a->type = Reflection::constructPrimitiveSpec(temp);
  }
}

struct Reflection::typeSpecifier
Reflection::constructArraySpec(const clang::ArrayType *type,
                               const struct Reflection::context &ctx) {
  struct Reflection::typeSpecifier spec;
  spec.type = Reflection::FIELD_TYPE_ARRAY;

  spec.info = malloc(sizeof(struct Reflection::arrayRef));

  struct Reflection::arrayRef *temp = (struct Reflection::arrayRef *)spec.info;

  setArrayRef(temp, type, ctx);

  return spec;
}
