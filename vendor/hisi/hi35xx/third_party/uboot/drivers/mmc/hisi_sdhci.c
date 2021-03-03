#include <common.h>
#include <malloc.h>
#include <sdhci.h>
#include "mmc_private.h"
#define MIN_FREQ	400000
#define NOT_FOUND	(-1)
#define PHASE_SCALE	32
#define EDGE_TUNING_PHASE_STEP	4
#if defined(CONFIG_TARGET_HI3556AV100) || defined(CONFIG_TARGET_HI3519AV100)
#include <asm/arch-hi3556av100/platform.h>
#include "hisi_hi3556av100.c"
#endif
#if defined(CONFIG_TARGET_HI3559AV100) || defined(CONFIG_TARGET_HI3569V100)
#include <asm/arch-hi3559av100/platform.h>
#include "hisi_hi3559av100.c"
#endif
#ifdef CONFIG_TARGET_HI3516EV200
#include <asm/arch-hi3516ev200/platform.h>
#include "hisi_hi3516ev200.c"
#endif
#ifdef CONFIG_TARGET_HI3516EV300
#include <asm/arch-hi3516ev300/platform.h>
#include "hisi_hi3516ev300.c"
#endif
#ifdef CONFIG_TARGET_HI3518EV300
#include <asm/arch-hi3518ev300/platform.h>
#include "hisi_hi3518ev300.c"
#endif
#ifdef CONFIG_TARGET_HI3516DV200
#include <asm/arch-hi3516dv200/platform.h>
#include "hisi_hi3516dv200.c"
#endif
#ifdef CONFIG_TARGET_HI3531DV200
#include <asm/arch-hi3531dv200/platform.h>
#include "hisi_hi3531dv200.c"
#endif
#ifdef CONFIG_TARGET_HI3535AV100
#include <asm/arch-hi3531dv200/platform.h>
#include "hisi_hi3531dv200.c"
#endif
#ifdef CONFIG_TARGET_HI3521DV200
#include <asm/arch-hi3521dv200/platform.h>
#include "hisi_hi3521dv200.c"
#endif
#ifdef CONFIG_TARGET_HI3520DV500
#include <asm/arch-hi3521dv200/platform.h>
#include "hisi_hi3521dv200.c"
#endif
#if defined(CONFIG_TARGET_HI3531DV200) || defined(CONFIG_TARGET_HI3535AV100) ||\
#elif !(defined(CONFIG_TARGET_HI3516EV200) || defined(CONFIG_TARGET_HI3518EV300))
#endif
#ifdef MMC_SUPPORTS_TUNING
#endif
#if defined(CONFIG_TARGET_HI3531DV200) || defined(CONFIG_TARGET_HI3535AV100) || \
#endif
