#include "libavutil/channel_layout.h"
#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
#define JV_PREAMBLE_SIZE 5
typedef struct JVFrame {
    int audio_size;    /**< audio packet size (bytes) */
    int video_size;    /**< video packet size (bytes) */
    int palette_size;  /**< palette size (bytes) */
    int video_type;    /**< per-frame video compression type */
} JVFrame;
typedef struct JVDemuxContext {
    JVFrame *frames;
    enum {
        JV_AUDIO = 0,
        JV_VIDEO,
        JV_PADDING
    } state;
#define MAGIC " Compression by John M Phillips Copyright (C) 1995 The Bitmap Brothers Ltd."
