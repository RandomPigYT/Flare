#include "../../include/flare.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

struct flr_programInfo flr_load(flr_Alloc allocator) {
	struct flr_programInfo info;
	if (!allocator) 
		allocator = malloc;

	info.types = malloc(49 * sizeof(struct flr_typeInfo));
	info.numTypes = 49;
	
	info.enums = malloc(0 * sizeof(struct flr_enumInfo));
	info.numEnums = 0;

	info.types[0].ID = 512;
	info.types[0].filename = "/home/randompigyt/Reflection/testFiles/as.c";
	info.types[0].name = "struct hello_t";
	info.types[0].aliases = malloc(1 * sizeof(char *));
	info.types[0].aliases[0] = malloc(6);
	strcpy(info.types[0].aliases[0], "hello");
	
	info.types[1].ID = 641;
	info.types[1].filename = "/home/randompigyt/Reflection/testFiles/as.c";
	info.types[1].name = "";
	info.types[1].aliases = malloc(1 * sizeof(char *));
	info.types[1].aliases[0] = malloc(3);
	strcpy(info.types[1].aliases[0], "Hi");
	
	info.types[2].ID = 701;
	info.types[2].filename = "/home/randompigyt/Reflection/testFiles/as.c";
	info.types[2].name = "union Hello_u";
	info.types[2].aliases = malloc(0 * sizeof(char *));
	
	info.types[3].ID = 722;
	info.types[3].filename = "/home/randompigyt/Reflection/testFiles/as.c";
	info.types[3].name = "struct helloo";
	info.types[3].aliases = malloc(0 * sizeof(char *));
	
	info.types[4].ID = 755;
	info.types[4].filename = "/home/randompigyt/Reflection/testFiles/as.c";
	info.types[4].name = "struct bruh";
	info.types[4].aliases = malloc(2 * sizeof(char *));
	info.types[4].aliases[0] = malloc(5);
	strcpy(info.types[4].aliases[0], "bruh");
	info.types[4].aliases[1] = malloc(4);
	strcpy(info.types[4].aliases[1], "gae");
	
	info.types[5].ID = 968;
	info.types[5].filename = "/home/randompigyt/Reflection/testFiles/as.c";
	info.types[5].name = "";
	info.types[5].aliases = malloc(0 * sizeof(char *));
	
	info.types[6].ID = 1133;
	info.types[6].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[6].name = "";
	info.types[6].aliases = malloc(2 * sizeof(char *));
	info.types[6].aliases[0] = malloc(9);
	strcpy(info.types[6].aliases[0], "__fsid_t");
	info.types[6].aliases[1] = malloc(7);
	strcpy(info.types[6].aliases[1], "fsid_t");
	
	info.types[7].ID = 1617;
	info.types[7].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[7].name = "";
	info.types[7].aliases = malloc(1 * sizeof(char *));
	info.types[7].aliases[0] = malloc(12);
	strcpy(info.types[7].aliases[0], "__mbstate_t");
	
	info.types[8].ID = 1651;
	info.types[8].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[8].name = "";
	info.types[8].aliases = malloc(0 * sizeof(char *));
	
	info.types[9].ID = 1763;
	info.types[9].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[9].name = "struct _G_fpos_t";
	info.types[9].aliases = malloc(2 * sizeof(char *));
	info.types[9].aliases[0] = malloc(9);
	strcpy(info.types[9].aliases[0], "__fpos_t");
	info.types[9].aliases[1] = malloc(7);
	strcpy(info.types[9].aliases[1], "fpos_t");
	
	info.types[10].ID = 1857;
	info.types[10].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[10].name = "struct _G_fpos64_t";
	info.types[10].aliases = malloc(2 * sizeof(char *));
	info.types[10].aliases[0] = malloc(11);
	strcpy(info.types[10].aliases[0], "__fpos64_t");
	info.types[10].aliases[1] = malloc(9);
	strcpy(info.types[10].aliases[1], "fpos64_t");
	
	info.types[11].ID = 1927;
	info.types[11].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[11].name = "struct _IO_FILE";
	info.types[11].aliases = malloc(0 * sizeof(char *));
	
	info.types[12].ID = 1969;
	info.types[12].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[12].name = "struct _IO_FILE";
	info.types[12].aliases = malloc(0 * sizeof(char *));
	
