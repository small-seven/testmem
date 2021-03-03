#include "pthread_impl.h"
#include "libc.h"
#include <elf.h>
#define CPU_HAS_LLSC 0x0040
#define CPU_HAS_CAS_L 0x0400
#ifndef __SH4A__
#if !defined(__SH3__) && !defined(__SH4__)
#endif
#endif
