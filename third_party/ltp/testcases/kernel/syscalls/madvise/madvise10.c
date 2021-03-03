#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include "lapi/mmap.h"
#include "tst_test.h"
#include "tst_safe_macros.h"
#define MAP_SIZE (16 * 1024)
static char *mem_map(void)
{
	char *ptr;

	ptr = SAFE_MMAP(NULL, MAP_SIZE,
			PROT_READ | PROT_WRITE,
			MAP_PRIVATE | MAP_ANONYMOUS,
			-1, 0);

	memcpy(ptr, pattern, MAP_SIZE);

	return ptr;
}
