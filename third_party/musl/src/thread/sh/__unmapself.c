#include "pthread_impl.h"
#if !defined(__SH3__) && !defined(__SH4__)
#define __unmapself __unmapself_sh_nommu
#include "dynlink.h"
#undef CRTJMP
#define CRTJMP(pc,sp) __asm__ __volatile__( \
#include "../__unmapself.c"
#undef __unmapself
#else
#define __sh_nommu 0
#endif
