#include <common.h>
#include <asm/io.h>
#include <netdev.h>
#include <fdt_support.h>
#include <fm_eth.h>
#include <fsl_mdio.h>
#include <fsl_dtsec.h>
#include <malloc.h>
#include <asm/arch/fsl_serdes.h>
#include "../common/qixis.h"
#include "../common/fman.h"
#include "ls1046aqds_qixis.h"
#define EMI_NONE	0xFF
#define EMI1_RGMII1	0
#define EMI1_RGMII2	1
#define EMI1_SLOT1	2
#define EMI1_SLOT2	3
#define EMI1_SLOT4	4
#ifdef CONFIG_FMAN_ENET
#endif /* CONFIG_FMAN_ENET */