	info.types[13].ID = 2000;
	info.types[13].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[13].name = "struct _IO_FILE";
	info.types[13].aliases = malloc(0 * sizeof(char *));
	
	info.types[14].ID = 2016;
	info.types[14].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[14].name = "struct _IO_marker";
	info.types[14].aliases = malloc(0 * sizeof(char *));
	
	info.types[15].ID = 2048;
	info.types[15].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[15].name = "struct _IO_codecvt";
	info.types[15].aliases = malloc(0 * sizeof(char *));
	
	info.types[16].ID = 2068;
	info.types[16].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[16].name = "struct _IO_wide_data";
	info.types[16].aliases = malloc(0 * sizeof(char *));
	
	info.types[17].ID = 2101;
	info.types[17].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[17].name = "struct _IO_FILE";
	info.types[17].aliases = malloc(0 * sizeof(char *));
	
	info.types[18].ID = 2985;
	info.types[18].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[18].name = "struct _IO_cookie_io_functions_t";
	info.types[18].aliases = malloc(1 * sizeof(char *));
	info.types[18].aliases[0] = malloc(22);
	strcpy(info.types[18].aliases[0], "cookie_io_functions_t");
	
	info.types[19].ID = 13971;
	info.types[19].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[19].name = "struct obstack";
	info.types[19].aliases = malloc(0 * sizeof(char *));
	
	info.types[20].ID = 14604;
	info.types[20].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[20].name = "";
	info.types[20].aliases = malloc(1 * sizeof(char *));
	info.types[20].aliases[0] = malloc(6);
	strcpy(info.types[20].aliases[0], "div_t");
	
	info.types[21].ID = 14675;
	info.types[21].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[21].name = "";
	info.types[21].aliases = malloc(1 * sizeof(char *));
	info.types[21].aliases[0] = malloc(7);
	strcpy(info.types[21].aliases[0], "ldiv_t");
	
	info.types[22].ID = 14747;
	info.types[22].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[22].name = "";
	info.types[22].aliases = malloc(1 * sizeof(char *));
	info.types[22].aliases[0] = malloc(8);
	strcpy(info.types[22].aliases[0], "lldiv_t");
	
	info.types[23].ID = 18859;
	info.types[23].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[23].name = "struct __locale_struct";
	info.types[23].aliases = malloc(0 * sizeof(char *));
	
	info.types[24].ID = 18880;
	info.types[24].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[24].name = "struct __locale_data";
	info.types[24].aliases = malloc(0 * sizeof(char *));
	
	info.types[25].ID = 23074;
	info.types[25].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[25].name = "";
	info.types[25].aliases = malloc(2 * sizeof(char *));
	info.types[25].aliases[0] = malloc(11);
	strcpy(info.types[25].aliases[0], "__sigset_t");
	info.types[25].aliases[1] = malloc(9);
	strcpy(info.types[25].aliases[1], "sigset_t");
	
	info.types[26].ID = 23209;
	info.types[26].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[26].name = "struct timeval";
	info.types[26].aliases = malloc(0 * sizeof(char *));
	
	info.types[27].ID = 23254;
	info.types[27].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[27].name = "struct timespec";
	info.types[27].aliases = malloc(0 * sizeof(char *));
	
	info.types[28].ID = 23324;
	info.types[28].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[28].name = "";
	info.types[28].aliases = malloc(1 * sizeof(char *));
	info.types[28].aliases[0] = malloc(7);
	strcpy(info.types[28].aliases[0], "fd_set");
	
	info.types[29].ID = 24015;
	info.types[29].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[29].name = "";
	info.types[29].aliases = malloc(1 * sizeof(char *));
	info.types[29].aliases[0] = malloc(22);
	strcpy(info.types[29].aliases[0], "__atomic_wide_counter");
	
	info.types[30].ID = 24064;
	info.types[30].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[30].name = "";
	info.types[30].aliases = malloc(0 * sizeof(char *));
	
	info.types[31].ID = 24157;
	info.types[31].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[31].name = "struct __pthread_internal_list";
	info.types[31].aliases = malloc(1 * sizeof(char *));
	info.types[31].aliases[0] = malloc(17);
	strcpy(info.types[31].aliases[0], "__pthread_list_t");
	
