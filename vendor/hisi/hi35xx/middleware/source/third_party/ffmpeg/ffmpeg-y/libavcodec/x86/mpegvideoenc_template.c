#include <stdint.h>
#include "libavutil/internal.h"
#include "libavutil/x86/asm.h"
#include "libavcodec/mpegutils.h"
#include "libavcodec/mpegvideo.h"
#include "fdct.h"
#undef MMREG_WIDTH
#undef MM
#undef MOVQ
#undef SPREADW
#undef PMAXW
#undef PMAX
#undef SAVE_SIGN
#undef RESTORE_SIGN
#if COMPILE_TEMPLATE_SSE2
#define MMREG_WIDTH "16"
#define MM "%%xmm"
#define MOVQ "movdqa"
#define SPREADW(a) \
#define PMAXW(a,b) "pmaxsw "a", "b"     \n\t"
#define PMAX(a,b) \
#else
#define MMREG_WIDTH "8"
#define MM "%%mm"
#define MOVQ "movq"
#if COMPILE_TEMPLATE_MMXEXT
#define SPREADW(a) "pshufw $0, "a", "a" \n\t"
#define PMAXW(a,b) "pmaxsw "a", "b"     \n\t"
#define PMAX(a,b) \
#else
#define SPREADW(a) \
#define PMAXW(a,b) \
#define PMAX(a,b)  \
#endif
#endif
#if COMPILE_TEMPLATE_SSSE3
#define SAVE_SIGN(a,b) \
#define RESTORE_SIGN(a,b) \
#else
#define SAVE_SIGN(a,b) \
#define RESTORE_SIGN(a,b) \
#endif
#if COMPILE_TEMPLATE_SSE2
#endif
