#include "libavutil/channel_layout.h"
#include "libavutil/mem.h"
#include "libavutil/opt.h"
#define BITSTREAM_READER_LE
#include "acelp_vectors.h"
#include "avcodec.h"
#include "celp_filters.h"
#include "celp_math.h"
#include "get_bits.h"
#include "internal.h"
#include "g723_1.h"
#define CNG_RANDOM_SEED 12345
#define iir_filter(fir_coef, iir_coef, src, dest, width)\
#define OFFSET(x) offsetof(G723_1_Context, x)
#define AD     AV_OPT_FLAG_AUDIO_PARAM | AV_OPT_FLAG_DECODING_PARAM
