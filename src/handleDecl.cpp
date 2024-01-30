#include "handleDecl.hpp"

void Reflection::handleRecordDecl(
    clang::RecordDecl *rd, char *file,
    std::vector<Reflection::typeInfo_t> &typeinfo) {

	if (!rd->isStruct() && !rd->isUnion())
		return;
	
	if (rd->isAnonymousStructOrUnion())
		return;

	Reflection::typeInfo_t t;

  t.ID = rd->getID();
  t.fileName.assign(file);
  t.name = rd->getNameAsString();
	t.recordType = rd->isStruct() ? RECORD_TYPE_STRUCT : RECORD_TYPE_UNION;

  typeinfo.emplace_back(t);
}

void Reflection::handleTypedefDecl(
    clang::TypedefDecl *td, char *file,
    std::vector<Reflection::typeInfo_t> &typeinfo) {
	
	clang::QualType q = td->getUnderlyingType();
	
	clang::RecordDecl *rd = q->getAsRecordDecl();
	if (!rd || (!rd->isStruct() && !rd->isUnion()))
		return;

	for (uint64_t i = 0; i < typeinfo.size(); i++){
		if (typeinfo[i].fileName != file || typeinfo[i].ID != rd->getID())
			continue;
		
		typeinfo[i].aliases.emplace_back(td->getNameAsString());
	}
}

void Reflection::handleFieldDecl(
    clang::FieldDecl *fd, char *file,
    std::vector<Reflection::typeInfo_t> &typeinfo) {




}
