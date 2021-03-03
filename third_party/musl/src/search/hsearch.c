#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include <search.h>
#define MINSIZE 8
#define MAXSIZE ((size_t)-1/2 + 1)
void hdestroy(void)
{
	__hdestroy_r(&htab);
}
