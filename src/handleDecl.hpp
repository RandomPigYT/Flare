#ifndef REFLECTION_HANDLE_DECL_H
#define REFLECTION_HANDLE_DECL_H

#include <clang/AST/Decl.h>

#include <vector>

#include "typeinfo.hpp"

namespace Reflection {

void handleRecordDecl(clang::RecordDecl *rd, char *file,
                      std::vector<typeInfo_t> &typeinfo);
void handleTypedefDecl(clang::TypedefDecl *td, char *file,
                       std::vector<typeInfo_t> &typeinfo);
void handleFieldDecl(clang::FieldDecl *fd, char *file,
                     std::vector<typeInfo_t> &typeinfo);

}  // namespace Reflection

#endif  // REFLECTION_HANDLE_DECL_H
