#include "config.h"
#include <signal.h>
#include <setjmp.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/mman.h>
#include <stdlib.h>
#include "test.h"
#include "safe_macros.h"
typedef void (*func_ptr_t)(void);

int main(int ac, char **av)
{
	int lc;
	int i;

	tst_parse_opts(ac, av, NULL, NULL);

	setup();

	for (lc = 0; TEST_LOOPING(lc); lc++) {
		tst_count = 0;

		for (i = 0; i < TST_TOTAL; i++)
			(*testfunc[i])();
	}
#if HAVE_BUILTIN_CLEAR_CACHE == 1
#else
#endif
#if defined(__powerpc64__) && (!defined(_CALL_ELF) || _CALL_ELF < 2)
#define USE_FUNCTION_DESCRIPTORS
#endif
#ifdef USE_FUNCTION_DESCRIPTORS
typedef struct {
	uintptr_t entry;
	uintptr_t toc;
	uintptr_t env;
} func_descr_t;
#endif
#ifdef USE_FUNCTION_DESCRIPTORS
#else
#endif
#ifdef USE_FUNCTION_DESCRIPTORS
#else
#endif
