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
#include <asm/fsl_portals.h>
#include <asm/fsl_liodn.h>
#include <fm_eth.h>
#include "../common/common.h"
#include "kmp204x.h"
#define DEBLOCK_PORT1	GPIO_A
#define DEBLOCK_SCL1	20
#define DEBLOCK_SDA1	21
#define ZL30158_RST	8
#define BFTIC4_RST	0
#define RSTRQSR1_WDT_RR	0x00200000
#define RSTRQSR1_SW_RR	0x00100000
#define ETH_FRONT_PHY_RST	15
#define QSFP2_RST		11
#define QSFP1_RST		10
#define ZL30343_RST		9
#define NUM_SRDS_BANKS	2
#if defined(CONFIG_HUSH_INIT_VAR)
#endif
#if defined(CONFIG_LAST_STAGE_INIT)
#if defined(CONFIG_KMCOGE4)
#endif
#endif
#ifdef CONFIG_SYS_DPAA_FMAN
#endif
#if defined(CONFIG_HAS_FSL_DR_USB) || defined(CONFIG_HAS_FSL_MPH_USB)
#endif
#ifdef CONFIG_PCI
#endif
#ifdef CONFIG_SYS_DPAA_FMAN
#endif
#if defined(CONFIG_POST)
#define SELFTEST_PORT	GPIO_A
#define SELFTEST_PIN	31
#endif
