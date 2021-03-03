#define UNCHECKED_BITSTREAM_READER 1
#include <inttypes.h>
#include "libavutil/attributes.h"
#include "libavutil/imgutils.h"
#include "libavutil/internal.h"
#include "libavutil/stereo3d.h"
#include "avcodec.h"
#include "bytestream.h"
#include "error_resilience.h"
#include "hwaccel.h"
#include "idctdsp.h"
#include "internal.h"
#include "mpeg_er.h"
#include "mpeg12.h"
#include "mpeg12data.h"
#include "mpegutils.h"
#include "mpegvideo.h"
#include "mpegvideodata.h"
#include "profiles.h"
#include "thread.h"
#include "version.h"
#include "xvmc_internal.h"
typedef struct Mpeg1Context {
    MpegEncContext mpeg_enc_ctx;
    int mpeg_enc_ctx_allocated; /* true if decoding context allocated */
    int repeat_field;           /* true if we must repeat the field */
    AVPanScan pan_scan;         /* some temporary storage for the panscan */
    AVStereo3D stereo3d;
    int has_stereo3d;
    uint8_t *a53_caption;
    int a53_caption_size;
    uint8_t afd;
    int has_afd;
    int slice_count;
    AVRational save_aspect;
    int save_width, save_height, save_progressive_seq;
    AVRational frame_rate_ext;  /* MPEG-2 specific framerate modificator */
    int sync;                   /* Did we reach a sync point like a GOP/SEQ/KEYFrame? */
    int tmpgexs;
    int first_slice;
    int extradata_decoded;
} Mpeg1Context;
#define MB_TYPE_ZERO_MV   0x20000000
#define MAX_INDEX (64 - 1)
#define check_scantable_index(ctx, x)                                         \
#define MT_FIELD 1
#define MT_FRAME 2
#define MT_16X8  2
#define MT_DMV   3
#if HAVE_THREADS
#endif
#if CONFIG_MPEG1_NVDEC_HWACCEL
#endif
#if CONFIG_MPEG1_XVMC_HWACCEL
#endif
#if CONFIG_MPEG1_VDPAU_HWACCEL
#endif
#if CONFIG_MPEG2_NVDEC_HWACCEL
#endif
#if CONFIG_MPEG2_XVMC_HWACCEL
#endif
#if CONFIG_MPEG2_VDPAU_HWACCEL
#endif
#if CONFIG_MPEG2_DXVA2_HWACCEL
#endif
#if CONFIG_MPEG2_D3D11VA_HWACCEL
#endif
#if CONFIG_MPEG2_VAAPI_HWACCEL
#endif
#if CONFIG_MPEG2_VIDEOTOOLBOX_HWACCEL
#endif
#define DECODE_SLICE_ERROR -1
#define DECODE_SLICE_OK     0
#if 0
#endif
#if FF_API_PRIVATE_OPT
#endif
#if CONFIG_MPEG1_NVDEC_HWACCEL
#endif
#if CONFIG_MPEG1_VDPAU_HWACCEL
#endif
#if CONFIG_MPEG1_VIDEOTOOLBOX_HWACCEL
#endif
#if CONFIG_MPEG1_XVMC_HWACCEL
#endif
#if CONFIG_MPEG2_DXVA2_HWACCEL
#endif
#if CONFIG_MPEG2_D3D11VA_HWACCEL
#endif
#if CONFIG_MPEG2_D3D11VA2_HWACCEL
#endif
#if CONFIG_MPEG2_NVDEC_HWACCEL
#endif
#if CONFIG_MPEG2_VAAPI_HWACCEL
#endif
#if CONFIG_MPEG2_VDPAU_HWACCEL
#endif
#if CONFIG_MPEG2_VIDEOTOOLBOX_HWACCEL
#endif
#if CONFIG_MPEG2_XVMC_HWACCEL
#endif
