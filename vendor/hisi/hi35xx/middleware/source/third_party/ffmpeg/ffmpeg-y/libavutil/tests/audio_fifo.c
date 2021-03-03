#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "libavutil/mem.h"
#include "libavutil/audio_fifo.c"
#define MAX_CHANNELS    32
typedef struct TestStruct {
    const enum AVSampleFormat format;
    const int nb_ch;
    void const *data_planes[MAX_CHANNELS];
    const int nb_samples_pch;
} TestStruct;
