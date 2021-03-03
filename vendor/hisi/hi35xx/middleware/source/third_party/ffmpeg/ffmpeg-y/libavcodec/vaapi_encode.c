#include <inttypes.h>
#include <string.h>
#include "libavutil/avassert.h"
#include "libavutil/common.h"
#include "libavutil/log.h"
#include "libavutil/pixdesc.h"
#include "vaapi_encode.h"
#include "avcodec.h"
static int vaapi_encode_free(AVCodecContext *avctx,
                             VAAPIEncodePicture *pic)
{
    int i;

    if (pic->encode_issued)
        vaapi_encode_discard(avctx, pic);

    for (i = 0; i < pic->nb_slices; i++) {
        if (pic->slices) {
            av_freep(&pic->slices[i].priv_data);
            av_freep(&pic->slices[i].codec_slice_params);
        }
    }
    av_freep(&pic->codec_picture_params);

    av_frame_free(&pic->input_image);
    av_frame_free(&pic->recon_image);

    av_freep(&pic->param_buffers);
    av_freep(&pic->slices);
    // Output buffer should already be destroyed.
    av_assert0(pic->output_buffer == VA_INVALID_ID);

    av_freep(&pic->priv_data);
    av_freep(&pic->codec_picture_params);

    av_free(pic);

    return 0;
}
typedef struct VAAPIEncodeRTFormat {
    const char *name;
    unsigned int value;
    int depth;
    int nb_components;
    int log2_chroma_w;
    int log2_chroma_h;
} VAAPIEncodeRTFormat;
#if VA_CHECK_VERSION(0, 38, 1)
#endif
#if VA_CHECK_VERSION(0, 39, 2)
#endif
#if VA_CHECK_VERSION(0, 39, 2)
#endif
#if VA_CHECK_VERSION(0, 39, 2)
#else
#endif
#if VA_CHECK_VERSION(1, 0, 0)
#else
#endif
#if VA_CHECK_VERSION(1, 0, 0)
#else
#endif
#if VA_CHECK_VERSION(1, 1, 0)
#else
#endif
#if VA_CHECK_VERSION(1, 3, 0)
#else
#endif
#define TRY_RC_MODE(mode, fail) do { \
#if VA_CHECK_VERSION(1, 1, 0)
#endif
#if VA_CHECK_VERSION(1, 3, 0)
#endif
#if VA_CHECK_VERSION(0, 40, 0)
#endif
#if VA_CHECK_VERSION(1, 0, 0)
#endif
#if VA_CHECK_VERSION(0, 36, 0)
#else
#endif
