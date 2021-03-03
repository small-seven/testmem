#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "avformat.h"
#include "internal.h"
#include "sauce.h"
#include "libavcodec/bintext.h"
typedef struct {
    const AVClass *class;
    int chars_per_frame; /**< characters to send decoder per frame;
                              set by private options as characters per second, and then
                              converted to characters per frame at runtime */
    int width, height;    /**< video size (WxH pixels) (private option) */
    AVRational framerate; /**< frames per second (private option) */
    uint64_t fsize;  /**< file size less metadata buffer */
} BinDemuxContext;
#if CONFIG_BINTEXT_DEMUXER | CONFIG_ADF_DEMUXER | CONFIG_IDF_DEMUXER
#endif
#if CONFIG_BINTEXT_DEMUXER
#define GET_EFI2_META(name,size) \
#endif /* CONFIG_BINTEXT_DEMUXER */
#if CONFIG_XBIN_DEMUXER
#endif /* CONFIG_XBIN_DEMUXER */
#if CONFIG_ADF_DEMUXER
#endif /* CONFIG_ADF_DEMUXER */
#if CONFIG_IDF_DEMUXER
#endif /* CONFIG_IDF_DEMUXER */
#define OFFSET(x) offsetof(BinDemuxContext, x)
#define CLASS(name) \
#if CONFIG_BINTEXT_DEMUXER
#endif
#if CONFIG_XBIN_DEMUXER
#endif
#if CONFIG_ADF_DEMUXER
#endif
#if CONFIG_IDF_DEMUXER
#endif
