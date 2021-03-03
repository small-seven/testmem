#include "config.h"
#include "libavutil/avassert.h"
#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "libavcodec/avcodec.h"
#include "libavcodec/bytestream.h"
#include "libavformat/avformat.h"
typedef struct FuzzDataBuffer {
    size_t size_;
    uint8_t *data_;
} FuzzDataBuffer;
#ifdef FFMPEG_DECODER
#define DECODER_SYMBOL0(CODEC) ff_##CODEC##_decoder
#define DECODER_SYMBOL(CODEC) DECODER_SYMBOL0(CODEC)
#else
#endif
