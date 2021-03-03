#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "libavutil/cpu.h"
#include "libavutil/bswap.h"
#include "config.h"
#include "rgb2rgb.h"
#include "swscale.h"
#include "swscale_internal.h"
#include "libavutil/pixdesc.h"
#define LOADCHROMA(i)                               \
#define PUTRGB(dst, src, i)                         \
#define PUTRGB24(dst, src, i)                       \
#define PUTBGR24(dst, src, i)                       \
#define PUTRGBA(dst, ysrc, asrc, i, s)                                  \
#define PUTRGB48(dst, src, i)                       \
#define PUTBGR48(dst, src, i)                       \
#define YUV2RGBFUNC(func_name, dst_type, alpha)                             \
#define ENDYUV2RGBLINE(dst_delta, ss)               \
#define ENDYUV2RGBFUNC()                            \
#define CLOSEYUV2RGBFUNC(dst_delta)                 \
#if HAVE_BIGENDIAN
#else
#endif
#if HAVE_BIGENDIAN
#else
#endif
#define PUTRGB16(dst, src, i, o)                    \
#define PUTRGB15(dst, src, i, o)                    \
#define PUTRGB12(dst, src, i, o)                    \
#define PUTRGB8(dst, src, i, o)                     \
#define PUTRGB4D(dst, src, i, o)                    \
#define PUTRGB4DB(dst, src, i, o)                   \
#define PUTRGB1(out, src, i, o)                     \
#define ALLOC_YUV_TABLE(x)          \
