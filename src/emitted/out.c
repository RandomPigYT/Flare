#include "../../include/flare.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

struct flr_programInfo flr_load(flr_Alloc allocator) {
	struct flr_programInfo info;
	
	info.types = malloc(8 * sizeof(struct flr_typeInfo));
	info.numTypes = 8;
	
	info.enums = malloc(0 * sizeof(struct flr_enumInfo));
	info.numEnums = 0;
	
	info.types[0].ID = 512;
	info.types[0].filename = malloc(44 * sizeof(char));
	strcpy(info.types[0].filename, "/home/randompigyt/Reflection/testFiles/as.c");
	info.types[0].name = malloc(15 * sizeof(char));
	strcpy(info.types[0].name, "struct hello_t");
	info.types[0].aliases = malloc(1 * sizeof(char *));
	info.types[0].aliases[0] = malloc(6 * sizeof(char));
	strcpy(info.types[0].aliases[0], "hello");
	info.types[0].recordType = 0;
	info.types[0].fields = malloc(3 * sizeof(struct flr_field));
	info.types[0].fields[0].name = malloc(2 * sizeof(char));
	strcpy(info.types[0].fields[0].name, "a");
	info.types[0].fields[0].offset = 0;
	info.types[0].fields[0].type.type = 182;
	info.types[0].fields[1].name = malloc(2 * sizeof(char));
	strcpy(info.types[0].fields[1].name, "b");
	info.types[0].fields[1].offset = 32;
	info.types[0].fields[1].type.type = 182;
	info.types[0].fields[2].name = malloc(2 * sizeof(char));
	strcpy(info.types[0].fields[2].name, "f");
	info.types[0].fields[2].offset = 64;
	info.types[0].fields[2].type.type = 1;
	
	info.types[1].ID = 641;
	info.types[1].filename = malloc(44 * sizeof(char));
	strcpy(info.types[1].filename, "/home/randompigyt/Reflection/testFiles/as.c");
	info.types[1].name = malloc(1 * sizeof(char));
	strcpy(info.types[1].name, "");
	info.types[1].aliases = malloc(1 * sizeof(char *));
	info.types[1].aliases[0] = malloc(3 * sizeof(char));
	strcpy(info.types[1].aliases[0], "Hi");
	info.types[1].recordType = 0;
	info.types[1].fields = malloc(1 * sizeof(struct flr_field));
	info.types[1].fields[0].name = malloc(2 * sizeof(char));
	strcpy(info.types[1].fields[0].name, "a");
	info.types[1].fields[0].offset = 0;
	info.types[1].fields[0].type.type = 182;
	
	info.types[2].ID = 701;
	info.types[2].filename = malloc(44 * sizeof(char));
	strcpy(info.types[2].filename, "/home/randompigyt/Reflection/testFiles/as.c");
	info.types[2].name = malloc(14 * sizeof(char));
	strcpy(info.types[2].name, "union Hello_u");
	info.types[2].aliases = malloc(0 * sizeof(char *));
	info.types[2].recordType = 1;
	info.types[2].fields = malloc(2 * sizeof(struct flr_field));
	info.types[2].fields[0].name = malloc(7 * sizeof(char));
	strcpy(info.types[2].fields[0].name, "uniono");
	info.types[2].fields[0].offset = 0;
	info.types[2].fields[0].type.type = 182;
	info.types[2].fields[1].name = malloc(13 * sizeof(char));
	strcpy(info.types[2].fields[1].name, "amiinsamemem");
	info.types[2].fields[1].offset = 0;
	info.types[2].fields[1].type.type = 182;
	
	info.types[3].ID = 748;
	info.types[3].filename = malloc(44 * sizeof(char));
	strcpy(info.types[3].filename, "/home/randompigyt/Reflection/testFiles/as.c");
	info.types[3].name = malloc(14 * sizeof(char));
	strcpy(info.types[3].name, "struct helloo");
	info.types[3].aliases = malloc(0 * sizeof(char *));
	info.types[3].recordType = 0;
	info.types[3].fields = malloc(1 * sizeof(struct flr_field));
	info.types[3].fields[0].name = malloc(2 * sizeof(char));
	strcpy(info.types[3].fields[0].name, "a");
	info.types[3].fields[0].offset = 0;
	info.types[3].fields[0].type.type = 182;
	
