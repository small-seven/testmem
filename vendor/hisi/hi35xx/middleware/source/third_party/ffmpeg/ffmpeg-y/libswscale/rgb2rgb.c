#include <inttypes.h>
#include "libavutil/attributes.h"
#include "libavutil/bswap.h"
#include "config.h"
#include "rgb2rgb.h"
#include "swscale.h"
#include "swscale_internal.h"
#define BY ((int)( 0.098 * (1 << RGB2YUV_SHIFT) + 0.5))
#define BV ((int)(-0.071 * (1 << RGB2YUV_SHIFT) + 0.5))
#define BU ((int)( 0.439 * (1 << RGB2YUV_SHIFT) + 0.5))
#define GY ((int)( 0.504 * (1 << RGB2YUV_SHIFT) + 0.5))
#define GV ((int)(-0.368 * (1 << RGB2YUV_SHIFT) + 0.5))
#define GU ((int)(-0.291 * (1 << RGB2YUV_SHIFT) + 0.5))
#define RY ((int)( 0.257 * (1 << RGB2YUV_SHIFT) + 0.5))
#define RV ((int)( 0.439 * (1 << RGB2YUV_SHIFT) + 0.5))
#define RU ((int)(-0.148 * (1 << RGB2YUV_SHIFT) + 0.5))
#include "rgb2rgb_template.c"
#if HAVE_BIGENDIAN
#else
#endif
#if HAVE_BIGENDIAN
#else
#endif
#if HAVE_BIGENDIAN
#else
#endif
#if HAVE_BIGENDIAN
#else
#endif
#define DEFINE_RGB48TOBGR48(need_bswap, swap)                           \
#define DEFINE_RGB64TOBGR48(need_bswap, swap)                           \
#define DEFINE_RGB64TO48(need_bswap, swap)                              \
#define DEFINE_RGB48TOBGR64(need_bswap, swap)                           \
#define DEFINE_RGB48TO64(need_bswap, swap)                              \
