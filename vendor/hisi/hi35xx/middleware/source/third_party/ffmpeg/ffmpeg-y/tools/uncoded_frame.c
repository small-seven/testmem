#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libavutil/avassert.h"
#include "libavdevice/avdevice.h"
#include "libavfilter/avfilter.h"
#include "libavfilter/buffersink.h"
#include "libavformat/avformat.h"
typedef struct {
    AVFormatContext *mux;
    AVStream *stream;
    AVFilterContext *sink;
} Stream;
