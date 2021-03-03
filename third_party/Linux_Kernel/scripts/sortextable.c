#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <getopt.h>
#include <elf.h>
#include <fcntl.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <tools/be_byteshift.h>
#include <tools/le_byteshift.h>
#ifndef EM_ARCOMPACT
#define EM_ARCOMPACT	93
#endif
#ifndef EM_XTENSA
#define EM_XTENSA	94
#endif
#ifndef EM_AARCH64
#define EM_AARCH64	183
#endif
#ifndef EM_MICROBLAZE
#define EM_MICROBLAZE	189
#endif
#ifndef EM_ARCV2
#define EM_ARCV2	195
#endif
typedef void (*table_sort_t)(char *, int);

/*
 * Move reserved section indices SHN_LORESERVE..SHN_HIRESERVE out of
 * the way to -256..-1, to avoid conflicting with real section
 * indices.
 */
#define SPECIAL(i) ((i) - (SHN_HIRESERVE + 1))

static inline int is_shndx_special(unsigned int i)
{
	return i != SHN_XINDEX && i >= SHN_LORESERVE && i <= SHN_HIRESERVE;
}
#include "sortextable.h"
#define SORTEXTABLE_64
#include "sortextable.h"
