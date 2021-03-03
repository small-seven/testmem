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
#include "../common/qixis.h"
#include "../common/vsc3316_3308.h"
#include "../common/vid.h"
#include "t208xqds.h"
#include "t208xqds_qixis.h"
#ifdef CONFIG_SDCARD
#elif CONFIG_SPIFLASH
#else
#endif
#if defined(CONFIG_TARGET_T2080QDS)
#endif
#if defined(CONFIG_TARGET_T2080QDS)
#elif defined(CONFIG_TARGET_T2081QDS)
#endif
#ifdef CONFIG_TARGET_T2080QDS
#endif
#ifdef CONFIG_FSL_QIXIS_CLOCK_MEASUREMENT
#endif
#ifdef CONFIG_FSL_QIXIS_CLOCK_MEASUREMENT
#endif
#ifdef CONFIG_PCI
#endif
#ifdef CONFIG_SYS_DPAA_FMAN
#endif
