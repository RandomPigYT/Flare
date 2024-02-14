#ifndef REFLECTION_CONSTRUCT_SPEC_H
#define REFLECTION_CONSTRUCT_SPEC_H

#include <clang/AST/Decl.h>
#include <clang/AST/Type.h>

#include "ast.hpp"
#include "typeinfo.hpp"

namespace Reflection {

struct Reflection::typeSpecifier constructRecordSpec(clang::RecordDecl *rd,
                                                     const char *filename);

struct Reflection::typeSpecifier constructEnumSpec(clang::EnumDecl *ed,
                                                   const char *filename);

struct Reflection::typeSpecifier
constructBitFieldSpec(clang::FieldDecl *fd, const clang::ASTContext *context);

struct Reflection::typeSpecifier
constructPtrSpec(const clang::PointerType *type,
                 const struct Reflection::context &ctx);

struct Reflection::typeSpecifier
constructArraySpec(const clang::ArrayType *type,
                   const struct Reflection::context &ctx);

struct Reflection::typeSpecifier constructFunctionSpec();

struct Reflection::typeSpecifier constructPrimitiveSpec(clang::QualType type);

} // namespace Reflection

#endif
