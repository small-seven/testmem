#include "libavutil/attributes.h"
#include "libavutil/float_dsp.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include "mathops.h"
#include "pcm_tablegen.h"
#define ENCODE(type, endian, src, dst, n, shift, offset)                \
#define ENCODE_PLANAR(type, endian, dst, n, shift, offset)              \
#if HAVE_BIGENDIAN
#else
#endif /* HAVE_BIGENDIAN */
#if HAVE_BIGENDIAN
#else
#endif /* HAVE_BIGENDIAN */
typedef struct PCMDecode {
    short   table[256];
    AVFloatDSPContext *fdsp;
    float   scale;
} PCMDecode;
#define DECODE(size, endian, src, dst, n, shift, offset)                \
#define DECODE_PLANAR(size, endian, src, dst, n, shift, offset)         \
#if HAVE_BIGENDIAN
#else
#endif /* HAVE_BIGENDIAN */
#if HAVE_BIGENDIAN
#else
#endif /* HAVE_BIGENDIAN */
#define PCM_ENCODER_0(id_, sample_fmt_, name_, long_name_)
#define PCM_ENCODER_1(id_, sample_fmt_, name_, long_name_)                  \
#define PCM_ENCODER_2(cf, id, sample_fmt, name, long_name)                  \
#define PCM_ENCODER_3(cf, id, sample_fmt, name, long_name)                  \
#define PCM_ENCODER(id, sample_fmt, name, long_name)                        \
#define PCM_DECODER_0(id, sample_fmt, name, long_name)
#define PCM_DECODER_1(id_, sample_fmt_, name_, long_name_)                  \
#define PCM_DECODER_2(cf, id, sample_fmt, name, long_name)                  \
#define PCM_DECODER_3(cf, id, sample_fmt, name, long_name)                  \
#define PCM_DECODER(id, sample_fmt, name, long_name)                        \
#define PCM_CODEC(id, sample_fmt_, name, long_name_)                    \
