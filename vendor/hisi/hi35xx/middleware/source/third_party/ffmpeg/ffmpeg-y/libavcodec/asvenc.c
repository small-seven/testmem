#include "libavutil/attributes.h"
#include "libavutil/mem.h"
#include "aandcttab.h"
#include "asv.h"
#include "avcodec.h"
#include "dct.h"
#include "fdctdsp.h"
#include "internal.h"
#include "mathops.h"
#include "mpeg12data.h"
#define MAX_MB_SIZE (30 * 16 * 16 * 3 / 2 / 8)
#if CONFIG_ASV1_ENCODER
#endif
#if CONFIG_ASV2_ENCODER
#endif
