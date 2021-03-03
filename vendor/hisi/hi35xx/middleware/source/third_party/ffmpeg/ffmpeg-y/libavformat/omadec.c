#include <inttypes.h>
#include "libavutil/channel_layout.h"
#include "avformat.h"
#include "internal.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/des.h"
#include "libavutil/mathematics.h"
#include "oma.h"
#include "pcm.h"
#include "id3v2.h"
typedef struct OMAContext {
    uint64_t content_start;
    int encrypted;
    uint16_t k_size;
    uint16_t e_size;
    uint16_t i_size;
    uint16_t s_size;
    uint32_t rid;
    uint8_t r_val[24];
    uint8_t n_val[24];
    uint8_t m_val[8];
    uint8_t s_val[8];
    uint8_t sm_val[8];
    uint8_t e_val[8];
    uint8_t iv[8];
    struct AVDES *av_des;

    int (*read_packet)(AVFormatContext *s, AVPacket *pkt);
} OMAContext;
#define OMA_RPROBE_M_VAL 48 + 1
