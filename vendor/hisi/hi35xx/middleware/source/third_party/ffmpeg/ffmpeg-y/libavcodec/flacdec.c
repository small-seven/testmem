#include <limits.h>
#include "libavutil/avassert.h"
#include "libavutil/crc.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "internal.h"
#include "get_bits.h"
#include "bytestream.h"
#include "golomb.h"
#include "flac.h"
#include "flacdata.h"
#include "flacdsp.h"
#include "thread.h"
#include "unary.h"
typedef struct FLACContext {
    AVClass *class;
    struct FLACStreaminfo flac_stream_info;

    AVCodecContext *avctx;                  ///< parent AVCodecContext
    GetBitContext gb;                       ///< GetBitContext initialized to start at the current frame

    int blocksize;                          ///< number of samples in the current frame
    int sample_shift;                       ///< shift required to make output samples 16-bit or 32-bit
    int ch_mode;                            ///< channel decorrelation type in the current frame
    int got_streaminfo;                     ///< indicates if the STREAMINFO has been read

    int32_t *decoded[FLAC_MAX_CHANNELS];    ///< decoded samples
    uint8_t *decoded_buffer;
    unsigned int decoded_buffer_size;
    int buggy_lpc;                          ///< use workaround for old lavc encoded files

    FLACDSPContext dsp;
} FLACContext;
#if HAVE_THREADS
#endif
