#include "../include/flare.h"

struct flr_programInfo info = {
	.numTypes = 10,
	.numEnums = 2,

	.types = (struct flr_typeInfo[]) {
		{
			.ID = 22120,
			.filename = "/home/randompigyt/Reflection/testFiles/anon.c",
			.name = "struct bruh",
			.numAliases = 1,
			.aliases = (char (*[])) {
				"bruh",
			},
			.recordType = RECORD_TYPE_STRUCT,
			.numFields = 11,
			.fields = (struct flr_field[]) {
				{
					.name = "c",
					.offset = 0,
					.type = {
						.type = FIELD_TYPE_I32,
					},
				},

				{
					.name = "b",
					.offset = 0,
					.type = {
						.type = FIELD_TYPE_I32,
					},
				},

				{
					.name = "h",
					.offset = 0,
					.type = {
						.type = FIELD_TYPE_I32,
					},
				},

				{
					.name = "f",
					.offset = 0,
					.type = {
						.type = FIELD_TYPE_I32,
					},
				},

				{
					.name = "g",
					.offset = 32,
					.type = {
						.type = FIELD_TYPE_STRUCT,
						.recordInfo = &(struct flr_recordRef) {
							.ID = 22332,
							.filename = "/home/randompigyt/Reflection/testFiles/anon.c",
						},
					},
				},

				{
					.name = "lmao",
					.offset = 128,
					.type = {
						.type = FIELD_TYPE_PTR,
						.ptrInfo = &(struct flr_ptrRef) {
							.level = 2,
							.type = {
								.type = FIELD_TYPE_STRUCT,
								.recordInfo = &(struct flr_recordRef) {
									.ID = 22399,
									.filename = "/home/randompigyt/Reflection/testFiles/anon.c",
								},
							},
						},
					},
				},

				{
					.name = "m",
					.offset = 192,
					.type = {
						.type = FIELD_TYPE_ARRAY,
						.arrayInfo = &(struct flr_arrayRef) {
							.size = 69,
							.type = {
								.type = FIELD_TYPE_I32,
							},
						},
					},
				},

				{
					.name = "a",
					.offset = 2400,
					.type = {
						.type = FIELD_TYPE_I32,
					},
				},

				{
					.name = "sup",
					.offset = 2432,
					.type = {
						.type = FIELD_TYPE_PTR,
						.ptrInfo = &(struct flr_ptrRef) {
							.level = 1,
							.type = {
								.type = FIELD_TYPE_FUNCTION,
							},
						},
					},
				},

				{
					.name = "whoo_hoo",
					.offset = 2496,
					.type = {
						.type = FIELD_TYPE_COMPLEX_FLOAT,
					},
				},

				{
					.name = "lmao_you_gae",
					.offset = 2560,
					.type = {
						.type = FIELD_TYPE_GNU_EXT_COMPLEX_I32,
					},
				},
			},
		},

		{
			.ID = 22332,
			.filename = "/home/randompigyt/Reflection/testFiles/anon.c",
			.name = "",
			.numAliases = 0,
			.aliases = (char (*[])) {

				// No aliases

			},
			.recordType = RECORD_TYPE_STRUCT,
			.numFields = 2,
			.fields = (struct flr_field[]) {
				{
					.name = "d",
					.offset = 0,
					.type = {
						.type = FIELD_TYPE_I32,
					},
				},

				{
					.name = "f",
					.offset = 32,
					.type = {
						.type = FIELD_TYPE_I32,
					},
				},
			},
		},

		{
			.ID = 22649,
			.filename = "/home/randompigyt/Reflection/testFiles/anon.c",
			.name = "struct shit",
			.numAliases = 0,
			.aliases = (char (*[])) {

				// No aliases

			},
			.recordType = RECORD_TYPE_STRUCT,
			.numFields = 2,
			.fields = (struct flr_field[]) {
				{
					.name = "a",
					.offset = 0,
					.type = {
						.type = FIELD_TYPE_BITFIELD,
						.bitFieldInfo = &(struct flr_bitFieldRef) {
							.bitWidth = 23,
						},
					},
				},

				{
					.name = "b",
					.offset = 32,
					.type = {
						.type = FIELD_TYPE_BITFIELD,
						.bitFieldInfo = &(struct flr_bitFieldRef) {
							.bitWidth = 23,
						},
					},
				},
			},
		},

		{
			.ID = 512,
			.filename = "/home/randompigyt/Reflection/testFiles/as.c",
			.name = "struct hello_t",
			.numAliases = 1,
			.aliases = (char (*[])) {
				"hello",
			},
			.recordType = RECORD_TYPE_STRUCT,
			.numFields = 3,
			.fields = (struct flr_field[]) {
				{
					.name = "a",
					.offset = 0,
					.type = {
						.type = FIELD_TYPE_I32,
					},
				},

				{
					.name = "b",
					.offset = 32,
					.type = {
						.type = FIELD_TYPE_I32,
					},
				},

				{
					.name = "f",
					.offset = 64,
					.type = {
						.type = FIELD_TYPE_PTR,
						.ptrInfo = &(struct flr_ptrRef) {
							.level = 1,
							.type = {
								.type = FIELD_TYPE_FUNCTION,
							},
						},
					},
				},
			},
		},

		{
			.ID = 641,
			.filename = "/home/randompigyt/Reflection/testFiles/as.c",
			.name = "",
			.numAliases = 1,
			.aliases = (char (*[])) {
				"Hi",
			},
			.recordType = RECORD_TYPE_STRUCT,
			.numFields = 1,
			.fields = (struct flr_field[]) {
				{
					.name = "a",
					.offset = 0,
					.type = {
						.type = FIELD_TYPE_I32,
					},
				},
			},
		},

		{
			.ID = 701,
			.filename = "/home/randompigyt/Reflection/testFiles/as.c",
			.name = "union Hello_u",
			.numAliases = 0,
			.aliases = (char (*[])) {

				// No aliases

			},
			.recordType = RECORD_TYPE_UNION,
			.numFields = 2,
			.fields = (struct flr_field[]) {
				{
					.name = "uniono",
					.offset = 0,
					.type = {
						.type = FIELD_TYPE_I32,
					},
				},

				{
					.name = "amiinsamemem",
					.offset = 0,
					.type = {
						.type = FIELD_TYPE_I32,
					},
				},
			},
		},

		{
			.ID = 748,
			.filename = "/home/randompigyt/Reflection/testFiles/as.c",
			.name = "struct helloo",
			.numAliases = 0,
			.aliases = (char (*[])) {

				// No aliases

			},
			.recordType = RECORD_TYPE_STRUCT,
			.numFields = 1,
			.fields = (struct flr_field[]) {
				{
					.name = "a",
					.offset = 0,
					.type = {
						.type = FIELD_TYPE_I32,
					},
				},
			},
		},

		{
			.ID = 781,
			.filename = "/home/randompigyt/Reflection/testFiles/as.c",
			.name = "struct bruh",
			.numAliases = 4,
			.aliases = (char (*[])) {
				"bruh",
				"gae",
				"YooHoo",
				"fml",
			},
			.recordType = RECORD_TYPE_STRUCT,
			.numFields = 9,
			.fields = (struct flr_field[]) {
				{
					.name = "c",
					.offset = 0,
					.type = {
						.type = FIELD_TYPE_I32,
					},
				},

				{
					.name = "b",
					.offset = 32,
					.type = {
						.type = FIELD_TYPE_I32,
					},
				},

				{
					.name = "h",
					.offset = 64,
					.type = {
						.type = FIELD_TYPE_I32,
					},
				},

				{
					.name = "f",
					.offset = 96,
					.type = {
						.type = FIELD_TYPE_I32,
					},
				},

				{
					.name = "g",
					.offset = 128,
					.type = {
						.type = FIELD_TYPE_STRUCT,
						.recordInfo = &(struct flr_recordRef) {
							.ID = 994,
							.filename = "/home/randompigyt/Reflection/testFiles/as.c",
						},
					},
				},

				{
					.name = "lmao",
					.offset = 256,
					.type = {
						.type = FIELD_TYPE_PTR,
						.ptrInfo = &(struct flr_ptrRef) {
							.level = 3,
							.type = {
								.type = FIELD_TYPE_STRUCT,
								.recordInfo = &(struct flr_recordRef) {
									.ID = 748,
									.filename = "/home/randompigyt/Reflection/testFiles/as.c",
								},
							},
						},
					},
				},

				{
					.name = "u",
					.offset = 320,
					.type = {
						.type = FIELD_TYPE_UNION,
						.recordInfo = &(struct flr_recordRef) {
							.ID = 701,
							.filename = "/home/randompigyt/Reflection/testFiles/as.c",
						},
					},
				},

				{
					.name = "z",
					.offset = 384,
					.type = {
						.type = FIELD_TYPE_PTR,
						.ptrInfo = &(struct flr_ptrRef) {
							.level = 1,
							.type = {
								.type = FIELD_TYPE_STRUCT,
								.recordInfo = &(struct flr_recordRef) {
									.ID = 1160,
									.filename = "/home/randompigyt/Reflection/testFiles/as.c",
								},
							},
						},
					},
				},

				{
					.name = "a",
					.offset = 448,
					.type = {
						.type = FIELD_TYPE_I32,
					},
				},
			},
		},

		{
			.ID = 994,
			.filename = "/home/randompigyt/Reflection/testFiles/as.c",
			.name = "",
			.numAliases = 0,
			.aliases = (char (*[])) {

				// No aliases

			},
			.recordType = RECORD_TYPE_STRUCT,
			.numFields = 3,
			.fields = (struct flr_field[]) {
				{
					.name = "d",
					.offset = 0,
					.type = {
						.type = FIELD_TYPE_I32,
					},
				},

				{
					.name = "f",
					.offset = 32,
					.type = {
						.type = FIELD_TYPE_I32,
					},
				},

				{
					.name = "haha",
					.offset = 64,
					.type = {
						.type = FIELD_TYPE_I32,
					},
				},
			},
		},

		{
			.ID = 1160,
			.filename = "/home/randompigyt/Reflection/testFiles/as.c",
			.name = "",
			.numAliases = 0,
			.aliases = (char (*[])) {

				// No aliases

			},
			.recordType = RECORD_TYPE_STRUCT,
			.numFields = 3,
			.fields = (struct flr_field[]) {
				{
					.name = "d",
					.offset = 0,
					.type = {
						.type = FIELD_TYPE_I32,
					},
				},

				{
					.name = "f",
					.offset = 32,
					.type = {
						.type = FIELD_TYPE_I32,
					},
				},

				{
					.name = "haha",
					.offset = 64,
					.type = {
						.type = FIELD_TYPE_I32,
					},
				},
			},
		},
	},

	.enums = (struct flr_enumInfo[]) {
		{
			.ID = 22712,
			.filename = "/home/randompigyt/Reflection/testFiles/anon.c",
			.name = "enum e",
			.numAliases = 0,
			.aliases = (char (*[])) {

				// No aliases

			},
			.numConstants = 2,
			.constants = (struct flr_enumConstant[]) {
				{
					.name = "HI",
					.value = 0,
				},

				{
					.name = "HELLO",
					.value = 1,
				},
			},
		},

		{
			.ID = 1369,
			.filename = "/home/randompigyt/Reflection/testFiles/as.c",
			.name = "enum a",
			.numAliases = 1,
			.aliases = (char (*[])) {
				"ennnnn",
			},
			.numConstants = 3,
			.constants = (struct flr_enumConstant[]) {
				{
					.name = "HI",
					.value = 0,
				},

				{
					.name = "WHOO",
					.value = 1,
				},

				{
					.name = "JDHFKDJ",
					.value = 2,
				},
			},
		},
	},
};

struct flr_programInfo flr_load() {
	return info;
}