	info.types[4].ID = 781;
	info.types[4].filename = malloc(44 * sizeof(char));
	strcpy(info.types[4].filename, "/home/randompigyt/Reflection/testFiles/as.c");
	info.types[4].name = malloc(12 * sizeof(char));
	strcpy(info.types[4].name, "struct bruh");
	info.types[4].aliases = malloc(4 * sizeof(char *));
	info.types[4].aliases[0] = malloc(5 * sizeof(char));
	strcpy(info.types[4].aliases[0], "bruh");
	info.types[4].aliases[1] = malloc(4 * sizeof(char));
	strcpy(info.types[4].aliases[1], "gae");
	info.types[4].aliases[2] = malloc(7 * sizeof(char));
	strcpy(info.types[4].aliases[2], "YooHoo");
	info.types[4].aliases[3] = malloc(4 * sizeof(char));
	strcpy(info.types[4].aliases[3], "fml");
	info.types[4].recordType = 0;
	info.types[4].fields = malloc(8 * sizeof(struct flr_field));
	info.types[4].fields[0].name = malloc(1 * sizeof(char));
	strcpy(info.types[4].fields[0].name, "");
	info.types[4].fields[0].offset = 0;
	info.types[4].fields[0].type.type = 4;
	info.types[4].fields[1].name = malloc(2 * sizeof(char));
	strcpy(info.types[4].fields[1].name, "c");
	info.types[4].fields[1].offset = 0;
	info.types[4].fields[1].type.type = 182;
	info.types[4].fields[2].name = malloc(2 * sizeof(char));
	strcpy(info.types[4].fields[2].name, "b");
	info.types[4].fields[2].offset = 32;
	info.types[4].fields[2].type.type = 182;
	info.types[4].fields[3].name = malloc(2 * sizeof(char));
	strcpy(info.types[4].fields[3].name, "h");
	info.types[4].fields[3].offset = 64;
	info.types[4].fields[3].type.type = 182;
	info.types[4].fields[4].name = malloc(2 * sizeof(char));
	strcpy(info.types[4].fields[4].name, "f");
	info.types[4].fields[4].offset = 96;
	info.types[4].fields[4].type.type = 182;
	info.types[4].fields[5].name = malloc(2 * sizeof(char));
	strcpy(info.types[4].fields[5].name, "g");
	info.types[4].fields[5].offset = 128;
	info.types[4].fields[5].type.type = 4;
	info.types[4].fields[6].name = malloc(5 * sizeof(char));
	strcpy(info.types[4].fields[6].name, "lmao");
	info.types[4].fields[6].offset = 192;
	info.types[4].fields[6].type.type = 1;
	info.types[4].fields[7].name = malloc(2 * sizeof(char));
	strcpy(info.types[4].fields[7].name, "a");
	info.types[4].fields[7].offset = 256;
	info.types[4].fields[7].type.type = 182;
	
	info.types[5].ID = 994;
	info.types[5].filename = malloc(44 * sizeof(char));
	strcpy(info.types[5].filename, "/home/randompigyt/Reflection/testFiles/as.c");
	info.types[5].name = malloc(1 * sizeof(char));
	strcpy(info.types[5].name, "");
	info.types[5].aliases = malloc(0 * sizeof(char *));
	info.types[5].recordType = 0;
	info.types[5].fields = malloc(2 * sizeof(struct flr_field));
	info.types[5].fields[0].name = malloc(2 * sizeof(char));
	strcpy(info.types[5].fields[0].name, "d");
	info.types[5].fields[0].offset = 0;
	info.types[5].fields[0].type.type = 182;
	info.types[5].fields[1].name = malloc(2 * sizeof(char));
	strcpy(info.types[5].fields[1].name, "f");
	info.types[5].fields[1].offset = 32;
	info.types[5].fields[1].type.type = 182;
	
	info.types[6].ID = 1077;
	info.types[6].filename = malloc(46 * sizeof(char));
	strcpy(info.types[6].filename, "/home/randompigyt/Reflection/testFiles/kind.c");
	info.types[6].name = malloc(1 * sizeof(char));
	strcpy(info.types[6].name, "");
	info.types[6].aliases = malloc(1 * sizeof(char *));
	info.types[6].aliases[0] = malloc(9 * sizeof(char));
	strcpy(info.types[6].aliases[0], "__fsid_t");
	info.types[6].recordType = 0;
	info.types[6].fields = malloc(1 * sizeof(struct flr_field));
	info.types[6].fields[0].name = malloc(6 * sizeof(char));
	strcpy(info.types[6].fields[0].name, "__val");
	info.types[6].fields[0].offset = 0;
	info.types[6].fields[0].type.type = 2;
	
