#ifndef REFLECTION_HANDLE_DECL_H
#define REFLECTION_HANDLE_DECL_H

#include <clang/AST/Decl.h>

#include <vector>

#include "context.hpp"
#include "typeinfo.hpp"

namespace Reflection {

void handleRecordDecl(clang::RecordDecl *rd, struct context &ctx);
void handleEnumDecl(clang::EnumDecl *ed, struct context &ctx);
void handleEnumConstantDecl(clang::EnumConstantDecl *ecd, struct context &ctx);
void handleTypedefDecl(clang::TypedefDecl *td, struct context &ctx);
void handleFieldDecl(clang::FieldDecl *fd, struct context &ctx,
										 clang::RecordDecl *p = nullptr, int64_t offset = -1);

} // namespace Reflection

#endif // REFLECTION_HANDLE_DECL_H
