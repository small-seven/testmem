#include <stdint.h>
#include "libavutil/attributes.h"
#include "libavutil/fifo.h"
#include "libavutil/log.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "libavcodec/put_bits.h"
#include "avformat.h"
#include "internal.h"
#include "mpeg.h"
#define MAX_PAYLOAD_SIZE 4096
typedef struct PacketDesc {
    int64_t pts;
    int64_t dts;
    int size;
    int unwritten_size;
    struct PacketDesc *next;
} PacketDesc;
typedef struct StreamInfo {
    AVFifoBuffer *fifo;
    uint8_t id;
    int max_buffer_size; /* in bytes */
    int buffer_index;
    PacketDesc *predecode_packet;
    PacketDesc *premux_packet;
    PacketDesc **next_packet;
    int packet_number;
    uint8_t lpcm_header[3];
    int lpcm_align;
    int bytes_to_iframe;
    int align_iframe;
    int64_t vobu_start_pts;
} StreamInfo;
typedef struct MpegMuxContext {
    const AVClass *class;
    int packet_size; /* required packet size */
    int packet_number;
    int pack_header_freq;     /* frequency (in packets^-1) at which we send pack headers */
    int system_header_freq;
    int system_header_size;
    int user_mux_rate; /* bitrate in units of bits/s */
    int mux_rate; /* bitrate in units of 50 bytes/s */
    /* stream info */
    int audio_bound;
    int video_bound;
    int is_mpeg2;
    int is_vcd;
    int is_svcd;
    int is_dvd;
    int64_t last_scr; /* current system clock */

    int64_t vcd_padding_bitrate_num;
    int64_t vcd_padding_bytes_written;

    int preload;
} MpegMuxContext;
#define VCD_PADDING_BITRATE_DEN (2279 * 2294)
#define OFFSET(x) offsetof(MpegMuxContext, x)
#define E AV_OPT_FLAG_ENCODING_PARAM
#define MPEGENC_CLASS(flavor)                   \
#if CONFIG_MPEG1SYSTEM_MUXER
#endif
#if CONFIG_MPEG1VCD_MUXER
#endif
#if CONFIG_MPEG2VOB_MUXER
#endif
#if CONFIG_MPEG2SVCD_MUXER
#endif
#if CONFIG_MPEG2DVD_MUXER
#endif
