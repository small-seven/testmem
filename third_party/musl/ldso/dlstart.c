#include <stddef.h>
#include "dynlink.h"
#include "libc.h"
#ifndef START
#define START "_dlstart"
#endif
#define SHARED
#include "crt_arch.h"
#ifndef GETFUNCSYM
#define GETFUNCSYM(fp, sym, got) do { \
#endif
#if DL_FDPIC
#endif
#if DL_FDPIC
#else
#endif
