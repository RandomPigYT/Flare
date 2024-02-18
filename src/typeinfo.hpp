#ifndef REFLECTION_TYPEINFO_H
#define REFLECTION_TYPEINFO_H

#include <clang/AST/Type.h>
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
  FIELD_TYPE_VA_ARG,

  // Primitive
  // Defined by clang
  FIELD_TYPE_I8 = clang::BuiltinType::Kind::SChar,
  FIELD_TYPE_I16 = clang::BuiltinType::Kind::Short,
  FIELD_TYPE_I32 = clang::BuiltinType::Kind::Int,
  FIELD_TYPE_I64 = clang::BuiltinType::Kind::Long,
  FIELD_TYPE_LONGLONG = clang::BuiltinType::Kind::LongLong,
  FIELD_TYPE_UI8 = clang::BuiltinType::UChar,
  FIELD_TYPE_UI16 = clang::BuiltinType::UShort,
  FIELD_TYPE_UI32 = clang::BuiltinType::UInt,
  FIELD_TYPE_UI64 = clang::BuiltinType::ULong,
  FIELD_TYPE_ULONGLONG = clang::BuiltinType::ULongLong,
  FIELD_TYPE_FLOAT = clang::BuiltinType::Float,
  FIELD_TYPE_DOUBLE = clang::BuiltinType::Double,
  FIELD_TYPE_LONG_DOUBLE = clang::BuiltinType::LongDouble,
  FIELD_TYPE_VOID = clang::BuiltinType::Void,
  FIELD_TYPE_PRIMITIVE, // A catch-all for all primitive types

  // Complex types
  FIELD_TYPE_GNU_EXT_COMPLEX_I8 = REF_MAKE_COMPLEX(FIELD_TYPE_I8),
  FIELD_TYPE_GNU_EXT_COMPLEX_I16 = REF_MAKE_COMPLEX(FIELD_TYPE_I16),
  FIELD_TYPE_GNU_EXT_COMPLEX_I32 = REF_MAKE_COMPLEX(FIELD_TYPE_I32),
  FIELD_TYPE_GNU_EXT_COMPLEX_I64 = REF_MAKE_COMPLEX(FIELD_TYPE_I64),
  FIELD_TYPE_COMPLEX_LONGLONG = REF_MAKE_COMPLEX(FIELD_TYPE_LONGLONG),
  FIELD_TYPE_GNU_EXT_COMPLEX_UI8 = REF_MAKE_COMPLEX(FIELD_TYPE_UI8),
  FIELD_TYPE_GNU_EXT_COMPLEX_UI16 = REF_MAKE_COMPLEX(FIELD_TYPE_UI16),
  FIELD_TYPE_GNU_EXT_COMPLEX_UI32 = REF_MAKE_COMPLEX(FIELD_TYPE_UI32),
  FIELD_TYPE_GNU_EXT_COMPLEX_UI64 = REF_MAKE_COMPLEX(FIELD_TYPE_UI64),
  FIELD_TYPE_COMPLEX_ULONGLONG = REF_MAKE_COMPLEX(FIELD_TYPE_ULONGLONG),
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

  // Only points to a valid block of memeory if type is not primitive or if type is a function type
  // Points to a functionRef_t, ptrRef_t, or structRef_t
  void *info;
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
