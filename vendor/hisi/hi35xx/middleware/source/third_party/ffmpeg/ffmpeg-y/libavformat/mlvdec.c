#include "libavutil/eval.h"
#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/rational.h"
#include "avformat.h"
#include "avio_internal.h"
#include "internal.h"
#include "riff.h"
#define MLV_VERSION "v2.0"
#define MLV_VIDEO_CLASS_RAW  1
#define MLV_VIDEO_CLASS_YUV  2
#define MLV_VIDEO_CLASS_JPEG 3
#define MLV_VIDEO_CLASS_H264 4
#define MLV_AUDIO_CLASS_WAV  1
#define MLV_CLASS_FLAG_DELTA 0x40
#define MLV_CLASS_FLAG_LZMA  0x80
typedef struct {
    AVIOContext *pb[101];
    int class[2];
    int stream_index;
    uint64_t pts;
} MlvContext;
