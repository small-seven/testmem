#include <libxml/parser.h>
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavutil/time.h"
#include "libavutil/parseutils.h"
#include "internal.h"
#include "avio_internal.h"
#include "dash.h"
#define INITIAL_BUFFER_SIZE 32768
typedef struct DASHContext {
    const AVClass *class;
    char *base_url;
    char *adaptionset_contenttype_val;
    char *adaptionset_par_val;
    char *adaptionset_lang_val;
    char *adaptionset_minbw_val;
    char *adaptionset_maxbw_val;
    char *adaptionset_minwidth_val;
    char *adaptionset_maxwidth_val;
    char *adaptionset_minheight_val;
    char *adaptionset_maxheight_val;
    char *adaptionset_minframerate_val;
    char *adaptionset_maxframerate_val;
    char *adaptionset_segmentalignment_val;
    char *adaptionset_bitstreamswitching_val;

    int n_videos;
    struct representation **videos;
    int n_audios;
    struct representation **audios;
    int n_subtitles;
    struct representation **subtitles;

    /* MediaPresentationDescription Attribute */
    uint64_t media_presentation_duration;
    uint64_t suggested_presentation_delay;
    uint64_t availability_start_time;
    uint64_t availability_end_time;
    uint64_t publish_time;
    uint64_t minimum_update_period;
    uint64_t time_shift_buffer_depth;
    uint64_t min_buffer_time;

    /* Period Attribute */
    uint64_t period_duration;
    uint64_t period_start;

    int is_live;
    AVIOInterruptCB *interrupt_callback;
    char *allowed_extensions;
    AVDictionary *avio_opts;
    int max_url_size;

    /* Flags for init section*/
    int is_init_section_common_video;
    int is_init_section_common_audio;

} DASHContext;
#if FF_API_R_FRAME_RATE
#endif
#define OFFSET(x) offsetof(DASHContext, x)
#define FLAGS AV_OPT_FLAG_DECODING_PARAM
