#include "config.h"
#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "libavutil/ppc/cpu.h"
#include "libavutil/ppc/util_altivec.h"
#include "libavcodec/hevcdsp.h"
#if HAVE_ALTIVEC
#define FUNCDECL(a, depth) a ## _ ## depth ## _altivec
#define FUNC(a, b) FUNCDECL(a, b)
#define BIT_DEPTH 8
#include "hevcdsp_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 10
#include "hevcdsp_template.c"
#undef BIT_DEPTH
#endif /* HAVE_ALTIVEC */
#if HAVE_ALTIVEC
#endif /* HAVE_ALTIVEC */
