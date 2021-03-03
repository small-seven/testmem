#include <common.h>
#include <command.h>
#include <env.h>
#include <i2c.h>
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
#include <hwconfig.h>
#include "../common/sleep.h"
#include "../common/qixis.h"
#include "t1040qds.h"
#include "t1040qds_qixis.h"
#if defined(CONFIG_DEEP_SLEEP)
#endif
#ifdef CONFIG_SYS_FLASH_BASE
#endif
#define NUM_SRDS_BANKS	2
#ifdef CONFIG_PCI
#endif
#ifdef CONFIG_HAS_FSL_DR_USB
#endif
#ifdef CONFIG_SYS_DPAA_FMAN
#endif
