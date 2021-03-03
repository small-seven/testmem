#include <float.h>
#include <time.h>
#include "avformat.h"
#include "avio.h"
#include "avio_internal.h"
#include "internal.h"
#include "libavutil/avassert.h"
#include "libavutil/log.h"
#include "libavutil/opt.h"
#include "libavutil/avstring.h"
#include "libavutil/parseutils.h"
#include "libavutil/mathematics.h"
#include "libavutil/time.h"
#include "libavutil/time_internal.h"
#include "libavutil/timestamp.h"
#define MAX_FILENAME_SIZE 1024
typedef struct WebMChunkContext {
    const AVClass *class;
    int chunk_start_index;
    char *header_filename;
    int chunk_duration;
    int chunk_index;
    char *http_method;
    uint64_t duration_written;
    int64_t prev_pts;
    ff_const59 AVOutputFormat *oformat;
    AVFormatContext *avf;
} WebMChunkContext;
#define OFFSET(x) offsetof(WebMChunkContext, x)
#if CONFIG_WEBM_CHUNK_MUXER
#endif
