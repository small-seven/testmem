#include <float.h>
#include <stdint.h>
#include <string.h>
#include "avformat.h"
#include "avio_internal.h"
#include "matroska.h"
#include "libavutil/avstring.h"
#include "libavutil/dict.h"
#include "libavutil/opt.h"
#include "libavutil/time_internal.h"
typedef struct AdaptationSet {
    char id[10];
    int *streams;
    int nb_streams;
} AdaptationSet;
typedef struct WebMDashMuxContext {
    const AVClass  *class;
    char *adaptation_sets;
    AdaptationSet *as;
    int nb_as;
    int representation_id;
    int is_live;
    int chunk_start_index;
    int chunk_duration;
    char *utc_timing_url;
    double time_shift_buffer_depth;
    int minimum_update_period;
    int debug_mode;
} WebMDashMuxContext;
#define OFFSET(x) offsetof(WebMDashMuxContext, x)
#if CONFIG_WEBM_DASH_MANIFEST_MUXER
#endif
