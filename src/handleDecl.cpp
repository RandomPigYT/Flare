#include "handleDecl.hpp"

#include <clang/AST/ASTContext.h>
#include <clang/AST/Decl.h>
#include <clang/AST/Expr.h>
#include <clang/AST/RecordLayout.h>
#include <clang/AST/Type.h>
#include <llvm/IR/DerivedTypes.h>

#include "context.hpp"
#include "constructSpec.hpp"

void Reflection::handleRecordDecl(clang::RecordDecl *rd, struct context &ctx) {
  if (!rd->isStruct() && !rd->isUnion())
    return;

  if (rd->isAnonymousStructOrUnion())
    return;

  struct Reflection::typeInfo t;

  t.ID = rd->getID();
  t.fileName.assign(ctx.filename);
  t.name = rd->getNameAsString();
  if (t.name.size()) {
    t.name = (rd->isStruct() ? "struct " : "union ") + t.name;
  }

  t.recordType = rd->isStruct() ? Reflection::RECORD_TYPE_STRUCT
                                : Reflection::RECORD_TYPE_UNION;

  ctx.typeinfo.push_back(t);
}

void Reflection::handleEnumDecl(clang::EnumDecl *ed, struct context &ctx) {
  struct Reflection::enumInfo e;

  e.ID = ed->getID();
  e.fileName.assign(ctx.filename);
  e.name = ed->getNameAsString();
  if (e.name.size()) {
    e.name = "enum " + e.name;
  }

  ctx.enumInfo.push_back(e);
}

static int64_t findEnum(int64_t ID, std::string filename,
                        const struct Reflection::context &ctx) {
  for (uint64_t i = 0; i < ctx.enumInfo.size(); i++) {
    if (ctx.enumInfo[i].ID == ID && ctx.enumInfo[i].fileName == filename)
      return i;
  }

  return -1;
}

void Reflection::handleEnumConstantDecl(clang::EnumConstantDecl *ecd,
                                        struct context &ctx) {
  clang::EnumDecl *parent =
    clang::dyn_cast<clang::EnumDecl>(ecd->getDeclContext());
  struct Reflection::enumConstant ec;

  ec.name = ecd->getNameAsString();
  ec.value = ecd->getInitVal().getExtValue();

  int64_t enumIndex = findEnum(parent->getID(), ctx.filename, ctx);
  if (enumIndex == -1) {
    fprintf(stderr, "Fatal: Failed to find enum: %ld\t%s\t%s\n",
            parent->getID(), parent->getNameAsString().c_str(), ctx.filename);
    exit(EXIT_FAILURE);
  }

  ctx.enumInfo[enumIndex].constants.push_back(ec);
}

void Reflection::handleTypedefDecl(clang::TypedefDecl *td,
                                   struct context &ctx) {
  clang::QualType q = td->getUnderlyingType();

EnumType:
  if (!q->isEnumeralType()) {
    goto RecordType;
  }

  for (uint64_t i = 0; i < ctx.enumInfo.size(); i++) {
    if (ctx.enumInfo[i].fileName != ctx.filename ||
        ctx.enumInfo[i].ID != q->getAsTagDecl()->getID()) {
      continue;
    }
    ctx.enumInfo[i].aliases.push_back(td->getNameAsString());
  }

  return;

RecordType:
  clang::RecordDecl *rd = q->getAsRecordDecl();
  if (!rd || !(rd->isStruct() || rd->isUnion()))
    return;

  for (uint64_t i = 0; i < ctx.typeinfo.size(); i++) {
    if (ctx.typeinfo[i].fileName != ctx.filename ||
        ctx.typeinfo[i].ID != rd->getID()) {
      continue;
    }

    ctx.typeinfo[i].aliases.push_back(td->getNameAsString());
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

  if (type->isBuiltinType() || type->isAnyComplexType() ||
      type->isVectorType()) {
    return Reflection::FIELD_TYPE_PRIMITIVE;
  }

  //return Reflection::FIELD_TYPE_PRIMITIVE;
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
  if (parent->isInvalidDecl()) {
    return;
  }
  if (fd->isInvalidDecl()) {
    return;
  }

  int64_t typeIndex = findRecord(parent->getID(), ctx.filename, ctx);
  if (typeIndex < 0) {
    fprintf(stderr, "Fatal: Failed to find type: %ld\t%s\t%s\n",
            parent->getID(), parent->getNameAsString().c_str(), ctx.filename);
    //exit(EXIT_FAILURE);
    return;
  }

  //printf("%s\n", fd->getNameAsString().c_str());

  const clang::ASTRecordLayout &layout =
    ctx.context->getASTRecordLayout(parent);

  struct Reflection::field f;
  f.name = fd->getNameAsString();
  f.offset =
    (offset == -1 ? layout.getFieldOffset(fd->getFieldIndex()) : offset);
  f.type.type = Reflection::NONE;

  clang::QualType fieldType = fd->getType().getCanonicalType();

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

  else if (typeEnum == Reflection::FIELD_TYPE_ENUM) {
    clang::EnumDecl *ed =
      clang::dyn_cast<clang::EnumDecl>(fieldType->getAsTagDecl());
    f.type = Reflection::constructEnumSpec(ed, ctx.filename);
  }

  else if (typeEnum == Reflection::FIELD_TYPE_PTR) {
    f.type = Reflection::constructPtrSpec(
      clang::dyn_cast<clang::PointerType>(fieldType.getTypePtr()), ctx);
  }

  else if (typeEnum == Reflection::FIELD_TYPE_PRIMITIVE) {
    f.type = Reflection::constructPrimitiveSpec(fieldType);
  }

  else if (typeEnum == Reflection::FIELD_TYPE_ARRAY) {
    f.type = Reflection::constructArraySpec(
      clang::dyn_cast<clang::ArrayType>(fieldType.getTypePtr()), ctx);
  }

  else if (typeEnum == Reflection::FIELD_TYPE_FUNCTION) {
    f.type = Reflection::constructFunctionSpec(
      clang::dyn_cast<clang::FunctionType>(fieldType.getTypePtr()), ctx);
  }

  ctx.typeinfo[typeIndex].fields.push_back(f);

  // clang::Decl *declForField =
  // clang::dyn_cast<clang::Decl>(fd->getUnderlyingDecl());
}
