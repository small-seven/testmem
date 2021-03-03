#include <common.h>
#include <command.h>
#include <env.h>
#include <i2c.h>
#include <init.h>
#include <irq_func.h>
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
#include "../common/qixis.h"
#include "../common/vsc3316_3308.h"
#include "t4qds.h"
#include "t4240qds_qixis.h"
#define NUM_READINGS	4	/* prefer to be power of 2 for efficiency */
#define WAIT_FOR_ADC	532	/* wait for 532 microseconds for ADC */
#ifdef CONFIG_FSL_QIXIS_CLOCK_MEASUREMENT
#endif
#ifdef CONFIG_FSL_QIXIS_CLOCK_MEASUREMENT
#endif
#ifdef CONFIG_PCI
#endif
#ifdef CONFIG_SYS_DPAA_FMAN
#endif
