#include <miiphy.h>
#include <bitfield.h>
#include <time.h>
#include <linux/delay.h>
#define PHY_ID_VSC8530                  0x00070560
#define PHY_ID_VSC8531                  0x00070570
#define PHY_ID_VSC8540                  0x00070760
#define PHY_ID_VSC8541                  0x00070770
#define PHY_ID_VSC8574			0x000704a0
#define PHY_ID_VSC8584                  0x000707c0
#define MSCC_EXT_PAGE_ACCESS            31     /* Page Access Register */
#define MSCC_PHY_PAGE_STD		0x0000 /* Standard registers */
#define MSCC_PHY_PAGE_EXT1		0x0001 /* Extended registers - page 1 */
#define MSCC_PHY_PAGE_EXT2		0x0002 /* Extended registers - page 2 */
#define MSCC_PHY_PAGE_EXT3		0x0003 /* Extended registers - page 3 */
#define MSCC_PHY_PAGE_EXT4		0x0004 /* Extended registers - page 4 */
#define MSCC_PHY_PAGE_GPIO		0x0010 /* GPIO registers */
#define MSCC_PHY_PAGE_TEST		0x2A30 /* TEST Page registers */
#define MSCC_PHY_PAGE_TR		0x52B5 /* Token Ring Page registers */
#define MSCC_PHY_BYPASS_CONTROL           18
#define PARALLEL_DET_IGNORE_ADVERTISED    BIT(3)
#define MSCC_PHY_EXT_CNTL_STATUS          22
#define SMI_BROADCAST_WR_EN              BIT(0)
#define MSCC_PHY_EXT_PHY_CNTL_2           24
#define MIIM_AUX_CNTRL_STAT_REG		28
#define MIIM_AUX_CNTRL_STAT_ACTIPHY_TO	(0x0004)
#define MIIM_AUX_CNTRL_STAT_F_DUPLEX	(0x0020)
#define MIIM_AUX_CNTRL_STAT_SPEED_MASK	(0x0018)
#define MIIM_AUX_CNTRL_STAT_SPEED_POS	(3)
#define MIIM_AUX_CNTRL_STAT_SPEED_10M	(0x0)
#define MIIM_AUX_CNTRL_STAT_SPEED_100M	(0x1)
#define MIIM_AUX_CNTRL_STAT_SPEED_1000M	(0x2)
#define MSCC_PHY_EXT_PHY_CNTL_1_REG	23
#define MAC_IF_SELECTION_MASK		(0x1800)
#define MAC_IF_SELECTION_GMII		(0)
#define MAC_IF_SELECTION_RMII		(1)
#define MAC_IF_SELECTION_RGMII		(2)
#define MAC_IF_SELECTION_POS		(11)
#define MAC_IF_SELECTION_WIDTH		(2)
#define VSC8584_MAC_IF_SELECTION_MASK     BIT(12)
#define VSC8584_MAC_IF_SELECTION_SGMII    0
#define VSC8584_MAC_IF_SELECTION_1000BASEX 1
#define VSC8584_MAC_IF_SELECTION_POS      12
#define MEDIA_OP_MODE_MASK		  GENMASK(10, 8)
#define MEDIA_OP_MODE_COPPER		  0
#define MEDIA_OP_MODE_SERDES		  1
#define MEDIA_OP_MODE_1000BASEX		  2
#define MEDIA_OP_MODE_100BASEFX		  3
#define MEDIA_OP_MODE_AMS_COPPER_SERDES	  5
#define MEDIA_OP_MODE_AMS_COPPER_1000BASEX	6
#define MEDIA_OP_MODE_AMS_COPPER_100BASEFX	7
#define MEDIA_OP_MODE_POS		  8
#define MSCC_PHY_ACTIPHY_CNTL		  20
#define PHY_ADDR_REVERSED		  BIT(9)
#define MSCC_PHY_EXT_PHY_CNTL_4           23
#define PHY_CNTL_4_ADDR_POS		  11
#define MSCC_PHY_VERIPHY_CNTL_2		25
#define MSCC_PHY_VERIPHY_CNTL_3		26
#define MSCC_PHY_CU_PMD_TX_CNTL         16
#define MSCC_PHY_RGMII_CNTL_REG		20
#define VSC_FAST_LINK_FAIL2_ENA_MASK	(0x8000)
#define RX_CLK_OUT_MASK			(0x0800)
#define RX_CLK_OUT_POS			(11)
#define RX_CLK_OUT_WIDTH		(1)
#define RX_CLK_OUT_NORMAL		(0)
#define RX_CLK_OUT_DISABLE		(1)
#define RGMII_RX_CLK_DELAY_POS		(4)
#define RGMII_RX_CLK_DELAY_WIDTH	(3)
#define RGMII_RX_CLK_DELAY_MASK		(0x0070)
#define RGMII_TX_CLK_DELAY_POS		(0)
#define RGMII_TX_CLK_DELAY_WIDTH	(3)
#define RGMII_TX_CLK_DELAY_MASK		(0x0007)
#define MSCC_PHY_WOL_MAC_CONTROL	27
#define EDGE_RATE_CNTL_POS		(5)
#define EDGE_RATE_CNTL_WIDTH		(3)
#define EDGE_RATE_CNTL_MASK		(0x00E0)
#define RMII_CLK_OUT_ENABLE_POS		(4)
#define RMII_CLK_OUT_ENABLE_WIDTH	(1)
#define RMII_CLK_OUT_ENABLE_MASK	(0x10)
#define MSCC_PHY_SERDES_TX_CRC_ERR_CNT	22
#define MSCC_DW8051_CNTL_STATUS		0
#define MICRO_NSOFT_RESET		BIT(15)
#define RUN_FROM_INT_ROM		BIT(14)
#define AUTOINC_ADDR			BIT(13)
#define PATCH_RAM_CLK			BIT(12)
#define MICRO_PATCH_EN			BIT(7)
#define DW8051_CLK_EN			BIT(4)
#define MICRO_CLK_EN			BIT(3)
#define MICRO_CLK_DIVIDE(x)		((x) >> 1)
#define MSCC_DW8051_VLD_MASK		0xf1ff
#define MSCC_TRAP_ROM_ADDR(x)		((x) * 2 + 1)
#define MSCC_TRAP_ROM_ADDR_SERDES_INIT	0x3eb7
#define MSCC_PATCH_RAM_ADDR(x)		(((x) + 1) * 2)
#define MSCC_PATCH_RAM_ADDR_SERDES_INIT	0x4012
#define MSCC_INT_MEM_ADDR		11
#define MSCC_INT_MEM_CNTL		12
#define READ_SFR			(BIT(14) | BIT(13))
#define READ_PRAM			BIT(14)
#define READ_ROM			BIT(13)
#define READ_RAM			(0x00 << 13)
#define INT_MEM_WRITE_EN		BIT(12)
#define EN_PATCH_RAM_TRAP_ADDR(x)	BIT((x) + 7)
#define INT_MEM_DATA_M			GENMASK(7, 0)
#define INT_MEM_DATA(x)			(INT_MEM_DATA_M & (x))
#define MSCC_PHY_PROC_CMD		  18
#define PROC_CMD_NCOMPLETED		  BIT(15)
#define PROC_CMD_FAILED			  BIT(14)
#define PROC_CMD_SGMII_PORT(x)		  ((x) << 8)
#define PROC_CMD_FIBER_PORT(x)		  BIT(8 + (x) % 4)
#define PROC_CMD_QSGMII_PORT		  (BIT(11) | BIT(10))
#define PROC_CMD_RST_CONF_PORT		  BIT(7)
#define PROC_CMD_RECONF_PORT		  (0 << 7)
#define PROC_CMD_READ_MOD_WRITE_PORT	  BIT(6)
#define PROC_CMD_WRITE			  BIT(6)
#define PROC_CMD_READ			  (0 << 6)
#define PROC_CMD_FIBER_DISABLE		  BIT(5)
#define PROC_CMD_FIBER_100BASE_FX	  BIT(4)
#define PROC_CMD_FIBER_1000BASE_X	  (0 << 4)
#define PROC_CMD_SGMII_MAC		  (BIT(5) | BIT(4))
#define PROC_CMD_QSGMII_MAC		  BIT(5)
#define PROC_CMD_NO_MAC_CONF		  (0x00 << 4)
#define PROC_CMD_1588_DEFAULT_INIT	  BIT(4)
#define PROC_CMD_NOP			  GENMASK(3, 0)
#define PROC_CMD_PHY_INIT		  (BIT(3) | BIT(1))
#define PROC_CMD_CRC16			  BIT(3)
#define PROC_CMD_FIBER_MEDIA_CONF	  BIT(0)
#define PROC_CMD_MCB_ACCESS_MAC_CONF	  (0x0000 << 0)
#define PROC_CMD_NCOMPLETED_TIMEOUT_MS    500
#define MSCC_PHY_MAC_CFG_FASTLINK	  19
#define MAC_CFG_MASK			  GENMASK(15, 14)
#define MAC_CFG_SGMII			  (0x00 << 14)
#define MAC_CFG_QSGMII			  BIT(14)
#define MSCC_PHY_TEST_PAGE_5		5
#define MSCC_PHY_TEST_PAGE_8		8
#define TR_CLK_DISABLE			BIT(15)
#define MSCC_PHY_TEST_PAGE_9		9
#define MSCC_PHY_TEST_PAGE_20		20
#define MSCC_PHY_TEST_PAGE_24		24
#define MSCC_PHY_REG_TR_ADDR_16		16
#define MSCC_PHY_REG_TR_DATA_17		17
#define MSCC_PHY_REG_TR_DATA_18		18
#define MSCC_PHY_TR_16_READ		(0xA000)
#define MSCC_PHY_TR_16_WRITE		(0x8000)
#define MSCC_PHY_TR_LINKDETCTRL_POS	(3)
#define MSCC_PHY_TR_LINKDETCTRL_WIDTH	(2)
#define MSCC_PHY_TR_LINKDETCTRL_VAL	(3)
#define MSCC_PHY_TR_LINKDETCTRL_MASK	(0x0018)
#define MSCC_PHY_TR_LINKDETCTRL_ADDR	(0x07F8)
#define MSCC_PHY_TR_VGATHRESH100_POS	(0)
#define MSCC_PHY_TR_VGATHRESH100_WIDTH	(7)
#define MSCC_PHY_TR_VGATHRESH100_VAL	(0x0018)
#define MSCC_PHY_TR_VGATHRESH100_MASK	(0x007f)
#define MSCC_PHY_TR_VGATHRESH100_ADDR	(0x0FA4)
#define MSCC_PHY_TR_VGAGAIN10_U_POS	(0)
#define MSCC_PHY_TR_VGAGAIN10_U_WIDTH	(1)
#define MSCC_PHY_TR_VGAGAIN10_U_MASK	(0x0001)
#define MSCC_PHY_TR_VGAGAIN10_U_VAL	(0)
#define MSCC_PHY_TR_VGAGAIN10_L_POS	(12)
#define MSCC_PHY_TR_VGAGAIN10_L_WIDTH	(4)
#define MSCC_PHY_TR_VGAGAIN10_L_MASK	(0xf000)
#define MSCC_PHY_TR_VGAGAIN10_L_VAL	(0x0001)
#define MSCC_PHY_TR_VGAGAIN10_ADDR	(0x0F92)
#define MSCC_PHY_RESET_TIMEOUT		(100)
#define MSCC_PHY_MICRO_TIMEOUT		(500)
#define VSC8584_REVB		0x0001
#define MSCC_DEV_REV_MASK	GENMASK(3, 0)
#define MSCC_VSC8574_REVB_INT8051_FW_START_ADDR 0x4000
#define MSCC_VSC8574_REVB_INT8051_FW_CRC	0x29e8
#define MSCC_VSC8584_REVB_INT8051_FW_START_ADDR	0xe800
#define MSCC_VSC8584_REVB_INT8051_FW_CRC	0xfb48