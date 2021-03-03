#include <common.h>
#include <mmc.h>
#include "mmc_private.h"
#include <asm/io.h>
#include <memalign.h>
#if defined(CONFIG_TARGET_HI3519AV100) || defined(CONFIG_TARGET_HI3556AV100) ||\
#endif
#if defined(CONFIG_TARGET_HI3519AV100) || defined(CONFIG_TARGET_HI3556AV100) ||\
#elif defined(CONFIG_TARGET_HI3531DV200) || defined(CONFIG_TARGET_HI3535AV100) ||\
#else
#endif
#define EXT_CSD_REV_4_41	5
