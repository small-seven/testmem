#include "libavutil/avassert.h"
#include "avcodec.h"
#include "internal.h"
#include "g722.h"
#include "libavutil/common.h"
#define FREEZE_INTERVAL 128
#define MAX_FRAME_SIZE 32768
#define MIN_TRELLIS 0
#define MAX_TRELLIS 16
#define STORE_NODE(index, UPDATE, VALUE)\
