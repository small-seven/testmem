#include <math.h>
#include <string.h>
#include "checkasm.h"
#include "libavcodec/vp9data.h"
#include "libavcodec/vp9.h"
#include "libavutil/common.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/mathematics.h"
#define SIZEOF_PIXEL ((bit_depth + 7) / 8)
#define randomize_buffers()                                        \
#undef randomize_buffers
#define randomize_buffers() \
typedef void (*ftx1d_fn)(double *out, const double *in, int sz);
static void ftx_2d(double *out, const double *in, enum TxfmMode tx,
                   enum TxfmType txtp, int sz)
{
    static const double scaling_factors[5][4] = {
        { 4.0, 16.0 * M_SQRT1_2 / 3.0, 16.0 * M_SQRT1_2 / 3.0, 32.0 / 9.0 },
#define SIZEOF_COEF (2 * ((bit_depth + 7) / 8))
#undef randomize_buffers
#define setpx(a,b,c) \
#define setdx(a,b,c,d) setpx(a,b,c-(d)+(rnd()%((d)*2+1)))
#define setsx(a,b,c,d) setdx(a,b,c,(d) << (bit_depth - 8))
#define randomize_buffers(bidx, lineoff, str) \
#define M(a) (((a)[1] << 8) | (a)[0])
#undef M
#undef setsx
#undef setpx
#undef setdx
#undef randomize_buffers
#define DST_BUF_SIZE (size * size * SIZEOF_PIXEL)
#define SRC_BUF_STRIDE 72
#define SRC_BUF_SIZE ((size + 7) * SRC_BUF_STRIDE * SIZEOF_PIXEL)
#define src (buf + 3 * SIZEOF_PIXEL * (SRC_BUF_STRIDE + 1))
#define randomize_buffers()                               \
