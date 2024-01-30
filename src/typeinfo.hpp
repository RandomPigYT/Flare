#ifndef REFLECTION_TYPEINFO_H
#define REFLECTION_TYPEINFO_H

#include <cstdint>
#include <string>
#include <vector>

namespace Reflection {

enum types_e {
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

struct typeSpecifier_t {
	types_e type;

  // Only points to a valid block of memeory if type is not primitive
	// Points to a functionRef_t, ptrRef_t, or structRef_t
	void *info;
};

struct functionRef_t {
	std::vector<typeSpecifier_t> parameters;
};

struct structRef_t {
  uint64_t ID;
  std::string fileName;
};

struct ptrRef_t {
	typeSpecifier_t type;

  // eg. int **a will have a level of 2, int ***a will have a level of 3
  uint32_t level;
};

struct field_t {
	typeSpecifier_t type;
  uint64_t offset;
};

struct typeInfo_t {
  uint64_t ID;
  std::string fileName;
	
	// Can be empty
  std::string name;  

  // If empty after all files are processed, the type is invalid
  std::vector<std::string> aliases;

  std::vector<field_t> fields;
};

}  // namespace Reflection

#endif  // REFLECTION_TYPEINFO_H
