#include <asm/io.h>
#ifndef error
#define error(fmt, args...) do { \
#include <common.h>
#endif
#include <compiler.h>
#include "hw_decompress_v1.h"
#if (defined CONFIG_TARGET_HI3556V200)
#include "hw_decompress_hi3556v200.c"
#endif
#if (defined CONFIG_TARGET_HI3559V200)
#include "hw_decompress_hi3559v200.c"
#endif
#if (defined CONFIG_TARGET_HI3562V100)
#include "hw_decompress_hi3559v200.c"
#endif
#if (defined CONFIG_TARGET_HI3566V100)
#include "hw_decompress_hi3559v200.c"
#endif
#if ((defined CONFIG_TARGET_HI3516DV300) || (defined CONFIG_TARGET_HI3516AV300))
#include "hw_decompress_hi3516dv300.c"
#endif
#if (defined CONFIG_TARGET_HI3516CV500)
#include "hw_decompress_hi3516cv500.c"
#endif
#if (defined CONFIG_TARGET_HI3516EV200)
#include "hw_decompress_hi3516ev200.c"
#endif
#if (defined CONFIG_TARGET_HI3516EV300)
#include "hw_decompress_hi3516ev300.c"
#endif
#if (defined CONFIG_TARGET_HI3518EV300)
#include "hw_decompress_hi3518ev300.c"
#endif
#if (defined CONFIG_TARGET_HI3516DV200)
#include "hw_decompress_hi3516dv200.c"
#endif
