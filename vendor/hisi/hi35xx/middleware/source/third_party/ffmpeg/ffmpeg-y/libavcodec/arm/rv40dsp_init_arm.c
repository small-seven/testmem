#include <stdint.h>
#include "libavutil/attributes.h"
#include "libavcodec/avcodec.h"
#include "libavcodec/rv34dsp.h"
#include "libavutil/arm/cpu.h"
#define DECL_QPEL3(type, w, pos) \
#define DECL_QPEL2(w, pos)                      \
#define DECL_QPEL_XY(x, y)                      \
#define DECL_QPEL_Y(y)                          \
