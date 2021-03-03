#include "dnn_backend_native.h"
#include "libavutil/avassert.h"
#define CLAMP_TO_EDGE(x, w) ((x) < 0 ? 0 : ((x) >= (w) ? (w - 1) : (x)))
