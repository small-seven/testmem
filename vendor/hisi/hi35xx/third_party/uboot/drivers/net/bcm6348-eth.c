#include <common.h>
#include <clk.h>
#include <dm.h>
#include <dma.h>
#include <miiphy.h>
#include <net.h>
#include <phy.h>
#include <reset.h>
#include <wait_bit.h>
#include <asm/io.h>
#define ETH_RX_DESC			PKTBUFSRX
#define ETH_MAX_MTU_SIZE		1518
#define ETH_TIMEOUT			100
#define ETH_TX_WATERMARK		32
#define ETH_RXCFG_REG			0x00
#define ETH_RXCFG_ENFLOW_SHIFT		5
#define ETH_RXCFG_ENFLOW_MASK		(1 << ETH_RXCFG_ENFLOW_SHIFT)
#define ETH_RXMAXLEN_REG		0x04
#define ETH_RXMAXLEN_SHIFT		0
#define ETH_RXMAXLEN_MASK		(0x7ff << ETH_RXMAXLEN_SHIFT)
#define ETH_TXMAXLEN_REG		0x08
#define ETH_TXMAXLEN_SHIFT		0
#define ETH_TXMAXLEN_MASK		(0x7ff << ETH_TXMAXLEN_SHIFT)
#define MII_SC_REG			0x10
#define MII_SC_MDCFREQDIV_SHIFT		0
#define MII_SC_MDCFREQDIV_MASK		(0x7f << MII_SC_MDCFREQDIV_SHIFT)
#define MII_SC_PREAMBLE_EN_SHIFT	7
#define MII_SC_PREAMBLE_EN_MASK		(1 << MII_SC_PREAMBLE_EN_SHIFT)
#define MII_DAT_REG			0x14
#define MII_DAT_DATA_SHIFT		0
#define MII_DAT_DATA_MASK		(0xffff << MII_DAT_DATA_SHIFT)
#define MII_DAT_TA_SHIFT		16
#define MII_DAT_TA_MASK			(0x3 << MII_DAT_TA_SHIFT)
#define MII_DAT_REG_SHIFT		18
#define MII_DAT_REG_MASK		(0x1f << MII_DAT_REG_SHIFT)
#define MII_DAT_PHY_SHIFT		23
#define MII_DAT_PHY_MASK		(0x1f << MII_DAT_PHY_SHIFT)
#define MII_DAT_OP_SHIFT		28
#define MII_DAT_OP_WRITE		(0x5 << MII_DAT_OP_SHIFT)
#define MII_DAT_OP_READ			(0x6 << MII_DAT_OP_SHIFT)
#define ETH_IRMASK_REG			0x18
#define ETH_IR_REG			0x1c
#define ETH_IR_MII_SHIFT		0
#define ETH_IR_MII_MASK			(1 << ETH_IR_MII_SHIFT)
#define ETH_CTL_REG			0x2c
#define ETH_CTL_ENABLE_SHIFT		0
#define ETH_CTL_ENABLE_MASK		(1 << ETH_CTL_ENABLE_SHIFT)
#define ETH_CTL_DISABLE_SHIFT		1
#define ETH_CTL_DISABLE_MASK		(1 << ETH_CTL_DISABLE_SHIFT)
#define ETH_CTL_RESET_SHIFT		2
#define ETH_CTL_RESET_MASK		(1 << ETH_CTL_RESET_SHIFT)
#define ETH_CTL_EPHY_SHIFT		3
#define ETH_CTL_EPHY_MASK		(1 << ETH_CTL_EPHY_SHIFT)
#define ETH_TXCTL_REG			0x30
#define ETH_TXCTL_FD_SHIFT		0
#define ETH_TXCTL_FD_MASK		(1 << ETH_TXCTL_FD_SHIFT)
#define ETH_TXWMARK_REG			0x34
#define ETH_TXWMARK_WM_SHIFT		0
#define ETH_TXWMARK_WM_MASK		(0x3f << ETH_TXWMARK_WM_SHIFT)
#define MIB_CTL_REG			0x38
#define MIB_CTL_RDCLEAR_SHIFT		0
#define MIB_CTL_RDCLEAR_MASK		(1 << MIB_CTL_RDCLEAR_SHIFT)
#define ETH_PM_CNT			4
#define ETH_PML_REG(x)			(0x58 + (x) * 0x8)
#define ETH_PMH_REG(x)			(0x5c + (x) * 0x8)
#define ETH_PMH_VALID_SHIFT		16
#define ETH_PMH_VALID_MASK		(1 << ETH_PMH_VALID_SHIFT)
#define MIB_REG_CNT			55
#define MIB_REG(x)			(0x200 + (x) * 4)
