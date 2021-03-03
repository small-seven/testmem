#include "config.h"
#include "libavutil/attributes.h"
#include "lossless_videoencdsp.h"
#include "mathops.h"
#define pb_7f (~0UL / 255 * 0x7f)
#define pb_80 (~0UL / 255 * 0x80)
#if !HAVE_FAST_UNALIGNED
#endif
