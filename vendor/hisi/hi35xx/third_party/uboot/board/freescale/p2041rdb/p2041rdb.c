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
#include "cpld.h"
#define CPLD_LANE_A_SEL	0x1
#define CPLD_LANE_G_SEL	0x2
#define CPLD_LANE_C_SEL	0x4
#define CPLD_LANE_D_SEL	0x8
#define NUM_SRDS_BANKS	2
#if defined(CONFIG_HAS_FSL_DR_USB) || defined(CONFIG_HAS_FSL_MPH_USB)
#endif
#ifdef CONFIG_PCI
#endif
#ifdef CONFIG_SYS_DPAA_FMAN
#endif
