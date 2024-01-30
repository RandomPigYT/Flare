#include "handleDecl.hpp"

void Reflection::handleRecordDecl(
    clang::RecordDecl *rd, char *file,
    std::vector<Reflection::typeInfo_t> &typeinfo) {
  Reflection::typeInfo_t t;

  t.ID = rd->getID();
  t.fileName.assign(file);
  t.name = rd->getNameAsString();

  typeinfo.emplace_back(t);
}

void Reflection::handleTypedefDecl(
    clang::TypedefDecl *td, char *file,
    std::vector<Reflection::typeInfo_t> &typeinfo) {}

void Reflection::handleFieldDecl(
    clang::FieldDecl *fd, char *file,
    std::vector<Reflection::typeInfo_t> &typeinfo) {}
