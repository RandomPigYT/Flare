#ifndef REFLECTION_HANDLE_DECL_H
#define REFLECTION_HANDLE_DECL_H

#include <clang/AST/Decl.h>

#include <vector>

#include "ast.hpp"
#include "typeinfo.hpp"

namespace Reflection {

void handleRecordDecl(clang::RecordDecl *rd, struct context_t &ctx);
void handleTypedefDecl(clang::TypedefDecl *td, struct context_t &ctx);
void handleFieldDecl(clang::FieldDecl *fd, struct context_t &ctx);

}  // namespace Reflection

#endif  // REFLECTION_HANDLE_DECL_H
