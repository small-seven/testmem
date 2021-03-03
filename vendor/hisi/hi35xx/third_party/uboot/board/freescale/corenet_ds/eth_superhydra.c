#include <common.h>
#include <netdev.h>
#include <asm/fsl_serdes.h>
#include <fm_eth.h>
#include <fsl_mdio.h>
#include <malloc.h>
#include <fdt_support.h>
#include <fsl_dtsec.h>
#include "../common/ngpixis.h"
#include "../common/fman.h"
#ifdef CONFIG_FMAN_ENET
#define BRDCFG1_EMI1_SEL_MASK	0x70
#define BRDCFG1_EMI1_SEL_SLOT1	0x10
#define BRDCFG1_EMI1_SEL_SLOT2	0x20
#define BRDCFG1_EMI1_SEL_SLOT5	0x30
#define BRDCFG1_EMI1_SEL_SLOT6	0x40
#define BRDCFG1_EMI1_SEL_SLOT7	0x50
#define BRDCFG1_EMI1_SEL_SLOT3	0x60
#define BRDCFG1_EMI1_SEL_RGMII	0x00
#define BRDCFG1_EMI1_EN		0x08
#define BRDCFG1_EMI2_SEL_MASK	0x06
#define BRDCFG1_EMI2_SEL_SLOT1	0x00
#define BRDCFG1_EMI2_SEL_SLOT2	0x02
#define BRDCFG2_REG_GPIO_SEL	0x20
#define PHY_BASE_ADDR		0x00
#define REGNUM			0x00
#define PORT_NUM_FM1		0x04
#define PORT_NUM_FM2		0x02
#define PIXIS_SW2_LANE_23_SEL		0x80
#define PIXIS_SW2_LANE_45_SEL		0x40
#define PIXIS_SW2_LANE_67_SEL_MASK	0x30
#define PIXIS_SW2_LANE_67_SEL_5		0x00
#define PIXIS_SW2_LANE_67_SEL_6		0x20
#define PIXIS_SW2_LANE_67_SEL_7		0x10
#define PIXIS_SW2_LANE_8_SEL		0x08
#define PIXIS_SW2_LANE_1617_SEL		0x04
#define PIXIS_SW11_LANE_9_SEL		0x04
#endif /* #ifdef CONFIG_FMAN_ENET */
#ifdef CONFIG_FMAN_ENET
#if CONFIG_SYS_NUM_FMAN == 2
#endif /* CONFIG_SYS_NUM_FMAN == 2 */
#endif /* CONFIG_FMAN_ENET */
#ifdef CONFIG_FMAN_ENET
#if (CONFIG_SYS_NUM_FMAN == 2)
#endif
#if (CONFIG_SYS_NUM_FMAN == 2)
#endif
#endif
