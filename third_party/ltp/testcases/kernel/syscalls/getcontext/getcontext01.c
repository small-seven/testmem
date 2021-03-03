#include <features.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <ucontext.h>
#include "test.h"
#if !defined(__UCLIBC__)
#else /* systems that dont support obsolete getcontext */
#endif
