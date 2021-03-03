#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "libavutil/x86/cpu.h"
#include "libavutil/x86/asm.h"
#include "libavcodec/vc1dsp.h"
#include "fpel.h"
#include "vc1dsp.h"
#include "config.h"
#define LOOP_FILTER(EXT) \
#if HAVE_X86ASM
#define DECLARE_FUNCTION(OP, DEPTH, INSN)                       \
#endif /* HAVE_X86ASM */
#define ASSIGN_LF(EXT) \
#if HAVE_X86ASM
#endif /* HAVE_X86ASM */
