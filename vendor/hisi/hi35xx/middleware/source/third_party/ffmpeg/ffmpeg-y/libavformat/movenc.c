#include <stdint.h>
#include <inttypes.h>
#include "movenc.h"
#include "avformat.h"
#include "avio_internal.h"
#include "riff.h"
#include "avio.h"
#include "isom.h"
#include "av1.h"
#include "avc.h"
#include "libavcodec/ac3_parser_internal.h"
#include "libavcodec/dnxhddata.h"
#include "libavcodec/flac.h"
#include "libavcodec/get_bits.h"
#include "libavcodec/internal.h"
#include "libavcodec/put_bits.h"
#include "libavcodec/vc1_common.h"
#include "libavcodec/raw.h"
#include "internal.h"
#include "libavutil/avstring.h"
#include "libavutil/intfloat.h"
#include "libavutil/mathematics.h"
#include "libavutil/libm.h"
#include "libavutil/opt.h"
#include "libavutil/dict.h"
#include "libavutil/pixdesc.h"
#include "libavutil/stereo3d.h"
#include "libavutil/timecode.h"
#include "libavutil/color_utils.h"
#include "hevc.h"
#include "rtpenc.h"
#include "mov_chan.h"
#include "vpcc.h"
#define MOV_CLASS(flavor)\
#if CONFIG_AC3_PARSER
#endif
#if FF_API_LAVF_AVCTX
#endif
#if FF_API_LAVF_AVCTX
#endif
#if 1
#if FF_API_LAVF_AVCTX
#else
#endif
#else
#endif
#if FF_API_OLD_ROTATE_API
#endif
#if FF_API_OLD_ROTATE_API
#endif
#if CONFIG_AC3_PARSER
#endif
#if 0
#else
#endif
static void mov_free(AVFormatContext *s)
{
    MOVMuxContext *mov = s->priv_data;
    int i;

    if (mov->chapter_track) {
        if (mov->tracks[mov->chapter_track].par)
            av_freep(&mov->tracks[mov->chapter_track].par->extradata);
        av_freep(&mov->tracks[mov->chapter_track].par);
    }

    for (i = 0; i < mov->nb_streams; i++) {
        if (mov->tracks[i].tag == MKTAG('r','t','p',' '))
            ff_mov_close_hinting(&mov->tracks[i]);
        else if (mov->tracks[i].tag == MKTAG('t','m','c','d') && mov->nb_meta_tmcd)
            av_freep(&mov->tracks[i].par);
        av_freep(&mov->tracks[i].cluster);
        av_freep(&mov->tracks[i].frag_info);
        av_packet_unref(&mov->tracks[i].cover_image);

        if (mov->tracks[i].eac3_priv) {
            struct eac3_info *info = mov->tracks[i].eac3_priv;
            av_packet_unref(&info->pkt);
            av_freep(&mov->tracks[i].eac3_priv);
        }
        if (mov->tracks[i].vos_len)
            av_freep(&mov->tracks[i].vos_data);

        ff_mov_cenc_free(&mov->tracks[i].cenc);
    }

    av_freep(&mov->tracks);
}
#define READ_BLOCK do {                                                             \
#if CONFIG_MOV_MUXER
#endif
#if CONFIG_TGP_MUXER
#endif
#if CONFIG_MP4_MUXER
#endif
#if CONFIG_PSP_MUXER
#endif
#if CONFIG_TG2_MUXER
#endif
#if CONFIG_IPOD_MUXER
#endif
#if CONFIG_ISMV_MUXER
#endif
#if CONFIG_F4V_MUXER
#endif
