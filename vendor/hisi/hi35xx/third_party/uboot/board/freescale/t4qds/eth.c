#include <common.h>
#include <command.h>
#include <netdev.h>
#include <asm/mmu.h>
#include <asm/processor.h>
#include <asm/cache.h>
#include <asm/immap_85xx.h>
#include <asm/fsl_law.h>
#include <fsl_ddr_sdram.h>
#include <asm/fsl_serdes.h>
#include <asm/fsl_portals.h>
#include <asm/fsl_liodn.h>
#include <malloc.h>
#include <fm_eth.h>
#include <fsl_mdio.h>
#include <miiphy.h>
#include <phy.h>
#include <fsl_dtsec.h>
#include <asm/fsl_serdes.h>
#include <hwconfig.h>
#include "../common/qixis.h"
#include "../common/fman.h"
#include "t4240qds_qixis.h"
#define EMI_NONE	0xFFFFFFFF
#define EMI1_RGMII	0
#define EMI1_SLOT1	1
#define EMI1_SLOT2	2
#define EMI1_SLOT3	3
#define EMI1_SLOT4	4
#define EMI1_SLOT5	5
#define EMI1_SLOT7	7
#define EMI2		8
#if defined(CONFIG_FMAN_ENET)
#if (CONFIG_SYS_NUM_FMAN == 2)
#endif /* CONFIG_SYS_NUM_FMAN */
#endif /* CONFIG_FMAN_ENET */
