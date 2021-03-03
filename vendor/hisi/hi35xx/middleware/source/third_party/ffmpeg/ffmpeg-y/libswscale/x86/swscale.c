#include <inttypes.h>
#include "config.h"
#include "libswscale/swscale.h"
#include "libswscale/swscale_internal.h"
#include "libavutil/attributes.h"
#include "libavutil/avassert.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/x86/cpu.h"
#include "libavutil/cpu.h"
#include "libavutil/pixdesc.h"
#if HAVE_INLINE_ASM
#define DITHER1XBPP
#if HAVE_MMX_INLINE
#undef RENAME
#define COMPILE_TEMPLATE_MMXEXT 0
#define RENAME(a) a ## _mmx
#include "swscale_template.c"
#endif
#if HAVE_MMXEXT_INLINE
#undef RENAME
#undef COMPILE_TEMPLATE_MMXEXT
#define COMPILE_TEMPLATE_MMXEXT 1
#define RENAME(a) a ## _mmxext
#include "swscale_template.c"
#endif
#if HAVE_MMXEXT
#define MAIN_FUNCTION \
#endif
#endif /* HAVE_INLINE_ASM */
#define SCALE_FUNC(filter_n, from_bpc, to_bpc, opt) \
#define SCALE_FUNCS(filter_n, opt) \
#define SCALE_FUNCS_MMX(opt) \
#define SCALE_FUNCS_SSE(opt) \
#if ARCH_X86_32
#endif
#define VSCALEX_FUNC(size, opt) \
#define VSCALEX_FUNCS(opt) \
#if ARCH_X86_32
#endif
#define VSCALE_FUNC(size, opt) \
#define VSCALE_FUNCS(opt1, opt2) \
#if ARCH_X86_32
#endif
#define INPUT_Y_FUNC(fmt, opt) \
#define INPUT_UV_FUNC(fmt, opt) \
#define INPUT_FUNC(fmt, opt) \
#define INPUT_FUNCS(opt) \
#if ARCH_X86_32
#endif
#if HAVE_MMX_INLINE
#endif
#if HAVE_MMXEXT_INLINE
#endif
#define ASSIGN_SCALE_FUNC2(hscalefn, filtersize, opt1, opt2) do { \
#define ASSIGN_MMX_SCALE_FUNC(hscalefn, filtersize, opt1, opt2) \
#define ASSIGN_VSCALEX_FUNC(vscalefn, opt, do_16_case, condition_8bit) \
#define ASSIGN_VSCALE_FUNC(vscalefn, opt1, opt2, opt2chk) \
#define case_rgb(x, X, opt) \
#if ARCH_X86_32
#endif /* ARCH_X86_32 */
#define ASSIGN_SSE_SCALE_FUNC(hscalefn, filtersize, opt1, opt2) \
