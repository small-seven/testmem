#define _XOPEN_SOURCE 600
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <libcrystalhd/bc_dts_types.h>
#include <libcrystalhd/bc_dts_defs.h>
#include <libcrystalhd/libcrystalhd_if.h>
#include "avcodec.h"
#include "decode.h"
#include "internal.h"
#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#define OUTPUT_PROC_TIMEOUT 50
#define TIMESTAMP_UNIT 100000
typedef enum {
    RET_ERROR           = -1,
    RET_OK              = 0,
    RET_COPY_AGAIN      = 1,
} CopyRet;
typedef struct OpaqueList {
    struct OpaqueList *next;
    uint64_t fake_timestamp;
    uint64_t reordered_opaque;
} OpaqueList;
typedef struct {
    AVClass *av_class;
    AVCodecContext *avctx;
    HANDLE dev;

    uint8_t is_70012;
    uint8_t need_second_field;
    uint8_t draining;

    OpaqueList *head;
    OpaqueList *tail;

    /* Options */
    uint32_t sWidth;
} CHDContext;
#if FF_API_PKT_PTS
#endif
#define DEFINE_CRYSTALHD_DECODER(x, X, bsf_name) \
#if CONFIG_H264_CRYSTALHD_DECODER
#endif
#if CONFIG_MPEG2_CRYSTALHD_DECODER
#endif
#if CONFIG_MPEG4_CRYSTALHD_DECODER
#endif
#if CONFIG_MSMPEG4_CRYSTALHD_DECODER
#endif
#if CONFIG_VC1_CRYSTALHD_DECODER
#endif
#if CONFIG_WMV3_CRYSTALHD_DECODER
#endif
