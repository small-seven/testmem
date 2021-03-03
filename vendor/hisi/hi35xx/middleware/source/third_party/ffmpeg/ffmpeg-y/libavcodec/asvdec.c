#include "libavutil/attributes.h"
#include "libavutil/mem.h"
#include "asv.h"
#include "avcodec.h"
#include "blockdsp.h"
#include "idctdsp.h"
#include "internal.h"
#include "mathops.h"
#include "mpeg12data.h"
#define VLC_BITS             6
#define ASV2_LEVEL_VLC_BITS 10
#if CONFIG_ASV1_DECODER
#endif
#if CONFIG_ASV2_DECODER
#endif
