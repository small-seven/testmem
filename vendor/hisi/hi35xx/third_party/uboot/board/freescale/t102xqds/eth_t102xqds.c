#include <common.h>
#include <command.h>
#include <netdev.h>
#include <asm/mmu.h>
#include <asm/processor.h>
#include <asm/immap_85xx.h>
#include <asm/fsl_law.h>
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
#include "../common/qixis.h"
#include "../common/fman.h"
#include "t102xqds_qixis.h"
#define EMI_NONE	0xFFFFFFFF
#define EMI1_RGMII1	0
#define EMI1_RGMII2	1
#define EMI1_SLOT1	2
#define EMI1_SLOT2	3
#define EMI1_SLOT3	4
#define EMI1_SLOT4	5
#define EMI1_SLOT5	6
#define EMI2		7
#if defined(CONFIG_FMAN_ENET)
#endif /* CONFIG_FMAN_ENET */
