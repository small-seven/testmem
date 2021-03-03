#include <common.h>
#include <errno.h>
#include <malloc.h>
#include <miiphy.h>
#include <netdev.h>
#define BRCM_PSEUDO_PHY_ADDR		30
#define B53_N_PORTS			9
#define B53_CTRL_PAGE			0x00 /* Control */
#define B53_MGMT_PAGE			0x02 /* Management Mode */
#define B53_PVLAN_PAGE			0x31
#define B53_PORT_CTRL(i)		(0x00 + (i))
#define   PORT_CTRL_RX_DISABLE		BIT(0)
#define   PORT_CTRL_TX_DISABLE		BIT(1)
#define   PORT_CTRL_RX_BCST_EN		BIT(2) /* Broadcast RX (P8 only) */
#define   PORT_CTRL_RX_MCST_EN		BIT(3) /* Multicast RX (P8 only) */
#define   PORT_CTRL_RX_UCST_EN		BIT(4) /* Unicast RX (P8 only) */
#define B53_SWITCH_MODE			0x0b
#define   SM_SW_FWD_MODE		BIT(0)	/* 1 = Managed Mode */
#define   SM_SW_FWD_EN			BIT(1)	/* Forwarding Enable */
#define B53_PORT_OVERRIDE_CTRL		0x0e
#define   PORT_OVERRIDE_LINK		BIT(0)
#define   PORT_OVERRIDE_FULL_DUPLEX	BIT(1) /* 0 = Half Duplex */
#define   PORT_OVERRIDE_SPEED_S		2
#define   PORT_OVERRIDE_SPEED_10M	(0 << PORT_OVERRIDE_SPEED_S)
#define   PORT_OVERRIDE_SPEED_100M	(1 << PORT_OVERRIDE_SPEED_S)
#define   PORT_OVERRIDE_SPEED_1000M	(2 << PORT_OVERRIDE_SPEED_S)
#define   PORT_OVERRIDE_RV_MII_25	BIT(4)
#define   PORT_OVERRIDE_RX_FLOW		BIT(4)
#define   PORT_OVERRIDE_TX_FLOW		BIT(5)
#define   PORT_OVERRIDE_SPEED_2000M	BIT(6)
#define   PORT_OVERRIDE_EN		BIT(7) /* Use the register contents */
#define B53_RGMII_CTRL_IMP		0x60
#define   RGMII_CTRL_ENABLE_GMII	BIT(7)
#define   RGMII_CTRL_TIMING_SEL		BIT(2)
#define   RGMII_CTRL_DLL_RXC		BIT(1)
#define   RGMII_CTRL_DLL_TXC		BIT(0)
#define B53_SWITCH_CTRL			0x22
#define  B53_MII_DUMB_FWDG_EN		BIT(6)
#define B53_SOFTRESET			0x79
#define   SW_RST			BIT(7)
#define   EN_CH_RST			BIT(6)
#define   EN_SW_RST			BIT(4)
#define B53_FAST_AGE_CTRL		0x88
#define   FAST_AGE_STATIC		BIT(0)
#define   FAST_AGE_DYNAMIC		BIT(1)
#define   FAST_AGE_PORT			BIT(2)
#define   FAST_AGE_VLAN			BIT(3)
#define   FAST_AGE_STP			BIT(4)
#define   FAST_AGE_MC			BIT(5)
#define   FAST_AGE_DONE			BIT(7)
#define B53_PVLAN_PORT_MASK(i)		((i) * 2)
#define REG_MII_PAGE    0x10    /* MII Page register */
#define REG_MII_ADDR    0x11    /* MII Address register */
#define REG_MII_DATA0   0x18    /* MII Data register 0 */
#define REG_MII_DATA1   0x19    /* MII Data register 1 */
#define REG_MII_DATA2   0x1a    /* MII Data register 2 */
#define REG_MII_DATA3   0x1b    /* MII Data register 3 */
#define REG_MII_PAGE_ENABLE     BIT(0)
#define REG_MII_ADDR_WRITE      BIT(0)
#define REG_MII_ADDR_READ       BIT(1)
