#include "config.h"
#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "libavutil/x86/cpu.h"
#include "libavcodec/idctdsp.h"
#include "libavcodec/xvididct.h"
#include "idctdsp.h"
#include "xvididct.h"
#if ARCH_X86_32 && HAVE_X86ASM
#endif
#if HAVE_X86ASM
#if ARCH_X86_32
#endif
#endif /* HAVE_X86ASM */
