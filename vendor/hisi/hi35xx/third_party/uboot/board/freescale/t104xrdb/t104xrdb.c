#include <common.h>
#include <command.h>
#include <env.h>
#include <hwconfig.h>
#include <init.h>
#include <netdev.h>
#include <linux/compiler.h>
#include <asm/mmu.h>
#include <asm/processor.h>
#include <asm/cache.h>
#include <asm/immap_85xx.h>
#include <asm/fsl_fdt.h>
#include <asm/fsl_law.h>
#include <asm/fsl_serdes.h>
#include <asm/fsl_liodn.h>
#include <fm_eth.h>
#include "../common/sleep.h"
#include "t104xrdb.h"
#include "cpld.h"
#if defined(CONFIG_TARGET_T1040D4RDB) || defined(CONFIG_TARGET_T1042D4RDB)
#else
#endif
#if defined(CONFIG_DEEP_SLEEP)
#endif
#ifdef CONFIG_SYS_FLASH_BASE
#endif
#if defined(CONFIG_TARGET_T1040D4RDB)
#endif
#ifdef CONFIG_PCI
#endif
#ifdef CONFIG_HAS_FSL_DR_USB
#endif
#ifdef CONFIG_SYS_DPAA_FMAN
#endif