	info.types[7].ID = 23656;
	info.types[7].filename = malloc(46 * sizeof(char));
	strcpy(info.types[7].filename, "/home/randompigyt/Reflection/testFiles/kind.c");
	info.types[7].name = malloc(10 * sizeof(char));
	strcpy(info.types[7].name, "struct hi");
	info.types[7].aliases = malloc(0 * sizeof(char *));
	info.types[7].recordType = 0;
	info.types[7].fields = malloc(18 * sizeof(struct flr_field));
	info.types[7].fields[0].name = malloc(2 * sizeof(char));
	strcpy(info.types[7].fields[0].name, "a");
	info.types[7].fields[0].offset = 0;
	info.types[7].fields[0].type.type = 179;
	info.types[7].fields[1].name = malloc(2 * sizeof(char));
	strcpy(info.types[7].fields[1].name, "b");
	info.types[7].fields[1].offset = 16;
	info.types[7].fields[1].type.type = 181;
	info.types[7].fields[2].name = malloc(2 * sizeof(char));
	strcpy(info.types[7].fields[2].name, "c");
	info.types[7].fields[2].offset = 32;
	info.types[7].fields[2].type.type = 182;
	info.types[7].fields[3].name = malloc(2 * sizeof(char));
	strcpy(info.types[7].fields[3].name, "d");
	info.types[7].fields[3].offset = 64;
	info.types[7].fields[3].type.type = 183;
	info.types[7].fields[4].name = malloc(2 * sizeof(char));
	strcpy(info.types[7].fields[4].name, "q");
	info.types[7].fields[4].offset = 128;
	info.types[7].fields[4].type.type = 184;
	info.types[7].fields[5].name = malloc(2 * sizeof(char));
	strcpy(info.types[7].fields[5].name, "e");
	info.types[7].fields[5].offset = 192;
	info.types[7].fields[5].type.type = 168;
	info.types[7].fields[6].name = malloc(2 * sizeof(char));
	strcpy(info.types[7].fields[6].name, "f");
	info.types[7].fields[6].offset = 208;
	info.types[7].fields[6].type.type = 173;
	info.types[7].fields[7].name = malloc(2 * sizeof(char));
	strcpy(info.types[7].fields[7].name, "g");
	info.types[7].fields[7].offset = 224;
	info.types[7].fields[7].type.type = 174;
	info.types[7].fields[8].name = malloc(2 * sizeof(char));
	strcpy(info.types[7].fields[8].name, "h");
	info.types[7].fields[8].offset = 256;
	info.types[7].fields[8].type.type = 175;
	info.types[7].fields[9].name = malloc(2 * sizeof(char));
	strcpy(info.types[7].fields[9].name, "r");
	info.types[7].fields[9].offset = 320;
	info.types[7].fields[9].type.type = 176;
	info.types[7].fields[10].name = malloc(2 * sizeof(char));
	strcpy(info.types[7].fields[10].name, "i");
	info.types[7].fields[10].offset = 384;
	info.types[7].fields[10].type.type = 211;
	info.types[7].fields[11].name = malloc(2 * sizeof(char));
	strcpy(info.types[7].fields[11].name, "j");
	info.types[7].fields[11].offset = 448;
	info.types[7].fields[11].type.type = 212;
	info.types[7].fields[12].name = malloc(2 * sizeof(char));
	strcpy(info.types[7].fields[12].name, "k");
	info.types[7].fields[12].offset = 512;
	info.types[7].fields[12].type.type = 213;
	info.types[7].fields[13].name = malloc(2 * sizeof(char));
	strcpy(info.types[7].fields[13].name, "l");
	info.types[7].fields[13].offset = 640;
	info.types[7].fields[13].type.type = -2147483437;
	info.types[7].fields[14].name = malloc(2 * sizeof(char));
	strcpy(info.types[7].fields[14].name, "m");
	info.types[7].fields[14].offset = 704;
	info.types[7].fields[14].type.type = -2147483436;
	info.types[7].fields[15].name = malloc(2 * sizeof(char));
	strcpy(info.types[7].fields[15].name, "n");
	info.types[7].fields[15].offset = 896;
	info.types[7].fields[15].type.type = -2147483435;
	info.types[7].fields[16].name = malloc(2 * sizeof(char));
	strcpy(info.types[7].fields[16].name, "o");
	info.types[7].fields[16].offset = 1152;
	info.types[7].fields[16].type.type = -2147483466;
	info.types[7].fields[17].name = malloc(2 * sizeof(char));
	strcpy(info.types[7].fields[17].name, "p");
	info.types[7].fields[17].offset = 1216;
	info.types[7].fields[17].type.type = 1;
	
	return info;
}
