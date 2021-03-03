#include "avformat.h"
#include "libavutil/bprint.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "internal.h"
#include "libavcodec/gif.h"
typedef struct GIFDemuxContext {
    const AVClass *class;
    /**
     * Time span in hundredths of second before
     * the next frame should be drawn on screen.
     */
    int delay;
    /**
     * Minimum allowed delay between frames in hundredths of
     * second. Values below this threshold considered to be
     * invalid and set to value of default_delay.
     */
    int min_delay;
    int max_delay;
    int default_delay;

    /**
     * loop options
     */
    int total_iter;
    int iter_count;
    int ignore_loop;

    int nb_frames;
    int last_duration;
} GIFDemuxContext;
#define GIF_DEFAULT_DELAY   10
#define GIF_MIN_DELAY       2
