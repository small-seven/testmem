#include "libavutil/intreadwrite.h"
#include "libavutil/imgutils.h"
#include "avformat.h"
#include "internal.h"
#define RAND_TAG MKBETAG('R','a','n','d')
typedef struct FilmstripDemuxContext {
    int leading;
} FilmstripDemuxContext;
