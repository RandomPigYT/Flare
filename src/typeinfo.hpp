#ifndef REFLECTION_TYPEINFO_H
#define REFLECTION_TYPEINFO_H

#include <cstdint>
#include <string>
#include <vector>

namespace Reflection {
#define REF_COMPLEX_MASK 1 << 31

#define REF_MAKE_COMPLEX(fieldType) (fieldType | REF_COMPLEX_MASK)

enum types {
  NONE = 0,

  // Not primitive
  FIELD_TYPE_PTR,
  FIELD_TYPE_ARRAY,
  FIELD_TYPE_CONSTANT_ARRAY,
  FIELD_TYPE_STRUCT,
  FIELD_TYPE_UNION,
  FIELD_TYPE_RECORD, // Can refer to struct or union
  FIELD_TYPE_FUNCTION,
  FIELD_TYPE_ENUM,

  // Misc
  FIELD_TYPE_BITFIELD,

  // Primitive
  // Defined by clang
  FIELD_TYPE_I8 = 179,
  FIELD_TYPE_I16 = 181,
  FIELD_TYPE_I32 = 182,
  FIELD_TYPE_I64 = 183,
  FIELD_TYPE_UI8 = 168,
  FIELD_TYPE_UI16 = 173,
  FIELD_TYPE_UI32 = 174,
  FIELD_TYPE_UI64 = 175,
  FIELD_TYPE_FLOAT = 211,
  FIELD_TYPE_DOUBLE = 212,
  FIELD_TYPE_LONG_DOUBLE = 213,
  FIELD_TYPE_VOID = 165,
  FIELD_TYPE_PRIMITIVE, // A catch-all for all primitive types

  // Complex types
  FIELD_TYPE_GNU_EXT_COMPLEX_I8 = REF_MAKE_COMPLEX(FIELD_TYPE_I8),
  FIELD_TYPE_GNU_EXT_COMPLEX_I16 = REF_MAKE_COMPLEX(FIELD_TYPE_I16),
  FIELD_TYPE_GNU_EXT_COMPLEX_I32 = REF_MAKE_COMPLEX(FIELD_TYPE_I32),
  FIELD_TYPE_GNU_EXT_COMPLEX_I64 = REF_MAKE_COMPLEX(FIELD_TYPE_I64),
  FIELD_TYPE_GNU_EXT_COMPLEX_UI8 = REF_MAKE_COMPLEX(FIELD_TYPE_UI8),
  FIELD_TYPE_GNU_EXT_COMPLEX_UI16 = REF_MAKE_COMPLEX(FIELD_TYPE_UI16),
  FIELD_TYPE_GNU_EXT_COMPLEX_UI32 = REF_MAKE_COMPLEX(FIELD_TYPE_UI32),
  FIELD_TYPE_GNU_EXT_COMPLEX_UI64 = REF_MAKE_COMPLEX(FIELD_TYPE_UI64),
  FIELD_TYPE_COMPLEX_FLOAT = REF_MAKE_COMPLEX(FIELD_TYPE_FLOAT),
  FIELD_TYPE_COMPLEX_DOUBLE = REF_MAKE_COMPLEX(FIELD_TYPE_DOUBLE),
  FIELD_TYPE_COMPLEX_LONG_DOUBLE = REF_MAKE_COMPLEX(FIELD_TYPE_LONG_DOUBLE),

};

enum recordTypes {
  RECORD_TYPE_STRUCT,
  RECORD_TYPE_UNION,
};

struct typeSpecifier {
  enum types type;

  // Only points to a valid block of memeory if type is not primitive
  // Points to a functionRef_t, ptrRef_t, or structRef_t
  void *info;
};

struct functionRef {
  std::vector<struct typeSpecifier> parameters;
  struct typeSpecifier returnType;
};

struct recordRef {
  int64_t ID;
  char *fileName;
};

struct enumRef {
  int64_t ID;
  char *fileName;
};

struct arrayRef {
  struct typeSpecifier type;
  int64_t size; // -1 if size is not known
};

struct ptrRef {
  struct typeSpecifier type;

  // eg. int **a will have a level of 2, int ***a will have a level of 3
  uint32_t level;
};

struct bitFieldRef {
  uint32_t bitWidth;
};

struct field {
  std::string name;
  struct typeSpecifier type;
  uint64_t offset; // In bits
};

struct enumConstant {
  std::string name;
  int32_t value;
};

struct typeInfo {
  int64_t ID;
  std::string fileName;

  // Can be empty
  std::string name;
  std::vector<std::string> aliases;

  enum recordTypes recordType;

  std::vector<struct field> fields;
};

struct enumInfo {
  int64_t ID;
  std::string fileName;

  std::string name;
  std::vector<std::string> aliases;

  std::vector<struct enumConstant> constants;
};

} // namespace Reflection

#endif // REFLECTION_TYPEINFO_H
