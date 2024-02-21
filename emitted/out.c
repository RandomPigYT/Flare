#include "../include/flare.h"

struct flr_programInfo info = {
	.numTypes = 17,
	.numEnums = 2,

	.types = (struct flr_typeInfo[]) {
		{
			.ID = 1077,
			.filename = "/home/randompigyt/Reflection/emitted/out.c",
			.name = "",
			.numAliases = 1,
			.aliases = (char (*[])) {
				"__fsid_t",
			},
			.recordType = RECORD_TYPE_STRUCT,
			.numFields = 1,
			.fields = (struct flr_field[]) {
				{
					.name = "__val",
					.offset = 0,
					.type = {
						.type = FIELD_TYPE_ARRAY,
						.arrayInfo = &(struct flr_arrayRef) {
							.size = 2,
							.type = {
								.type = FIELD_TYPE_I32,
							},
						},
					},
				},
			},
		},

		{
			.ID = 3082,
			.filename = "/home/randompigyt/Reflection/emitted/out.c",
			.name = "struct flr_typeSpecifier",
			.numAliases = 0,
			.aliases = (char (*[])) {

				// No aliases

			},
			.recordType = RECORD_TYPE_STRUCT,
			.numFields = 6,
			.fields = (struct flr_field[]) {
				{
					.name = "type",
					.offset = 0,
					.type = {
						.type = FIELD_TYPE_ENUM,
						.enumInfo = &(struct flr_enumRef) {
							.ID = 2201,
							.filename = "/home/randompigyt/Reflection/emitted/out.c",
						},
					},
				},

				{
					.name = "recordInfo",
					.offset = 64,
					.type = {
						.type = FIELD_TYPE_PTR,
						.ptrInfo = &(struct flr_ptrRef) {
							.level = 1,
							.type = {
								.type = FIELD_TYPE_STRUCT,
								.recordInfo = &(struct flr_recordRef) {
									.ID = 3498,
									.filename = "/home/randompigyt/Reflection/emitted/out.c",
								},
							},
						},
					},
				},

				{
					.name = "enumInfo",
					.offset = 64,
					.type = {
						.type = FIELD_TYPE_PTR,
						.ptrInfo = &(struct flr_ptrRef) {
							.level = 1,
							.type = {
								.type = FIELD_TYPE_STRUCT,
								.recordInfo = &(struct flr_recordRef) {
									.ID = 3551,
									.filename = "/home/randompigyt/Reflection/emitted/out.c",
								},
							},
						},
					},
				},

				{
					.name = "arrayInfo",
					.offset = 64,
					.type = {
						.type = FIELD_TYPE_PTR,
						.ptrInfo = &(struct flr_ptrRef) {
							.level = 1,
							.type = {
								.type = FIELD_TYPE_STRUCT,
								.recordInfo = &(struct flr_recordRef) {
									.ID = 3594,
									.filename = "/home/randompigyt/Reflection/emitted/out.c",
								},
							},
						},
					},
				},

				{
					.name = "ptrInfo",
					.offset = 64,
					.type = {
						.type = FIELD_TYPE_PTR,
						.ptrInfo = &(struct flr_ptrRef) {
							.level = 1,
							.type = {
								.type = FIELD_TYPE_STRUCT,
								.recordInfo = &(struct flr_recordRef) {
									.ID = 3669,
									.filename = "/home/randompigyt/Reflection/emitted/out.c",
								},
							},
						},
					},
				},

				{
					.name = "bitFieldInfo",
					.offset = 64,
					.type = {
						.type = FIELD_TYPE_PTR,
						.ptrInfo = &(struct flr_ptrRef) {
							.level = 1,
							.type = {
								.type = FIELD_TYPE_STRUCT,
								.recordInfo = &(struct flr_recordRef) {
									.ID = 3724,
									.filename = "/home/randompigyt/Reflection/emitted/out.c",
								},
							},
						},
					},
				},
			},
		},

		{
			.ID = 3142,
			.filename = "/home/randompigyt/Reflection/emitted/out.c",
			.name = "struct flr_recordRef",
			.numAliases = 0,
			.aliases = (char (*[])) {

				// No aliases

			},
			.recordType = RECORD_TYPE_STRUCT,
			.numFields = 0,
			.fields = (struct flr_field[]) {

				// No fields

			},
		},

		{
			.ID = 3198,
			.filename = "/home/randompigyt/Reflection/emitted/out.c",
			.name = "struct flr_enumRef",
			.numAliases = 0,
			.aliases = (char (*[])) {

				// No aliases

			},
			.recordType = RECORD_TYPE_STRUCT,
			.numFields = 0,
			.fields = (struct flr_field[]) {

				// No fields

			},
		},

		{
			.ID = 3254,
			.filename = "/home/randompigyt/Reflection/emitted/out.c",
			.name = "struct flr_arrayRef",
			.numAliases = 0,
			.aliases = (char (*[])) {

				// No aliases

			},
			.recordType = RECORD_TYPE_STRUCT,
			.numFields = 0,
			.fields = (struct flr_field[]) {

				// No fields

			},
		},

		{
			.ID = 3310,
			.filename = "/home/randompigyt/Reflection/emitted/out.c",
			.name = "struct flr_ptrRef",
			.numAliases = 0,
			.aliases = (char (*[])) {

				// No aliases

			},
			.recordType = RECORD_TYPE_STRUCT,
			.numFields = 0,
			.fields = (struct flr_field[]) {

				// No fields

			},
		},

		{
			.ID = 3366,
			.filename = "/home/randompigyt/Reflection/emitted/out.c",
			.name = "struct flr_bitFieldRef",
			.numAliases = 0,
			.aliases = (char (*[])) {

				// No aliases

			},
			.recordType = RECORD_TYPE_STRUCT,
			.numFields = 0,
			.fields = (struct flr_field[]) {

				// No fields

			},
		},

		{
			.ID = 3498,
			.filename = "/home/randompigyt/Reflection/emitted/out.c",
			.name = "struct flr_recordRef",
			.numAliases = 0,
			.aliases = (char (*[])) {

				// No aliases

			},
			.recordType = RECORD_TYPE_STRUCT,
			.numFields = 2,
			.fields = (struct flr_field[]) {
				{
					.name = "ID",
					.offset = 0,
					.type = {
						.type = FIELD_TYPE_I64,
					},
				},

				{
					.name = "filename",
					.offset = 64,
					.type = {
						.type = FIELD_TYPE_PTR,
						.ptrInfo = &(struct flr_ptrRef) {
							.level = 1,
							.type = {
								.type = FIELD_TYPE_CHAR,
							},
						},
					},
				},
			},
		},

		{
			.ID = 3551,
			.filename = "/home/randompigyt/Reflection/emitted/out.c",
			.name = "struct flr_enumRef",
			.numAliases = 0,
			.aliases = (char (*[])) {

				// No aliases

			},
			.recordType = RECORD_TYPE_STRUCT,
			.numFields = 2,
			.fields = (struct flr_field[]) {
				{
					.name = "ID",
					.offset = 0,
					.type = {
						.type = FIELD_TYPE_I64,
					},
				},

				{
					.name = "filename",
					.offset = 64,
					.type = {
						.type = FIELD_TYPE_PTR,
						.ptrInfo = &(struct flr_ptrRef) {
							.level = 1,
							.type = {
								.type = FIELD_TYPE_CHAR,
							},
						},
					},
				},
			},
		},

		{
			.ID = 3594,
			.filename = "/home/randompigyt/Reflection/emitted/out.c",
			.name = "struct flr_arrayRef",
			.numAliases = 0,
			.aliases = (char (*[])) {

				// No aliases

			},
			.recordType = RECORD_TYPE_STRUCT,
			.numFields = 2,
			.fields = (struct flr_field[]) {
				{
					.name = "type",
					.offset = 0,
					.type = {
						.type = FIELD_TYPE_STRUCT,
						.recordInfo = &(struct flr_recordRef) {
							.ID = 3082,
							.filename = "/home/randompigyt/Reflection/emitted/out.c",
						},
					},
				},

				{
					.name = "size",
					.offset = 128,
					.type = {
						.type = FIELD_TYPE_I64,
					},
				},
			},
		},

		{
			.ID = 3669,
			.filename = "/home/randompigyt/Reflection/emitted/out.c",
			.name = "struct flr_ptrRef",
			.numAliases = 0,
			.aliases = (char (*[])) {

				// No aliases

			},
			.recordType = RECORD_TYPE_STRUCT,
			.numFields = 2,
			.fields = (struct flr_field[]) {
				{
					.name = "type",
					.offset = 0,
					.type = {
						.type = FIELD_TYPE_STRUCT,
						.recordInfo = &(struct flr_recordRef) {
							.ID = 3082,
							.filename = "/home/randompigyt/Reflection/emitted/out.c",
						},
					},
				},

				{
					.name = "level",
					.offset = 128,
					.type = {
						.type = FIELD_TYPE_UI32,
					},
				},
			},
		},

		{
			.ID = 3724,
			.filename = "/home/randompigyt/Reflection/emitted/out.c",
			.name = "struct flr_bitFieldRef",
			.numAliases = 0,
			.aliases = (char (*[])) {

				// No aliases

			},
			.recordType = RECORD_TYPE_STRUCT,
			.numFields = 1,
			.fields = (struct flr_field[]) {
				{
					.name = "bitWidth",
					.offset = 0,
					.type = {
						.type = FIELD_TYPE_UI32,
					},
				},
			},
		},

		{
			.ID = 3752,
			.filename = "/home/randompigyt/Reflection/emitted/out.c",
			.name = "struct flr_field",
			.numAliases = 0,
			.aliases = (char (*[])) {

				// No aliases

			},
			.recordType = RECORD_TYPE_STRUCT,
			.numFields = 3,
			.fields = (struct flr_field[]) {
				{
					.name = "name",
					.offset = 0,
					.type = {
						.type = FIELD_TYPE_PTR,
						.ptrInfo = &(struct flr_ptrRef) {
							.level = 1,
							.type = {
								.type = FIELD_TYPE_CHAR,
							},
						},
					},
				},

				{
					.name = "type",
					.offset = 64,
					.type = {
						.type = FIELD_TYPE_STRUCT,
						.recordInfo = &(struct flr_recordRef) {
							.ID = 3082,
							.filename = "/home/randompigyt/Reflection/emitted/out.c",
						},
					},
				},

				{
					.name = "offset",
					.offset = 192,
					.type = {
						.type = FIELD_TYPE_UI64,
					},
				},
			},
		},

		{
			.ID = 3811,
			.filename = "/home/randompigyt/Reflection/emitted/out.c",
			.name = "struct flr_enumConstant",
			.numAliases = 0,
			.aliases = (char (*[])) {

				// No aliases

			},
			.recordType = RECORD_TYPE_STRUCT,
			.numFields = 2,
			.fields = (struct flr_field[]) {
				{
					.name = "name",
					.offset = 0,
					.type = {
						.type = FIELD_TYPE_PTR,
						.ptrInfo = &(struct flr_ptrRef) {
							.level = 1,
							.type = {
								.type = FIELD_TYPE_CHAR,
							},
						},
					},
				},

				{
					.name = "value",
					.offset = 64,
					.type = {
						.type = FIELD_TYPE_I32,
					},
				},
			},
		},

		{
			.ID = 3870,
			.filename = "/home/randompigyt/Reflection/emitted/out.c",
			.name = "struct flr_typeInfo",
			.numAliases = 0,
			.aliases = (char (*[])) {

				// No aliases

			},
			.recordType = RECORD_TYPE_STRUCT,
			.numFields = 8,
			.fields = (struct flr_field[]) {
				{
					.name = "ID",
					.offset = 0,
					.type = {
						.type = FIELD_TYPE_I64,
					},
				},

				{
					.name = "filename",
					.offset = 64,
					.type = {
						.type = FIELD_TYPE_PTR,
						.ptrInfo = &(struct flr_ptrRef) {
							.level = 1,
							.type = {
								.type = FIELD_TYPE_CHAR,
							},
						},
					},
				},

				{
					.name = "name",
					.offset = 128,
					.type = {
						.type = FIELD_TYPE_PTR,
						.ptrInfo = &(struct flr_ptrRef) {
							.level = 1,
							.type = {
								.type = FIELD_TYPE_CHAR,
							},
						},
					},
				},

				{
					.name = "aliases",
					.offset = 192,
					.type = {
						.type = FIELD_TYPE_PTR,
						.ptrInfo = &(struct flr_ptrRef) {
							.level = 2,
							.type = {
								.type = FIELD_TYPE_CHAR,
							},
						},
					},
				},

				{
					.name = "numAliases",
					.offset = 256,
					.type = {
						.type = FIELD_TYPE_UI64,
					},
				},

				{
					.name = "recordType",
					.offset = 320,
					.type = {
						.type = FIELD_TYPE_ENUM,
						.enumInfo = &(struct flr_enumRef) {
							.ID = 3038,
							.filename = "/home/randompigyt/Reflection/emitted/out.c",
						},
					},
				},

				{
					.name = "fields",
					.offset = 384,
					.type = {
						.type = FIELD_TYPE_PTR,
						.ptrInfo = &(struct flr_ptrRef) {
							.level = 1,
							.type = {
								.type = FIELD_TYPE_STRUCT,
								.recordInfo = &(struct flr_recordRef) {
									.ID = 3752,
									.filename = "/home/randompigyt/Reflection/emitted/out.c",
								},
							},
						},
					},
				},

				{
					.name = "numFields",
					.offset = 448,
					.type = {
						.type = FIELD_TYPE_UI64,
					},
				},
			},
		},

		{
			.ID = 4022,
			.filename = "/home/randompigyt/Reflection/emitted/out.c",
			.name = "struct flr_enumInfo",
			.numAliases = 0,
			.aliases = (char (*[])) {

				// No aliases

			},
			.recordType = RECORD_TYPE_STRUCT,
			.numFields = 7,
			.fields = (struct flr_field[]) {
				{
					.name = "ID",
					.offset = 0,
					.type = {
						.type = FIELD_TYPE_I64,
					},
				},

				{
					.name = "filename",
					.offset = 64,
					.type = {
						.type = FIELD_TYPE_PTR,
						.ptrInfo = &(struct flr_ptrRef) {
							.level = 1,
							.type = {
								.type = FIELD_TYPE_CHAR,
							},
						},
					},
				},

				{
					.name = "name",
					.offset = 128,
					.type = {
						.type = FIELD_TYPE_PTR,
						.ptrInfo = &(struct flr_ptrRef) {
							.level = 1,
							.type = {
								.type = FIELD_TYPE_CHAR,
							},
						},
					},
				},

				{
					.name = "aliases",
					.offset = 192,
					.type = {
						.type = FIELD_TYPE_PTR,
						.ptrInfo = &(struct flr_ptrRef) {
							.level = 2,
							.type = {
								.type = FIELD_TYPE_CHAR,
							},
						},
					},
				},

				{
					.name = "numAliases",
					.offset = 256,
					.type = {
						.type = FIELD_TYPE_UI64,
					},
				},

				{
					.name = "constants",
					.offset = 320,
					.type = {
						.type = FIELD_TYPE_PTR,
						.ptrInfo = &(struct flr_ptrRef) {
							.level = 1,
							.type = {
								.type = FIELD_TYPE_STRUCT,
								.recordInfo = &(struct flr_recordRef) {
									.ID = 3811,
									.filename = "/home/randompigyt/Reflection/emitted/out.c",
								},
							},
						},
					},
				},

				{
					.name = "numConstants",
					.offset = 384,
					.type = {
						.type = FIELD_TYPE_UI64,
					},
				},
			},
		},

		{
			.ID = 4150,
			.filename = "/home/randompigyt/Reflection/emitted/out.c",
			.name = "struct flr_programInfo",
			.numAliases = 0,
			.aliases = (char (*[])) {

				// No aliases

			},
			.recordType = RECORD_TYPE_STRUCT,
			.numFields = 4,
			.fields = (struct flr_field[]) {
				{
					.name = "types",
					.offset = 0,
					.type = {
						.type = FIELD_TYPE_PTR,
						.ptrInfo = &(struct flr_ptrRef) {
							.level = 1,
							.type = {
								.type = FIELD_TYPE_STRUCT,
								.recordInfo = &(struct flr_recordRef) {
									.ID = 3870,
									.filename = "/home/randompigyt/Reflection/emitted/out.c",
								},
							},
						},
					},
				},

				{
					.name = "numTypes",
					.offset = 64,
					.type = {
						.type = FIELD_TYPE_UI64,
					},
				},

				{
					.name = "enums",
					.offset = 128,
					.type = {
						.type = FIELD_TYPE_PTR,
						.ptrInfo = &(struct flr_ptrRef) {
							.level = 1,
							.type = {
								.type = FIELD_TYPE_STRUCT,
								.recordInfo = &(struct flr_recordRef) {
									.ID = 4022,
									.filename = "/home/randompigyt/Reflection/emitted/out.c",
								},
							},
						},
					},
				},

				{
					.name = "numEnums",
					.offset = 192,
					.type = {
						.type = FIELD_TYPE_UI64,
					},
				},
			},
		},
	},

