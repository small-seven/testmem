#include <stdlib.h>
#include "libavformat/avformat.h"
#include "libavcodec/put_bits.h"
#include "libavutil/lfg.h"
#include "libavutil/timer.h"
#define MAX_FORMATS 1000 //this must be larger than the number of formats
#ifndef AV_READ_TIME
#define AV_READ_TIME(x) 0
#endif
