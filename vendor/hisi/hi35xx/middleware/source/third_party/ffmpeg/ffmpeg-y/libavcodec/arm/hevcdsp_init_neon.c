#include "libavutil/attributes.h"
#include "libavutil/arm/cpu.h"
#include "libavcodec/hevcdsp.h"
#include "libavcodec/avcodec.h"
#include "hevcdsp_arm.h"
#define PUT_PIXELS(name) \
#undef PUT_PIXELS
#define QPEL_FUNC(name) \
#undef QPEL_FUNC
#define QPEL_FUNC_UW_PIX(name) \
#undef QPEL_FUNC_UW_PIX
#define QPEL_FUNC_UW(name) \
#undef QPEL_FUNC_UW