	.enums = (struct flr_enumInfo[]) {
		{
			.ID = 2201,
			.filename = "/home/randompigyt/Reflection/emitted/out.c",
			.name = "enum flr_types",
			.numAliases = 0,
			.aliases = (char (*[])) {

				// No aliases

			},
			.numConstants = 41,
			.constants = (struct flr_enumConstant[]) {
				{
					.name = "FIELD_TYPE_NONE",
					.value = 0,
				},

				{
					.name = "FIELD_TYPE_PTR",
					.value = 1,
				},

				{
					.name = "FIELD_TYPE_ARRAY",
					.value = 2,
				},

				{
					.name = "FIELD_TYPE_CONSTANT_ARRAY",
					.value = 3,
				},

				{
					.name = "FIELD_TYPE_STRUCT",
					.value = 4,
				},

				{
					.name = "FIELD_TYPE_UNION",
					.value = 5,
				},

				{
					.name = "FIELD_TYPE_RECORD",
					.value = 6,
				},

				{
					.name = "FIELD_TYPE_FUNCTION",
					.value = 7,
				},

				{
					.name = "FIELD_TYPE_ENUM",
					.value = 8,
				},

				{
					.name = "FIELD_TYPE_BITFIELD",
					.value = 9,
				},

				{
					.name = "FIELD_TYPE_VA_ARG",
					.value = 10,
				},

				{
					.name = "FIELD_TYPE_PRIMITIVE",
					.value = 11,
				},

				{
					.name = "FIELD_TYPE_CHAR",
					.value = 12,
				},

				{
					.name = "FIELD_TYPE_I8",
					.value = 13,
				},

				{
					.name = "FIELD_TYPE_I16",
					.value = 14,
				},

				{
					.name = "FIELD_TYPE_I32",
					.value = 15,
				},

				{
					.name = "FIELD_TYPE_I64",
					.value = 16,
				},

				{
					.name = "FIELD_TYPE_LONGLONG",
					.value = 17,
				},

				{
					.name = "FIELD_TYPE_UI8",
					.value = 18,
				},

				{
					.name = "FIELD_TYPE_UI16",
					.value = 19,
				},

				{
					.name = "FIELD_TYPE_UI32",
					.value = 20,
				},

				{
					.name = "FIELD_TYPE_UI64",
					.value = 21,
				},

				{
					.name = "FIELD_TYPE_ULONGLONG",
					.value = 22,
				},

				{
					.name = "FIELD_TYPE_FLOAT",
					.value = 23,
				},

				{
					.name = "FIELD_TYPE_DOUBLE",
					.value = 24,
				},

				{
					.name = "FIELD_TYPE_LONG_DOUBLE",
					.value = 25,
				},

				{
					.name = "FIELD_TYPE_VOID",
					.value = 26,
				},

				{
					.name = "FIELD_TYPE_GNU_EXT_COMPLEX_CHAR",
					.value = -2147483636,
				},

				{
					.name = "FIELD_TYPE_GNU_EXT_COMPLEX_I8",
					.value = -2147483635,
				},

				{
					.name = "FIELD_TYPE_GNU_EXT_COMPLEX_I16",
					.value = -2147483634,
				},

				{
					.name = "FIELD_TYPE_GNU_EXT_COMPLEX_I32",
					.value = -2147483633,
				},

				{
					.name = "FIELD_TYPE_GNU_EXT_COMPLEX_I64",
					.value = -2147483632,
				},

				{
					.name = "FIELD_TYPE_GNU_EXT_COMPLEX_LONGLONG",
					.value = -2147483631,
				},

				{
					.name = "FIELD_TYPE_GNU_EXT_COMPLEX_UI8",
					.value = -2147483630,
				},

				{
					.name = "FIELD_TYPE_GNU_EXT_COMPLEX_UI16",
					.value = -2147483629,
				},

				{
					.name = "FIELD_TYPE_GNU_EXT_COMPLEX_UI32",
					.value = -2147483628,
				},

				{
					.name = "FIELD_TYPE_GNU_EXT_COMPLEX_UI64",
					.value = -2147483627,
				},

				{
					.name = "FIELD_TYPE_GNU_EXT_COMPLEX_ULONGLONG",
					.value = -2147483626,
				},

				{
					.name = "FIELD_TYPE_COMPLEX_FLOAT",
					.value = -2147483625,
				},

				{
					.name = "FIELD_TYPE_COMPLEX_DOUBLE",
					.value = -2147483624,
				},

				{
					.name = "FIELD_TYPE_COMPLEX_LONG_DOUBLE",
					.value = -2147483623,
				},
			},
		},

		{
			.ID = 3038,
			.filename = "/home/randompigyt/Reflection/emitted/out.c",
			.name = "enum flr_recordTypes",
			.numAliases = 0,
			.aliases = (char (*[])) {

				// No aliases

			},
			.numConstants = 2,
			.constants = (struct flr_enumConstant[]) {
				{
					.name = "RECORD_TYPE_STRUCT",
					.value = 0,
				},

				{
					.name = "RECORD_TYPE_UNION",
					.value = 1,
				},
			},
		},
	},
};

struct flr_programInfo flr_load() {
	return info;
}
