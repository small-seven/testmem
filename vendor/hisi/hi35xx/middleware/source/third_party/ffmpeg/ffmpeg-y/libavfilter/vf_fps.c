#include <float.h>
#include <stdint.h>
#include "libavutil/avassert.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "filters.h"
#include "internal.h"
typedef struct FPSContext {
    const AVClass *class;

    double start_time;      ///< pts, in seconds, of the expected first frame

    AVRational framerate;   ///< target framerate
    int rounding;           ///< AVRounding method for timestamps
    int eof_action;         ///< action performed for last frame in FIFO

    /* Set during outlink configuration */
    int64_t  in_pts_off;    ///< input frame pts offset for start_time handling
    int64_t  out_pts_off;   ///< output frame pts offset for start_time handling

    /* Runtime state */
    int      status;        ///< buffered input status
    int64_t  status_pts;    ///< buffered input status timestamp

    AVFrame *frames[2];     ///< buffered frames
    int      frames_count;  ///< number of buffered frames

    int64_t  next_pts;      ///< pts of the next frame to output

    /* statistics */
    int cur_frame_out;         ///< number of times current frame has been output
    int frames_in;             ///< number of frames on input
    int frames_out;            ///< number of frames on output
    int dup;                   ///< number of frames duplicated
    int drop;                  ///< number of framed dropped
} FPSContext;
#define OFFSET(x) offsetof(FPSContext, x)
#define V AV_OPT_FLAG_VIDEO_PARAM
#define F AV_OPT_FLAG_FILTERING_PARAM
