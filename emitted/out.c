#include "../include/flare.h"

struct flr_programInfo info = {
	.numTypes = 7,
	.numEnums = 1,

	.types = (struct flr_typeInfo[]) {
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
