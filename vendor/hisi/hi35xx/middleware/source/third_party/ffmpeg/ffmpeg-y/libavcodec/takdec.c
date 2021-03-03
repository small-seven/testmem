#include "libavutil/internal.h"
#include "libavutil/samplefmt.h"
#define BITSTREAM_READER_LE
#include "audiodsp.h"
#include "thread.h"
#include "avcodec.h"
#include "internal.h"
#include "unary.h"
#include "tak.h"
#include "takdsp.h"
#define MAX_SUBFRAMES     8                         ///< max number of subframes per channel
#define MAX_PREDICTORS  256
typedef struct MCDParam {
    int8_t present;                                 ///< decorrelation parameter availability for this channel
    int8_t index;                                   ///< index into array of decorrelation types
    int8_t chan1;
    int8_t chan2;
} MCDParam;
typedef struct TAKDecContext {
    AVCodecContext *avctx;                          ///< parent AVCodecContext
    AudioDSPContext adsp;
    TAKDSPContext   tdsp;
    TAKStreamInfo   ti;
    GetBitContext   gb;                             ///< bitstream reader initialized to start at the current frame

    int             uval;
    int             nb_samples;                     ///< number of samples in the current frame
    uint8_t        *decode_buffer;
    unsigned int    decode_buffer_size;
    int32_t        *decoded[TAK_MAX_CHANNELS];      ///< decoded samples for each channel

    int8_t          lpc_mode[TAK_MAX_CHANNELS];
    int8_t          sample_shift[TAK_MAX_CHANNELS]; ///< shift applied to every sample in the channel
    int16_t         predictors[MAX_PREDICTORS];
    int             nb_subframes;                   ///< number of subframes in the current frame
    int16_t         subframe_len[MAX_SUBFRAMES];    ///< subframe length in samples
    int             subframe_scale;

    int8_t          dmode;                          ///< channel decorrelation type in the current frame

    MCDParam        mcdparams[TAK_MAX_CHANNELS];    ///< multichannel decorrelation parameters

    int8_t          coding_mode[128];
    DECLARE_ALIGNED(16, int16_t, filter)[MAX_PREDICTORS];
    DECLARE_ALIGNED(16, int16_t, residues)[544];
} TAKDecContext;
#if HAVE_THREADS
#endif
