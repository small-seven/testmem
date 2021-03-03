#include <asm/io.h>
#ifndef error
#define error(fmt, args...) do { \
#endif
#include "hw_decompress_v2.h"
#if (defined CONFIG_TARGET_HI3559AV100) || (defined CONFIG_HI3559AV100)
#include "hw_decompress_hi3559av100.c"
#endif
#if (defined CONFIG_TARGET_HI3569V100) || (defined CONFIG_HI3569V100)
#include "hw_decompress_hi3569v100.c"
#endif
#if (defined CONFIG_TARGET_HI3556AV100)
#include "hw_decompress_hi3556av100.c"
#endif
#if (defined CONFIG_TARGET_HI3519AV100)
#include "hw_decompress_hi3519av100.c"
#endif
