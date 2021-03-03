#include <common.h>
#include <asm/io.h>
#include <asm/lapic.h>
#include <asm/msr.h>
#include <asm/msr-index.h>
#include <asm/post.h>
#define xchg(ptr, v)	((__typeof__(*(ptr)))__xchg((unsigned long)(v), (ptr), \
#define __xg(x)		((struct __xchg_dummy *)(x))
