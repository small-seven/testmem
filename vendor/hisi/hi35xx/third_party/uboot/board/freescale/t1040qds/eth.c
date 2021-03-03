#include <common.h>
#include <netdev.h>
#include <asm/fsl_serdes.h>
#include <asm/immap_85xx.h>
#include <fm_eth.h>
#include <fsl_mdio.h>
#include <malloc.h>
#include <fsl_dtsec.h>
#include <vsc9953.h>
#include "../common/fman.h"
#include "../common/qixis.h"
#include "t1040qds_qixis.h"
#ifdef CONFIG_FMAN_ENET
#define EMI_NONE	0xFFFFFFFF
#define EMI1_RGMII0	0
#define EMI1_RGMII1	1
#define EMI1_SLOT1	2
#define EMI1_SLOT3	3
#define EMI1_SLOT4	4
#define EMI1_SLOT5	5
#define EMI1_SLOT6	6
#define EMI1_SLOT7	7
#define EMI2		8
#endif /* #ifdef CONFIG_FMAN_ENET */
#ifdef CONFIG_FMAN_ENET
#ifdef CONFIG_VSC9953
#endif
#ifdef CONFIG_VSC9953
#endif
#endif
