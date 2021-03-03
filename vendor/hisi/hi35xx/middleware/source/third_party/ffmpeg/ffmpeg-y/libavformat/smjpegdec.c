#include <inttypes.h>
#include "avformat.h"
#include "internal.h"
#include "riff.h"
#include "smjpeg.h"
typedef struct SMJPEGContext {
    int audio_stream_index;
    int video_stream_index;
} SMJPEGContext;
