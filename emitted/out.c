#include "../include/flare.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

struct flr_programInfo info = {
	.numTypes = 9,
	.numEnums = 0,

	.types = (struct flr_typeInfo[]) {
		{
			.ID = 512,
			.filename = "/home/randompigyt/Reflection/testFiles/as.c",
			.name = "struct hello_t",
			.numAliases = 1,
			.aliases = (char (*[])) {
				"hello",
			},
			.recordType = 0,
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
			.recordType = 0,
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
			.recordType = 1,
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
			.recordType = 0,
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
			.recordType = 0,
			.numFields = 8,
			.fields = (struct flr_field[]) {
				{
					.name = "",
					.offset = 0,
					.type = {
						.type = FIELD_TYPE_STRUCT,
						.recordInfo = &(struct flr_recordRef) {
							.ID = 802,
							.fileName = "/home/randompigyt/Reflection/testFiles/as.c",
						},
					},
				},

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
							.fileName = "/home/randompigyt/Reflection/testFiles/as.c",
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
									.fileName = "/home/randompigyt/Reflection/testFiles/as.c",
								},
							},
						},
					},
				},

				{
					.name = "a",
					.offset = 320,
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
			.recordType = 0,
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
			.ID = 1077,
			.filename = "/home/randompigyt/Reflection/testFiles/kind.c",
			.name = "",
			.numAliases = 1,
			.aliases = (char (*[])) {
				"__fsid_t",
			},
			.recordType = 0,
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
			.ID = 23656,
			.filename = "/home/randompigyt/Reflection/testFiles/kind.c",
			.name = "struct hi",
			.numAliases = 0,
			.aliases = (char (*[])) {

				// No aliases

			},
			.recordType = 0,
			.numFields = 18,
			.fields = (struct flr_field[]) {
				{
					.name = "a",
					.offset = 0,
					.type = {
						.type = FIELD_TYPE_I8,
					},
				},

				{
					.name = "b",
					.offset = 16,
					.type = {
						.type = FIELD_TYPE_I16,
					},
				},

				{
					.name = "c",
					.offset = 32,
					.type = {
						.type = FIELD_TYPE_I32,
					},
				},

				{
					.name = "d",
					.offset = 64,
					.type = {
						.type = FIELD_TYPE_I64,
					},
				},

				{
					.name = "q",
					.offset = 128,
					.type = {
						.type = FIELD_TYPE_LONGLONG,
					},
				},

				{
					.name = "e",
					.offset = 192,
					.type = {
						.type = FIELD_TYPE_UI8,
					},
				},

				{
					.name = "f",
					.offset = 208,
					.type = {
						.type = FIELD_TYPE_UI16,
					},
				},

				{
					.name = "g",
					.offset = 224,
					.type = {
						.type = FIELD_TYPE_UI32,
					},
				},

				{
					.name = "h",
					.offset = 256,
					.type = {
						.type = FIELD_TYPE_UI64,
					},
				},

				{
					.name = "r",
					.offset = 320,
					.type = {
						.type = FIELD_TYPE_ULONGLONG,
					},
				},

				{
					.name = "i",
					.offset = 384,
					.type = {
						.type = FIELD_TYPE_FLOAT,
					},
				},

				{
					.name = "j",
					.offset = 448,
					.type = {
						.type = FIELD_TYPE_DOUBLE,
					},
				},

				{
					.name = "k",
					.offset = 512,
					.type = {
						.type = FIELD_TYPE_LONG_DOUBLE,
					},
				},

				{
					.name = "l",
					.offset = 640,
					.type = {
						.type = FIELD_TYPE_COMPLEX_FLOAT,
					},
				},

				{
					.name = "m",
					.offset = 704,
					.type = {
						.type = FIELD_TYPE_COMPLEX_DOUBLE,
					},
				},

				{
					.name = "n",
					.offset = 896,
					.type = {
						.type = FIELD_TYPE_COMPLEX_LONG_DOUBLE,
					},
				},

				{
					.name = "o",
					.offset = 1152,
					.type = {
						.type = FIELD_TYPE_GNU_EXT_COMPLEX_I32,
					},
				},

				{
					.name = "p",
					.offset = 1216,
					.type = {
						.type = FIELD_TYPE_PTR,
						.ptrInfo = &(struct flr_ptrRef) {
							.level = 1,
							.type = {
								.type = FIELD_TYPE_VOID,
							},
						},
					},
				},
			},
		},

		{
			.ID = 512,
			.filename = "/home/randompigyt/Reflection/testFiles/array.c",
			.name = "struct hello",
			.numAliases = 0,
			.aliases = (char (*[])) {

				// No aliases

			},
			.recordType = 0,
			.numFields = 2,
			.fields = (struct flr_field[]) {
				{
					.name = "b",
					.offset = 0,
					.type = {
						.type = FIELD_TYPE_I32,
					},
				},

				{
					.name = "a",
					.offset = 32,
					.type = {
						.type = FIELD_TYPE_ARRAY,
						.arrayInfo = &(struct flr_arrayRef) {
							.size = -1,
							.type = {
								.type = FIELD_TYPE_ARRAY,
								.arrayInfo = &(struct flr_arrayRef) {
									.size = 5,
									.type = {
										.type = FIELD_TYPE_ARRAY,
										.arrayInfo = &(struct flr_arrayRef) {
											.size = 45,
											.type = {
												.type = FIELD_TYPE_ARRAY,
												.arrayInfo = &(struct flr_arrayRef) {
													.size = 5,
													.type = {
														.type = FIELD_TYPE_I32,
													},
												},
											},
										},
									},
								},
							},
						},
					},
				},
			},
		},
	},

	.enums = (struct flr_enumInfo[]) {
	},
};

struct flr_programInfo flr_load(flr_Alloc allocator) {
	return info;
}
