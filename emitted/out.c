#include "../include/flare.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

struct flr_programInfo info = {
	.numTypes = 8,
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
					},
				},

				{
					.name = "b",
					.offset = 32,
					.type = {
					},
				},

				{
					.name = "f",
					.offset = 64,
					.type = {
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
					},
				},

				{
					.name = "amiinsamemem",
					.offset = 0,
					.type = {
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
					},
				},

				{
					.name = "c",
					.offset = 0,
					.type = {
					},
				},

				{
					.name = "b",
					.offset = 32,
					.type = {
					},
				},

				{
					.name = "h",
					.offset = 64,
					.type = {
					},
				},

				{
					.name = "f",
					.offset = 96,
					.type = {
					},
				},

				{
					.name = "g",
					.offset = 128,
					.type = {
					},
				},

				{
					.name = "lmao",
					.offset = 192,
					.type = {
					},
				},

				{
					.name = "a",
					.offset = 256,
					.type = {
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
			.numFields = 2,
			.fields = (struct flr_field[]) {
				{
					.name = "d",
					.offset = 0,
					.type = {
					},
				},

				{
					.name = "f",
					.offset = 32,
					.type = {
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
					},
				},

				{
					.name = "b",
					.offset = 16,
					.type = {
					},
				},

				{
					.name = "c",
					.offset = 32,
					.type = {
					},
				},

				{
					.name = "d",
					.offset = 64,
					.type = {
					},
				},

				{
					.name = "q",
					.offset = 128,
					.type = {
					},
				},

				{
					.name = "e",
					.offset = 192,
					.type = {
					},
				},

				{
					.name = "f",
					.offset = 208,
					.type = {
					},
				},

				{
					.name = "g",
					.offset = 224,
					.type = {
					},
				},

				{
					.name = "h",
					.offset = 256,
					.type = {
					},
				},

				{
					.name = "r",
					.offset = 320,
					.type = {
					},
				},

				{
					.name = "i",
					.offset = 384,
					.type = {
					},
				},

				{
					.name = "j",
					.offset = 448,
					.type = {
					},
				},

				{
					.name = "k",
					.offset = 512,
					.type = {
					},
				},

				{
					.name = "l",
					.offset = 640,
					.type = {
					},
				},

				{
					.name = "m",
					.offset = 704,
					.type = {
					},
				},

				{
					.name = "n",
					.offset = 896,
					.type = {
					},
				},

				{
					.name = "o",
					.offset = 1152,
					.type = {
					},
				},

				{
					.name = "p",
					.offset = 1216,
					.type = {
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
