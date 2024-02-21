#ifndef FLARE_H
#define FLARE_H

#include <stdint.h>

typedef void *(*flr_Alloc)(uint64_t);
typedef void (*flr_Free)(void *);

#define FLR_COMPLEX_MASK 1 << 31
#define FLR_MAKE_COMPLEX(fieldType) (fieldType | FLR_COMPLEX_MASK)

enum flr_types {
  FIELD_TYPE_NONE = 0,

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

  FIELD_TYPE_PRIMITIVE, // A catch-all for all primitive types

  // Primitive
  // Defined by clang
  FIELD_TYPE_CHAR,
  FIELD_TYPE_I8,
  FIELD_TYPE_I16,
  FIELD_TYPE_I32,
  FIELD_TYPE_I64,
  FIELD_TYPE_LONGLONG,
  FIELD_TYPE_UI8,
  FIELD_TYPE_UI16,
  FIELD_TYPE_UI32,
  FIELD_TYPE_UI64,
  FIELD_TYPE_ULONGLONG,
  FIELD_TYPE_FLOAT,
  FIELD_TYPE_DOUBLE,
  FIELD_TYPE_LONG_DOUBLE,
  FIELD_TYPE_VOID,

  // Complex types
  FIELD_TYPE_GNU_EXT_COMPLEX_CHAR = FLR_MAKE_COMPLEX(FIELD_TYPE_CHAR),
  FIELD_TYPE_GNU_EXT_COMPLEX_I8 = FLR_MAKE_COMPLEX(FIELD_TYPE_I8),
  FIELD_TYPE_GNU_EXT_COMPLEX_I16 = FLR_MAKE_COMPLEX(FIELD_TYPE_I16),
  FIELD_TYPE_GNU_EXT_COMPLEX_I32 = FLR_MAKE_COMPLEX(FIELD_TYPE_I32),
  FIELD_TYPE_GNU_EXT_COMPLEX_I64 = FLR_MAKE_COMPLEX(FIELD_TYPE_I64),
  FIELD_TYPE_GNU_EXT_COMPLEX_LONGLONG = FLR_MAKE_COMPLEX(FIELD_TYPE_LONGLONG),
  FIELD_TYPE_GNU_EXT_COMPLEX_UI8 = FLR_MAKE_COMPLEX(FIELD_TYPE_UI8),
  FIELD_TYPE_GNU_EXT_COMPLEX_UI16 = FLR_MAKE_COMPLEX(FIELD_TYPE_UI16),
  FIELD_TYPE_GNU_EXT_COMPLEX_UI32 = FLR_MAKE_COMPLEX(FIELD_TYPE_UI32),
  FIELD_TYPE_GNU_EXT_COMPLEX_UI64 = FLR_MAKE_COMPLEX(FIELD_TYPE_UI64),
  FIELD_TYPE_GNU_EXT_COMPLEX_ULONGLONG = FLR_MAKE_COMPLEX(FIELD_TYPE_ULONGLONG),
  FIELD_TYPE_COMPLEX_FLOAT = FLR_MAKE_COMPLEX(FIELD_TYPE_FLOAT),
  FIELD_TYPE_COMPLEX_DOUBLE = FLR_MAKE_COMPLEX(FIELD_TYPE_DOUBLE),
  FIELD_TYPE_COMPLEX_LONG_DOUBLE = FLR_MAKE_COMPLEX(FIELD_TYPE_LONG_DOUBLE),

};

enum flr_recordTypes {
  RECORD_TYPE_STRUCT,
  RECORD_TYPE_UNION,
};

struct flr_typeSpecifier {
  enum flr_types type;

  union {
    struct flr_recordRef *recordInfo;
    struct flr_enumRef *enumInfo;
    struct flr_arrayRef *arrayInfo;
    struct flr_ptrRef *ptrInfo;
    struct flr_bitFieldRef *bitFieldInfo;
  };
};

struct flr_recordRef {
  int64_t ID;
  char *filename;
};

struct flr_enumRef {
  int64_t ID;
  char *filename;
};

struct flr_arrayRef {
  struct flr_typeSpecifier type;
  int64_t size; // -1 if size is not known
};

struct flr_ptrRef {
  struct flr_typeSpecifier type;

  // eg. int **a will have a level of 2, int ***a will have a level of 3
  uint32_t level;
};

struct flr_bitFieldRef {
  uint32_t bitWidth;
};

struct flr_field {
  char *name;
  struct flr_typeSpecifier type;
  uint64_t offset; // In bits
};

struct flr_enumConstant {
  char *name;
  int32_t value;
};

struct flr_typeInfo {
  int64_t ID;
  char *filename;

  char *name;
  char **aliases;
  uint64_t numAliases;

  enum flr_recordTypes recordType;

  struct flr_field *fields;
  uint64_t numFields;
};

struct flr_enumInfo {
  int64_t ID;
  char *filename;

  char *name;
  char **aliases;
  uint64_t numAliases;

  struct flr_enumConstant *constants;
  uint64_t numConstants;
};

struct flr_programInfo {
  struct flr_typeInfo *types;
  uint64_t numTypes;

  struct flr_enumInfo *enums;
  uint64_t numEnums;
};

struct flr_programInfo flr_load();

#endif // FLARE_H
