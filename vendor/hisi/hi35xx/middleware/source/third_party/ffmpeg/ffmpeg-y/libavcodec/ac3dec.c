#include <stdio.h>
#include <stddef.h>
#include <math.h>
#include <string.h>
#include "libavutil/channel_layout.h"
#include "libavutil/crc.h"
#include "libavutil/downmix_info.h"
#include "libavutil/opt.h"
#include "bswapdsp.h"
#include "internal.h"
#include "aac_ac3_parser.h"
#include "ac3_parser_internal.h"
#include "ac3dec.h"
#include "ac3dec_data.h"
#include "kbdwin.h"
#if (!USE_FIXED)
#endif
#if (!USE_FIXED)
#endif
#if (USE_FIXED)
#else
#endif
typedef struct mant_groups {
    int b1_mant[2];
    int b2_mant[2];
    int b4_mant;
    int b1;
    int b2;
    int b4;
} mant_groups;
#if USE_FIXED
#else
#endif
#if USE_FIXED
#else
#endif
#if USE_FIXED
#endif
#if USE_FIXED
#else
#endif
#if USE_FIXED
#else
#endif
#if USE_FIXED
#else
#endif
#if USE_FIXED
#else
#endif
#define OFFSET(x) offsetof(AC3DecodeContext, x)
#define PAR (AV_OPT_FLAG_DECODING_PARAM | AV_OPT_FLAG_AUDIO_PARAM)
