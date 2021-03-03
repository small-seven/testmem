#define _GNU_SOURCE
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <config.h>
#include "ptrace.h"
#include "test.h"
#include "spawn_ptrace_child.h"
#include "config.h"
#if defined(__i386__)
#define SIZEOF_USER 284
#elif defined(__x86_64__)
#define SIZEOF_USER 928
#else
#define SIZEOF_USER 0x1000	/* just pick a big number */
#endif
#ifdef PTRACE_GETREGS
#endif
#ifdef PTRACE_GETFGREGS
#endif
#ifdef PTRACE_SETREGS
#endif
#ifdef PTRACE_SETFGREGS
#endif
#if HAVE_DECL_PTRACE_GETSIGINFO
#endif
#if HAVE_DECL_PTRACE_SETSIGINFO
#endif
