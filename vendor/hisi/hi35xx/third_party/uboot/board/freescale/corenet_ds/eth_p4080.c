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
#include "../common/ngpixis.h"
#include "../common/fman.h"
#include <fsl_dtsec.h>
#define EMI_NONE	0xffffffff
#define EMI_MASK	0xf0000000
#define EMI1_RGMII	0x0
#define EMI1_SLOT3	0x80000000	/* bank1 EFGH */
#define EMI1_SLOT4	0x40000000	/* bank2 ABCD */
#define EMI1_SLOT5	0xc0000000	/* bank3 ABCD */
#define EMI2_SLOT4	0x10000000	/* bank2 ABCD */
#define EMI2_SLOT5	0x30000000	/* bank3 ABCD */
#define EMI1_MASK	0xc0000000
#define EMI2_MASK	0x30000000
#define PHY_BASE_ADDR	0x00
#define PHY_BASE_ADDR_SLOT5	0x10
#if defined(CONFIG_SYS_P4080_ERRATUM_SERDES9) && defined(CONFIG_PHY_TERANETICS)
#endif
#ifdef CONFIG_FMAN_ENET
#if (CONFIG_SYS_NUM_FMAN == 2)
#endif
#if (CONFIG_SYS_NUM_FMAN == 2)
#endif
#endif /* CONFIG_FMAN_ENET */
