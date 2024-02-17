#ifndef REFLECTION_H
#define REFLECTION_H

#include <stdint.h>

typedef void *(*ref_Alloc)(uint64_t);
typedef void (*ref_Free)(void *);

#define REF_COMPLEX_MASK 1 << 31
#define REF_MAKE_COMPLEX(fieldType) (fieldType | REF_COMPLEX_MASK)

enum ref_types {
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

enum ref_recordTypes {
  RECORD_TYPE_STRUCT,
  RECORD_TYPE_UNION,
};

struct ref_typeSpecifier {
  enum ref_types type;

  union {
    struct ref_recordRef *recordInfo;
    struct ref_enumRef *enumInfo;
    struct ref_arrayRef *arrayInfo;
    struct ref_ptrRef *ptrInfo;
    struct ref_bitFieldRef *bitFieldInfo;
  };
};

struct ref_recordRef {
  int64_t ID;
  char *fileName;
};

struct ref_enumRef {
  int64_t ID;
  char *fileName;
};

struct ref_arrayRef {
  struct ref_typeSpecifier type;
  int64_t size; // -1 if size is not known
};

struct ref_ptrRef {
  struct ref_typeSpecifier type;

  // eg. int **a will have a level of 2, int ***a will have a level of 3
  uint32_t level;
};

struct ref_bitFieldRef {
  uint32_t bitWidth;
};

struct ref_field {
  char *name;
  struct ref_typeSpecifier type;
  uint64_t offset; // In bits
};

struct ref_enumConstant {
  char *name;
  int32_t value;
};

struct ref_typeInfo {
  int64_t ID;
  char *filename;

  char *name;
  char **aliases;

  enum ref_recordTypes recordType;

  struct ref_field *fields;
};

struct ref_enumInfo {
  int64_t ID;
  char *fileName;

  char *name;
  char **aliases;

  struct ref_enumConstant *constants;
};

struct ref_programInfo {
  struct ref_typeInfo *types;
  uint64_t numTypes;

  struct ref_enumInfo *enums;
  uint64_t numEnums;
};

struct ref_programInfo *ref_load(ref_Alloc allocator);
void ref_unload(struct ref_programInfo *info, ref_Free deallocator);

#endif // REFLECTION_H