	info.types[32].ID = 24251;
	info.types[32].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[32].name = "struct __pthread_internal_slist";
	info.types[32].aliases = malloc(1 * sizeof(char *));
	info.types[32].aliases[0] = malloc(18);
	strcpy(info.types[32].aliases[0], "__pthread_slist_t");
	
	info.types[33].ID = 24329;
	info.types[33].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[33].name = "struct __pthread_mutex_s";
	info.types[33].aliases = malloc(0 * sizeof(char *));
	
	info.types[34].ID = 24466;
	info.types[34].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[34].name = "struct __pthread_rwlock_arch_t";
	info.types[34].aliases = malloc(0 * sizeof(char *));
	
	info.types[35].ID = 24668;
	info.types[35].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[35].name = "struct __pthread_cond_s";
	info.types[35].aliases = malloc(0 * sizeof(char *));
	
	info.types[36].ID = 24878;
	info.types[36].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[36].name = "";
	info.types[36].aliases = malloc(1 * sizeof(char *));
	info.types[36].aliases[0] = malloc(12);
	strcpy(info.types[36].aliases[0], "__once_flag");
	
	info.types[37].ID = 24951;
	info.types[37].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[37].name = "";
	info.types[37].aliases = malloc(1 * sizeof(char *));
	info.types[37].aliases[0] = malloc(20);
	strcpy(info.types[37].aliases[0], "pthread_mutexattr_t");
	
	info.types[38].ID = 25033;
	info.types[38].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[38].name = "";
	info.types[38].aliases = malloc(1 * sizeof(char *));
	info.types[38].aliases[0] = malloc(19);
	strcpy(info.types[38].aliases[0], "pthread_condattr_t");
	
	info.types[39].ID = 25151;
	info.types[39].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[39].name = "union pthread_attr_t";
	info.types[39].aliases = malloc(1 * sizeof(char *));
	info.types[39].aliases[0] = malloc(15);
	strcpy(info.types[39].aliases[0], "pthread_attr_t");
	
	info.types[40].ID = 25235;
	info.types[40].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[40].name = "";
	info.types[40].aliases = malloc(1 * sizeof(char *));
	info.types[40].aliases[0] = malloc(16);
	strcpy(info.types[40].aliases[0], "pthread_mutex_t");
	
	info.types[41].ID = 25373;
	info.types[41].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[41].name = "";
	info.types[41].aliases = malloc(1 * sizeof(char *));
	info.types[41].aliases[0] = malloc(15);
	strcpy(info.types[41].aliases[0], "pthread_cond_t");
	
	info.types[42].ID = 25499;
	info.types[42].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[42].name = "";
	info.types[42].aliases = malloc(1 * sizeof(char *));
	info.types[42].aliases[0] = malloc(17);
	strcpy(info.types[42].aliases[0], "pthread_rwlock_t");
	
	info.types[43].ID = 25625;
	info.types[43].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[43].name = "";
	info.types[43].aliases = malloc(1 * sizeof(char *));
	info.types[43].aliases[0] = malloc(21);
	strcpy(info.types[43].aliases[0], "pthread_rwlockattr_t");
	
	info.types[44].ID = 25727;
	info.types[44].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[44].name = "";
	info.types[44].aliases = malloc(1 * sizeof(char *));
	info.types[44].aliases[0] = malloc(18);
	strcpy(info.types[44].aliases[0], "pthread_barrier_t");
	
	info.types[45].ID = 25815;
	info.types[45].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[45].name = "";
	info.types[45].aliases = malloc(1 * sizeof(char *));
	info.types[45].aliases[0] = malloc(22);
	strcpy(info.types[45].aliases[0], "pthread_barrierattr_t");
	
	info.types[46].ID = 26199;
	info.types[46].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[46].name = "struct random_data";
	info.types[46].aliases = malloc(0 * sizeof(char *));
	
	info.types[47].ID = 27689;
	info.types[47].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[47].name = "struct drand48_data";
	info.types[47].aliases = malloc(0 * sizeof(char *));
	
	info.types[48].ID = 36563;
	info.types[48].filename = "/home/randompigyt/Reflection/testFiles/null.c";
	info.types[48].name = "struct hi";
	info.types[48].aliases = malloc(0 * sizeof(char *));
	
	return info;
}
