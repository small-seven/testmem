#include <string.h>
#include "libavcodec/avcodec.h"
#include "libavcodec/vp8dsp.h"
#include "libavutil/common.h"
#include "libavutil/intreadwrite.h"
#include "checkasm.h"
#define PIXEL_STRIDE 16
#define randomize_buffers(src, dst, stride, coef)                            \
#define SRC_BUF_STRIDE 32
#define SRC_BUF_SIZE (((size << (size < 16)) + 5) * SRC_BUF_STRIDE)
#define src (buf + 2 * SRC_BUF_STRIDE + 2 + 1)
#undef randomize_buffers
#define randomize_buffers()                               \
#undef randomize_buffers
#define setpx(a, b, c) buf[(a) + (b) * jstride] = av_clip_uint8(c)
#define setdx(a, b, c, d) setpx(a, b, c - (d) + (rnd() % ((d) * 2 + 1)))
#define setdx2(a, b, o, c, d, e) setpx(a, b, o = c + ((d) + (rnd() % (e))) * (c >= 128 ? -1 : 1))
#define randomize_buffers(buf, lineoff, str, force_hev) \
