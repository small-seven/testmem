#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/mount.h>
#include <sys/xattr.h>
#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <limits.h>
#include <pwd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>
#include "test.h"
#include "safe_macros.h"
void *safe_malloc(const char *file, const int lineno, void (*cleanup_fn) (void),
		  size_t size)
{
	void *rval;

	rval = malloc(size);
	if (rval == NULL) {
		tst_brkm(TBROK | TERRNO, cleanup_fn,
			 "%s:%d: malloc(%zu) failed",
			 file, lineno, size);
	}

	return rval;
}
void *safe_memalign(const char *file, const int lineno,
		    void (*cleanup_fn) (void), size_t alignment, size_t size)
{
	void *rval;

	rval = memalign(alignment, size);
	if (rval == NULL)
		tst_brkm(TBROK | TERRNO, cleanup_fn, "memalign failed at %s:%d",
			 file, lineno);

	return rval;
}
