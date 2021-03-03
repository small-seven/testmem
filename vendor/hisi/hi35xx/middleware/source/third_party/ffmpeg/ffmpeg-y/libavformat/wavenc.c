#include <stdint.h>
#include <string.h>
#include "libavutil/avstring.h"
#include "libavutil/dict.h"
#include "libavutil/common.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "libavutil/time.h"
#include "libavutil/time_internal.h"
#include "avformat.h"
#include "avio.h"
#include "avio_internal.h"
#include "internal.h"
#include "riff.h"
#define RF64_AUTO   (-1)
#define RF64_NEVER  0
#define RF64_ALWAYS 1
#define PEAK_BUFFER_SIZE   1024
typedef enum {
    PEAK_OFF = 0,
    PEAK_ON,
    PEAK_ONLY
} PeakType;
typedef enum {
    PEAK_FORMAT_UINT8 = 1,
    PEAK_FORMAT_UINT16
} PeakFormat;
typedef struct WAVMuxContext {
    const AVClass *class;
    int64_t data;
    int64_t fact_pos;
    int64_t ds64;
    int64_t minpts;
    int64_t maxpts;
    int16_t *peak_maxpos, *peak_maxneg;
    uint32_t peak_num_frames;
    uint32_t peak_outbuf_size;
    uint32_t peak_outbuf_bytes;
    uint8_t *peak_output;
    int last_duration;
    int write_bext;
    int write_peak;
    int rf64;
    int peak_block_size;
    int peak_format;
    int peak_block_pos;
    int peak_ppv;
    int peak_bps;
} WAVMuxContext;
#if CONFIG_WAV_MUXER
#define OFFSET(x) offsetof(WAVMuxContext, x)
#define ENC AV_OPT_FLAG_ENCODING_PARAM
#endif /* CONFIG_WAV_MUXER */
#if CONFIG_W64_MUXER
#include "w64.h"
#endif /* CONFIG_W64_MUXER */
