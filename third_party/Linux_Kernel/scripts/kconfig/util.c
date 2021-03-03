#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "lkc.h"
void str_free(struct gstr *gs)
{
	if (gs->s)
		free(gs->s);
	gs->s = NULL;
	gs->len = 0;
}
void *xmalloc(size_t size)
{
	void *p = malloc(size);
	if (p)
		return p;
	fprintf(stderr, "Out of memory.\n");
	exit(1);
}
void *xcalloc(size_t nmemb, size_t size)
{
	void *p = calloc(nmemb, size);
	if (p)
		return p;
	fprintf(stderr, "Out of memory.\n");
	exit(1);
}
