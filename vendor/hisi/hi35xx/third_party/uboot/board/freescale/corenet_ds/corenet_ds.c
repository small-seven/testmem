#include <common.h>
#include <command.h>
#include <env.h>
#include <init.h>
#include <netdev.h>
#include <linux/compiler.h>
#include <asm/mmu.h>
#include <asm/processor.h>
#include <asm/cache.h>
#include <asm/immap_85xx.h>
#include <asm/fsl_law.h>
#include <asm/fsl_serdes.h>
#include <asm/fsl_liodn.h>
#include <fm_eth.h>
#include "../common/ngpixis.h"
#include "corenet_ds.h"
#if defined(CONFIG_TARGET_P3041DS) || defined(CONFIG_TARGET_P5020DS) || \
#endif
#if defined(CONFIG_TARGET_P3041DS) || defined(CONFIG_TARGET_P5020DS) || \
#ifdef CONFIG_TARGET_P5040DS
#endif
#else
#endif
#define NUM_SRDS_BANKS	3
#if defined(CONFIG_TARGET_P3041DS) || defined(CONFIG_TARGET_P5020DS) || \
#else
#endif
#ifdef CONFIG_PCI
#endif
#ifdef CONFIG_SYS_DPAA_FMAN
#endif
