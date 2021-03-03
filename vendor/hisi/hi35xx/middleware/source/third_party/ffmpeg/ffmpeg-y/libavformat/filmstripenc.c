#include "libavutil/intreadwrite.h"
#include "avformat.h"
#define RAND_TAG MKBETAG('R','a','n','d')
typedef struct FilmstripMuxContext {
    int nb_frames;
} FilmstripMuxContext;
