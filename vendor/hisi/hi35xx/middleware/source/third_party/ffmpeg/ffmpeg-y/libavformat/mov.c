#include <inttypes.h>
#include <limits.h>
#include <stdint.h>
#include "libavutil/attributes.h"
#include "libavutil/channel_layout.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/intfloat.h"
#include "libavutil/mathematics.h"
#include "libavutil/time_internal.h"
#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/dict.h"
#include "libavutil/display.h"
#include "libavutil/opt.h"
#include "libavutil/aes.h"
#include "libavutil/aes_ctr.h"
#include "libavutil/pixdesc.h"
#include "libavutil/sha.h"
#include "libavutil/spherical.h"
#include "libavutil/stereo3d.h"
#include "libavutil/timecode.h"
#include "libavcodec/ac3tab.h"
#include "libavcodec/flac.h"
#include "libavcodec/mpegaudiodecheader.h"
#include "avformat.h"
#include "internal.h"
#include "avio_internal.h"
#include "riff.h"
#include "isom.h"
#include "libavcodec/get_bits.h"
#include "id3v1.h"
#include "mov_chan.h"
#include "replaygain.h"
#if CONFIG_ZLIB
#include <zlib.h>
#endif
#include "qtpalette.h"
typedef struct MOVParseTableEntry {
    uint32_t type;
    int (*parse)(MOVContext *ctx, AVIOContext *pb, MOVAtom atom);
} MOVParseTableEntry;
#define MIN_DATA_ENTRY_BOX_SIZE 12
#if FF_API_LAVF_AVCTX
#endif
#if FF_API_LAVF_AVCTX
#endif
#define DRM_BLOB_SIZE 56
#define ALAC_EXTRADATA_SIZE 36
#if FF_API_LAVF_AVCTX
#endif
#if FF_API_LAVF_AVCTX
#endif
#if CONFIG_DV_DEMUXER
#endif
#define MAX_REORDER_DELAY 16
#if FF_API_R_FRAME_RATE
#endif
#if CONFIG_H261_DECODER
#endif
#if CONFIG_H263_DECODER
#endif
#if CONFIG_MPEG4_DECODER
#endif
#define IS_MATRIX_IDENT(matrix)            \
#if FF_API_OLD_ROTATE_API
#endif
#if CONFIG_ZLIB
#else
#endif
static int mov_read_free(MOVContext *c, AVIOContext *pb, MOVAtom atom)
{
    int ret;
    uint8_t content[16];

    if (atom.size < 8)
        return 0;

    ret = avio_read(pb, content, FFMIN(sizeof(content), atom.size));
    if (ret < 0)
        return ret;

    if (   !c->found_moov
        && !c->found_mdat
        && !memcmp(content, "Anevia\x1A\x1A", 8)
        && c->use_mfra_for == FF_MOV_FLAG_MFRA_AUTO) {
        c->use_mfra_for = FF_MOV_FLAG_MFRA_PTS;
    }

    return 0;
}
#if CONFIG_DV_DEMUXER
#endif
#define OFFSET(x) offsetof(MOVContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_DECODING_PARAM
