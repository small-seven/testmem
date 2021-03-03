#include "libavutil/channel_layout.h"
#include "avformat.h"
#include "avio_internal.h"
#include "internal.h"
#include "pcm.h"
#include "rawenc.h"
#include "riff.h"
typedef struct MMFContext {
    int64_t atrpos, atsqpos, awapos;
    int64_t data_end;
    int stereo;
} MMFContext;
#if CONFIG_MMF_MUXER
#endif /* CONFIG_MMF_MUXER */
#define MAX_SIZE 4096
#if CONFIG_MMF_DEMUXER
#endif
#if CONFIG_MMF_MUXER
#endif
