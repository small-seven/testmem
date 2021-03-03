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
#define R(r) { .name = "PT_" #r, .off = PT_##r },
#ifdef __bfin__
#endif
#ifdef HAVE_STRUCT_PTRACE_REGS
#else
#endif
