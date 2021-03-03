#include <common.h>
#include <command.h>
#include <env.h>
#include <i2c.h>
#include <init.h>
#include <netdev.h>
#include <linux/compiler.h>
#include <asm/mmu.h>
#include <asm/processor.h>
#include <asm/immap_85xx.h>
#include <asm/fsl_law.h>
#include <asm/fsl_serdes.h>
#include <asm/fsl_liodn.h>
#include <fm_eth.h>
#include "t102xrdb.h"
#ifdef CONFIG_TARGET_T1024RDB
#include "cpld.h"
#elif defined(CONFIG_TARGET_T1023RDB)
#include <i2c.h>
#include <mmc.h>
#endif
#include "../common/sleep.h"
#ifdef CONFIG_TARGET_T1023RDB
#endif
#if defined(CONFIG_TARGET_T1024RDB)
#elif defined(CONFIG_TARGET_T1023RDB)
#endif
#ifdef CONFIG_SDCARD
#elif CONFIG_SPIFLASH
#elif defined(CONFIG_TARGET_T1024RDB)
#elif defined(CONFIG_TARGET_T1023RDB)
#ifdef CONFIG_MTD_RAW_NAND
#else
#endif
#endif
#ifdef CONFIG_TARGET_T1024RDB
#endif
#if defined(CONFIG_DEEP_SLEEP)
#endif
#ifdef CONFIG_SYS_FLASH_BASE
#endif
#ifdef CONFIG_TARGET_T1024RDB
#endif
#ifdef CONFIG_TARGET_T1024RDB
#endif
#ifdef CONFIG_PCI
#endif
#ifdef CONFIG_SYS_DPAA_FMAN
#endif
#ifdef CONFIG_TARGET_T1023RDB
#endif
#ifdef CONFIG_TARGET_T1023RDB
#endif
