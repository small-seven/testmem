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
#include <linux/errno.h>
#include <asm/cache.h>
#include <asm/immap_85xx.h>
#include <asm/fsl_law.h>
#include <asm/fsl_serdes.h>
#include <asm/fsl_liodn.h>
#include <fm_eth.h>
#include <hwconfig.h>
#include "../common/qixis.h"
#include "../common/vsc3316_3308.h"
#include "../common/idt8t49n222a_serdes_clk.h"
#include "../common/zm7300.h"
#include "b4860qds.h"
#include "b4860qds_qixis.h"
#include "b4860qds_crossbar_con.h"
#define CLK_MUX_SEL_MASK	0x4
#define ETH_PHY_CLK_OUT		0x4
#define WAIT_FOR_ADC	532	/* wait for 532 microseconds for ADC */
#define NUM_READINGS	4	/* prefer to be power of 2 for efficiency */
#ifdef CONFIG_ARCH_B4420
#endif
#ifdef CONFIG_ARCH_B4420
#endif
#ifdef CONFIG_SYS_FSL_B4860QDS_XFI_ERR
#else
#endif
#ifdef CONFIG_ARCH_B4420
#endif
#if defined(CONFIG_SYS_FSL_ERRATUM_A006384) || \
#endif
#define NUM_SRDS_BANKS	2
#ifdef CONFIG_PCI
#endif
#ifdef CONFIG_HAS_FSL_DR_USB
#endif
#ifdef CONFIG_SYS_DPAA_FMAN
#endif
