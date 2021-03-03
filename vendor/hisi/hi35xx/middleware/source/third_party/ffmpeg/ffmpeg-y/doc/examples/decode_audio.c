#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libavutil/frame.h>
#include <libavutil/mem.h>
#include <libavcodec/avcodec.h>
#define AUDIO_INBUF_SIZE 20480
#define AUDIO_REFILL_THRESH 4096
