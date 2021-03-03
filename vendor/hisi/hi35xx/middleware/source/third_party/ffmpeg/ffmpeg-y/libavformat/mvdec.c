#include "libavutil/channel_layout.h"
#include "libavutil/eval.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/rational.h"
#include "avformat.h"
#include "internal.h"
typedef struct MvContext {
    int nb_video_tracks;
    int nb_audio_tracks;

    int eof_count;        ///< number of streams that have finished
    int stream_index;     ///< current stream index
    int frame[2];         ///< frame nb for current stream

    int acompression;     ///< compression level for audio stream
    int aformat;          ///< audio format
} MvContext;
#define AUDIO_FORMAT_SIGNED 401
