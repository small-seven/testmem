#include "../swscale_internal.h"
#include "libavutil/x86/asm.h"
#include "libavutil/x86/cpu.h"
#define RET 0xC3 // near return opcode for x86
#define PREFETCH "prefetchnta"
#if HAVE_INLINE_ASM
#if ARCH_X86_64
#else
#if !HAVE_EBX_AVAILABLE
#endif
#endif
#if ARCH_X86_64
#else
#if !HAVE_EBX_AVAILABLE
#endif
#endif
#if ARCH_X86_64
#define CALL_MMXEXT_FILTER_CODE \
#else
#define CALL_MMXEXT_FILTER_CODE \
#endif /* ARCH_X86_64 */
#if ARCH_X86_64
#else
#if !HAVE_EBX_AVAILABLE
#endif
#endif
#if ARCH_X86_64
#else
#if !HAVE_EBX_AVAILABLE
#endif
#endif
#if ARCH_X86_64 || HAVE_EBX_AVAILABLE
#endif
#if ARCH_X86_64
#else
#if !HAVE_EBX_AVAILABLE
#endif
#endif
#if ARCH_X86_64
#else
#if !HAVE_EBX_AVAILABLE
#endif
#endif
#if ARCH_X86_64
#else
#if !HAVE_EBX_AVAILABLE
#endif
#endif
#if ARCH_X86_64
#else
#if !HAVE_EBX_AVAILABLE
#endif
#endif
#if ARCH_X86_64 || HAVE_EBX_AVAILABLE
#endif
#endif //HAVE_INLINE_ASM
