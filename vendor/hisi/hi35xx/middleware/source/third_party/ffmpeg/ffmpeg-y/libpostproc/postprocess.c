# more or less selfinvented filters so the exactness is not too meaningful
#include "config.h"
#include "libavutil/avutil.h"
#include "libavutil/avassert.h"
#include "libavutil/intreadwrite.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "postprocess.h"
#include "postprocess_internal.h"
#include "libavutil/avstring.h"
#include "libavutil/ppc/util_altivec.h"
#include "libavutil/ffversion.h"
#define LICENSE_PREFIX "libpostproc license: "
#define GET_MODE_BUFFER_SIZE 500
#define OPTIONS_ARRAY_SIZE 10
#define BLOCK_SIZE 8
#define TEMP_STRIDE 8
#if ARCH_X86 && HAVE_INLINE_ASM
#endif
#define TEMPLATE_PP_C 1
#include "postprocess_template.c"
#if HAVE_ALTIVEC
#   define TEMPLATE_PP_ALTIVEC 1
#   include "postprocess_altivec_template.c"
#   include "postprocess_template.c"
#endif
#if ARCH_X86 && HAVE_INLINE_ASM
#    if CONFIG_RUNTIME_CPUDETECT
#        define TEMPLATE_PP_MMX 1
#        include "postprocess_template.c"
#        define TEMPLATE_PP_MMXEXT 1
#        include "postprocess_template.c"
#        define TEMPLATE_PP_3DNOW 1
#        include "postprocess_template.c"
#        define TEMPLATE_PP_SSE2 1
#        include "postprocess_template.c"
#    else
#        if HAVE_SSE2_INLINE
#            define TEMPLATE_PP_SSE2 1
#            include "postprocess_template.c"
#        elif HAVE_MMXEXT_INLINE
#            define TEMPLATE_PP_MMXEXT 1
#            include "postprocess_template.c"
#        elif HAVE_AMD3DNOW_INLINE
#            define TEMPLATE_PP_3DNOW 1
#            include "postprocess_template.c"
#        elif HAVE_MMX_INLINE
#            define TEMPLATE_PP_MMX 1
#            include "postprocess_template.c"
#        endif
#    endif
#endif
typedef void (*pp_fn)(const uint8_t src[], int srcStride, uint8_t dst[], int dstStride, int width, int height,
                      const int8_t QPs[], int QPStride, int isColor, PPContext *c2);

static inline void postProcess(const uint8_t src[], int srcStride, uint8_t dst[], int dstStride, int width, int height,
        const int8_t QPs[], int QPStride, int isColor, pp_mode *vm, pp_context *vc)
{
    pp_fn pp = postProcess_C;
    PPContext *c= (PPContext *)vc;
    PPMode *ppMode= (PPMode *)vm;
    c->ppMode= *ppMode; //FIXME

    if (!(ppMode->lumMode & BITEXACT)) {
#if CONFIG_RUNTIME_CPUDETECT
#if ARCH_X86 && HAVE_INLINE_ASM
        // ordered per speed fastest first
        if      (c->cpuCaps & AV_CPU_FLAG_SSE2)     pp = postProcess_SSE2;
        else if (c->cpuCaps & AV_CPU_FLAG_MMXEXT)   pp = postProcess_MMX2;
        else if (c->cpuCaps & AV_CPU_FLAG_3DNOW)    pp = postProcess_3DNow;
        else if (c->cpuCaps & AV_CPU_FLAG_MMX)      pp = postProcess_MMX;
#elif HAVE_ALTIVEC
        if      (c->cpuCaps & AV_CPU_FLAG_ALTIVEC)  pp = postProcess_altivec;
#endif
#else /* CONFIG_RUNTIME_CPUDETECT */
#if     HAVE_SSE2_INLINE
        pp = postProcess_SSE2;
#elif   HAVE_MMXEXT_INLINE
        pp = postProcess_MMX2;
#elif HAVE_AMD3DNOW_INLINE
        pp = postProcess_3DNow;
#elif HAVE_MMX_INLINE
        pp = postProcess_MMX;
#elif HAVE_ALTIVEC
        pp = postProcess_altivec;
#endif
#endif /* !CONFIG_RUNTIME_CPUDETECT */
    }
