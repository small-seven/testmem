#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "tst_test.h"
#if defined(__powerpc64__) || defined(__powerpc__)
# ifndef PPC_FEATURE_TRUE_LE
# define PPC_FEATURE_TRUE_LE              0x00000002
# endif
# define TST_NO_DEFAULT_MAIN
#else /* defined (__powerpc64__) || (__powerpc__) */
#endif
