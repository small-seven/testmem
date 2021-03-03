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
#include <hwconfig.h>
#include "../common/qixis.h"
#include "../common/fman.h"
#include "t208xqds_qixis.h"
#define EMI_NONE	0xFFFFFFFF
#define EMI1_RGMII1	0
#define EMI1_RGMII2     1
#define EMI1_SLOT1	2
#if defined(CONFIG_TARGET_T2080QDS)
#define EMI1_SLOT2	6
#define EMI1_SLOT3	3
#define EMI1_SLOT4	4
#define EMI1_SLOT5	5
#define EMI2            7
#elif defined(CONFIG_TARGET_T2081QDS)
#define EMI1_SLOT2      3
#define EMI1_SLOT3      4
#define EMI1_SLOT5      5
#define EMI1_SLOT6      6
#define EMI1_SLOT7      7
#define EMI2		8
#endif
#define PCCR1_SGMIIA_KX_MASK		0x00008000
#define PCCR1_SGMIIB_KX_MASK		0x00004000
#define PCCR1_SGMIIC_KX_MASK		0x00002000
#define PCCR1_SGMIID_KX_MASK		0x00001000
#define PCCR1_SGMIIE_KX_MASK		0x00000800
#define PCCR1_SGMIIF_KX_MASK		0x00000400
#define PCCR1_SGMIIG_KX_MASK		0x00000200
#define PCCR1_SGMIIH_KX_MASK		0x00000100
#if defined(CONFIG_TARGET_T2080QDS)
#elif defined(CONFIG_TARGET_T2081QDS)
#endif
#if defined(CONFIG_TARGET_T2080QDS)
#elif defined(CONFIG_TARGET_T2081QDS)
#endif
#ifdef CONFIG_TARGET_T2080QDS
#endif
#if defined(CONFIG_TARGET_T2080QDS)
#elif defined(CONFIG_TARGET_T2081QDS)
#endif
#if defined(CONFIG_TARGET_T2080QDS)
#elif defined(CONFIG_TARGET_T2081QDS)
#endif
#if defined(CONFIG_FMAN_ENET)
#if defined(CONFIG_TARGET_T2080QDS)
#endif
#if defined(CONFIG_TARGET_T2081QDS)
#endif
#if defined(CONFIG_TARGET_T2080QDS)
#elif defined(CONFIG_TARGET_T2081QDS)
#endif
#if defined(CONFIG_TARGET_T2081QDS)
#endif
#endif /* CONFIG_FMAN_ENET */
