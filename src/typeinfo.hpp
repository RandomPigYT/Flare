#ifndef REFLECTION_TYPEINFO_H
#define REFLECTION_TYPEINFO_H

#include <cstdint>
#include <string>
#include <vector>

namespace Reflection {

enum fieldTypes_e {
	NONE = 0,

	// Primitive
  FIELD_TYPE_I8,
  FIELD_TYPE_I16,
  FIELD_TYPE_I32,
  FIELD_TYPE_I64,
  FIELD_TYPE_UI8,
  FIELD_TYPE_UI16,
  FIELD_TYPE_UI32,
  FIELD_TYPE_UI64,
  FIELD_TYPE_FLOAT,
  FIELD_TYPE_DOUBLE,
  FIELD_TYPE_LONG_DOUBLE,
  FIELD_TYPE_PTR,
	
	// Not primitive
  FIELD_TYPE_STRUCT,
  FIELD_TYPE_FUNCTION,
  FIELD_TYPE_ENUM
};

struct parameter_t {
	enum fieldTypes_e type;

  // Only points to a valid block of memeory if type is not primitive
	void *info;
};

struct functionRef_t {
	


};

struct ptrRef_t {
  enum fieldTypes_e type;

  // eg. int **a will have a level of 2, int ***a will have a level of 3
  uint32_t level;

  // Only points to a valid block of memeory if type is not primitive
  void *info;
};

struct structRef_t {
  uint64_t ID;
  std::string fileName;
};

struct field_t {
  enum fieldTypes_e type;

  // Addtional info in case the type is FIELD_TYPE_STRUCT, FIELD_TYPE_PTR or
  // FIELD_TYPE_FUNCTION
  void *info;

  uint64_t offset;
};

struct typeInfo_t {
  uint64_t ID;
  std::string fileName;
	
	// Can be empty
  std::string name;  

  // If empty after all files are processed, the type is invalid
  std::vector<std::string> aliases;

  std::vector<struct field_t> fields;
};

}  // namespace Reflection

#endif  // REFLECTION_TYPEINFO_H
