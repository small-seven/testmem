#include <stddef.h>
#include "libavcodec/cabac.h"
#include "cabac.h"
#if HAVE_INLINE_ASM
#if ARCH_X86_64
#define REG64 "r"
#else
#define REG64 "m"
#endif
#if HAVE_7REGS && !BROKEN_COMPILER
#define decode_significance decode_significance_x86
#ifdef BROKEN_RELOCATIONS
#endif
#define decode_significance_8x8 decode_significance_8x8_x86
#ifdef BROKEN_RELOCATIONS
#endif
#ifdef BROKEN_RELOCATIONS
#else
#endif
#endif /* HAVE_7REGS && BROKEN_COMPILER */
#endif /* HAVE_INLINE_ASM */
