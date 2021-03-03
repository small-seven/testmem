#include <malloc.h>
#include <common.h>
#include "biosemui.h"
#define OFF(addr)	(u16)(((addr) >> 0) & 0xffff)
#define SEG(addr)	(u16)(((addr) >> 4) & 0xf000)
#if !defined(__DRIVER__)  && !defined(__KERNEL__)
#endif
#ifdef __KERNEL__
#else
#endif
#ifdef __KERNEL__
#else
#endif
