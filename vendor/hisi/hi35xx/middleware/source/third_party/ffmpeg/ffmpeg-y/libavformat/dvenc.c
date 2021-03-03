#include <time.h>
#include <stdarg.h>
#include "avformat.h"
#include "internal.h"
#include "libavcodec/dv_profile.h"
#include "libavcodec/dv.h"
#include "dv.h"
#include "libavutil/avassert.h"
#include "libavutil/fifo.h"
#include "libavutil/mathematics.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavutil/timecode.h"
#define MAX_AUDIO_FRAME_SIZE 192000 // 1 second of 48khz 32-bit audio
