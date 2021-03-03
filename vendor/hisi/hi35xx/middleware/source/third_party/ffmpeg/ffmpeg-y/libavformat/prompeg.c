#include "libavutil/avstring.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "libavutil/random_seed.h"
#include "avformat.h"
#include "config.h"
#include "url.h"
#define PROMPEG_RTP_PT 0x60
#define PROMPEG_FEC_COL 0x0
#define PROMPEG_FEC_ROW 0x1
typedef struct PrompegFec {
    uint16_t sn;
    uint32_t ts;
    uint8_t *bitstring;
} PrompegFec;
typedef struct PrompegContext {
    const AVClass *class;
    URLContext *fec_col_hd, *fec_row_hd;
    PrompegFec **fec_arr, **fec_col_tmp, **fec_col, *fec_row;
    int ttl;
    uint8_t l, d;
    uint8_t *rtp_buf;
    uint16_t rtp_col_sn, rtp_row_sn;
    uint16_t length_recovery;
    int packet_size;
    int packet_idx, packet_idx_max;
    int fec_arr_len;
    int bitstring_size;
    int rtp_buf_size;
    int init;
    int first;
} PrompegContext;
#define OFFSET(x) offsetof(PrompegContext, x)
#define E AV_OPT_FLAG_ENCODING_PARAM
#if HAVE_FAST_64BIT
#else
#endif
