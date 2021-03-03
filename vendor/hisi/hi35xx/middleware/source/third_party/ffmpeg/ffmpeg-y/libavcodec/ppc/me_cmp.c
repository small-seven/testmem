#include "config.h"
#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "libavutil/ppc/cpu.h"
#include "libavutil/ppc/util_altivec.h"
#include "libavcodec/avcodec.h"
#include "libavcodec/mpegvideo.h"
#include "libavcodec/me_cmp.h"
#if HAVE_ALTIVEC
#if HAVE_BIGENDIAN
#define GET_PERM(per1, per2, pix) {\
#define LOAD_PIX(v, iv, pix, per1, per2) {\
#else
#define GET_PERM(per1, per2, pix) {}
#define LOAD_PIX(v, iv, pix, per1, per2) {\
#endif
#define ONEITERBUTTERFLY(i, res)                                            \
#undef ONEITERBUTTERFLY
#define ONEITERBUTTERFLY(i, res1, res2)                                     \
#undef ONEITERBUTTERFLY
#endif /* HAVE_ALTIVEC */
#if HAVE_ALTIVEC
#endif /* HAVE_ALTIVEC */
