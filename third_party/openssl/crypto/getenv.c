#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif
#include <stdlib.h>
#include "internal/cryptlib.h"
#if defined(__GLIBC__) && defined(__GLIBC_PREREQ)
# if __GLIBC_PREREQ(2, 17)
#  define SECURE_GETENV
# endif
#endif
#ifndef SECURE_GETENV
#endif
