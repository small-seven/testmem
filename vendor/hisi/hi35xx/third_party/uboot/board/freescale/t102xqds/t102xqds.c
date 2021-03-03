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
#include "../common/qixis.h"
#include "t102xqds.h"
#include "t102xqds_qixis.h"
#include "../common/sleep.h"
#ifdef CONFIG_SDCARD
#elif CONFIG_SPIFLASH
#else
#endif
#ifdef CONFIG_ARCH_T1024
#endif
#if defined(CONFIG_DEEP_SLEEP)
#endif
#ifdef CONFIG_SYS_FLASH_BASE
#endif
#define NUM_SRDS_PLL	2
#ifdef CONFIG_ARCH_T1024
#endif
#ifdef CONFIG_PCI
#endif
#ifdef CONFIG_HAS_FSL_DR_USB
#endif
#ifdef CONFIG_SYS_DPAA_FMAN
#endif
