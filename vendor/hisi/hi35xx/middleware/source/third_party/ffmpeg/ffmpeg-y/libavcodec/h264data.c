#include <stdint.h>
#include "libavutil/avutil.h"
#include "avcodec.h"
#include "h264dec.h"
#include "h264data.h"
#define QP(qP, depth) ((qP) + 6 * ((depth) - 8))
#define CHROMA_QP_TABLE_END(d)                                          \
