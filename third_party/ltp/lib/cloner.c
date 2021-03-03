#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sched.h>
#include <stdarg.h>
#include "config.h"
#include "tst_clone.h"
#undef clone			/* we want to use clone() */
#if defined(__ia64__)
#endif
#ifndef CLONE_SUPPORTS_7_ARGS
# define clone(fn, stack, flags, arg, ptid, tls, ctid) \
#endif
#if defined(__ia64__)
#else
# if defined(__hppa__) || defined(__metag__)
# else
# endif
#endif
#ifdef CLONE_SUPPORTS_7_ARGS
#else
#endif
