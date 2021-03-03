#include <inttypes.h>
#include <stddef.h>
#include "libavutil/adler32.h"
#include "libavutil/attributes.h"
#include "libavutil/channel_layout.h"
#include "libavutil/common.h"
#include "libavutil/downmix_info.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/mem.h"
#include "libavutil/replaygain.h"
#include "libavutil/timestamp.h"
#include "libavutil/samplefmt.h"
#include "libavcodec/avcodec.h"
#include "audio.h"
#include "avfilter.h"
#include "internal.h"
typedef struct AShowInfoContext {
    /**
     * Scratch space for individual plane checksums for planar audio
     */
    uint32_t *plane_checksums;
} AShowInfoContext;
