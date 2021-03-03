#include "avcodec.h"
#include "internal.h"
#include "bytestream.h"
#include "lossless_videoencdsp.h"
#include "png.h"
#include "apng.h"
#include "libavutil/avassert.h"
#include "libavutil/crc.h"
#include "libavutil/libm.h"
#include "libavutil/opt.h"
#include "libavutil/color_utils.h"
#include "libavutil/stereo3d.h"
#include <zlib.h>
#define IOBUF_SIZE 4096
typedef struct APNGFctlChunk {
    uint32_t sequence_number;
    uint32_t width, height;
    uint32_t x_offset, y_offset;
    uint16_t delay_num, delay_den;
    uint8_t dispose_op, blend_op;
} APNGFctlChunk;
typedef struct PNGEncContext {
    AVClass *class;
    LLVidEncDSPContext llvidencdsp;

    uint8_t *bytestream;
    uint8_t *bytestream_start;
    uint8_t *bytestream_end;

    int filter_type;

    z_stream zstream;
    uint8_t buf[IOBUF_SIZE];
    int dpi;                     ///< Physical pixel density, in dots per inch, if set
    int dpm;                     ///< Physical pixel density, in dots per meter, if set

    int is_progressive;
    int bit_depth;
    int color_type;
    int bits_per_pixel;

    // APNG
    uint32_t palette_checksum;   // Used to ensure a single unique palette
    uint32_t sequence_number;
    int extra_data_updated;
    uint8_t *extra_data;
    int extra_data_size;

    AVFrame *prev_frame;
    AVFrame *last_frame;
    APNGFctlChunk last_frame_fctl;
    uint8_t *last_frame_packet;
    size_t last_frame_packet_size;
} PNGEncContext;
#define AV_WB32_PNG(buf, n) AV_WB32(buf, lrint((n) * 100000))
#if FF_API_CODED_FRAME
#endif
#if FF_API_PRIVATE_OPT
#endif
#define OFFSET(x) offsetof(PNGEncContext, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
