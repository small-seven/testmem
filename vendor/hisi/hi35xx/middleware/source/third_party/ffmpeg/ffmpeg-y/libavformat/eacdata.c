#include "avformat.h"
#include "internal.h"
typedef struct CdataDemuxContext {
  unsigned int channels;
  unsigned int audio_pts;
} CdataDemuxContext;
