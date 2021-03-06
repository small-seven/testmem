#include <common.h>
#include <dm.h>
#include <dm/device.h>
#include <generic-phy.h>
#include <asm/io.h>
#include <asm/arch/sys_proto.h>
#include <syscon.h>
#include <regmap.h>
#define PLL_STATUS              0x00000004
#define PLL_GO                  0x00000008
#define PLL_CONFIGURATION1      0x0000000C
#define PLL_CONFIGURATION2      0x00000010
#define PLL_CONFIGURATION3      0x00000014
#define PLL_CONFIGURATION4      0x00000020
#define PLL_REGM_MASK           0x001FFE00
#define PLL_REGM_SHIFT          9
#define PLL_REGM_F_MASK         0x0003FFFF
#define PLL_REGM_F_SHIFT        0
#define PLL_REGN_MASK           0x000001FE
#define PLL_REGN_SHIFT          1
#define PLL_SELFREQDCO_MASK     0x0000000E
#define PLL_SELFREQDCO_SHIFT    1
#define PLL_SD_MASK             0x0003FC00
#define PLL_SD_SHIFT            10
#define SET_PLL_GO              0x1
#define PLL_TICOPWDN            BIT(16)
#define PLL_LDOPWDN             BIT(15)
#define PLL_LOCK                0x2
#define PLL_IDLE                0x1
#define SATA_PLL_SOFT_RESET (1<<18)
#define PIPE3_PHY_PWRCTL_CLK_CMD_MASK	GENMASK(21, 14)
#define PIPE3_PHY_PWRCTL_CLK_CMD_SHIFT	14
#define PIPE3_PHY_PWRCTL_CLK_FREQ_MASK	GENMASK(31, 22)
#define PIPE3_PHY_PWRCTL_CLK_FREQ_SHIFT	22
#define PIPE3_PHY_RX_POWERON       (0x1 << PIPE3_PHY_PWRCTL_CLK_CMD_SHIFT)
#define PIPE3_PHY_TX_POWERON       (0x2 << PIPE3_PHY_PWRCTL_CLK_CMD_SHIFT)
#define PIPE3_PHY_RX_ANA_PROGRAMMABILITY	0x0000000C
#define INTERFACE_MASK			GENMASK(31, 27)
#define INTERFACE_SHIFT			27
#define INTERFACE_MODE_USBSS		BIT(4)
#define INTERFACE_MODE_SATA_1P5		BIT(3)
#define INTERFACE_MODE_SATA_3P0		BIT(2)
#define INTERFACE_MODE_PCIE		BIT(0)
#define LOSD_MASK			GENMASK(17, 14)
#define LOSD_SHIFT			14
#define MEM_PLLDIV			GENMASK(6, 5)
#define PIPE3_PHY_RX_TRIM		0x0000001C
#define MEM_DLL_TRIM_SEL_MASK		GENMASK(31, 30)
#define MEM_DLL_TRIM_SHIFT		30
#define PIPE3_PHY_RX_DLL		0x00000024
#define MEM_DLL_PHINT_RATE_MASK		GENMASK(31, 30)
#define MEM_DLL_PHINT_RATE_SHIFT	30
#define PIPE3_PHY_RX_DIGITAL_MODES		0x00000028
#define MEM_HS_RATE_MASK		GENMASK(28, 27)
#define MEM_HS_RATE_SHIFT		27
#define MEM_OVRD_HS_RATE		BIT(26)
#define MEM_OVRD_HS_RATE_SHIFT		26
#define MEM_CDR_FASTLOCK		BIT(23)
#define MEM_CDR_FASTLOCK_SHIFT		23
#define MEM_CDR_LBW_MASK		GENMASK(22, 21)
#define MEM_CDR_LBW_SHIFT		21
#define MEM_CDR_STEPCNT_MASK		GENMASK(20, 19)
#define MEM_CDR_STEPCNT_SHIFT		19
#define MEM_CDR_STL_MASK		GENMASK(18, 16)
#define MEM_CDR_STL_SHIFT		16
#define MEM_CDR_THR_MASK		GENMASK(15, 13)
#define MEM_CDR_THR_SHIFT		13
#define MEM_CDR_THR_MODE		BIT(12)
#define MEM_CDR_THR_MODE_SHIFT		12
#define MEM_CDR_2NDO_SDM_MODE		BIT(11)
#define MEM_CDR_2NDO_SDM_MODE_SHIFT	11
#define PIPE3_PHY_RX_EQUALIZER		0x00000038
#define MEM_EQLEV_MASK			GENMASK(31, 16)
#define MEM_EQLEV_SHIFT			16
#define MEM_EQFTC_MASK			GENMASK(15, 11)
#define MEM_EQFTC_SHIFT			11
#define MEM_EQCTL_MASK			GENMASK(10, 7)
#define MEM_EQCTL_SHIFT			7
#define MEM_OVRD_EQLEV			BIT(2)
#define MEM_OVRD_EQLEV_SHIFT		2
#define MEM_OVRD_EQFTC			BIT(1)
#define MEM_OVRD_EQFTC_SHIFT		1
#define SATA_PHY_RX_IO_AND_A2D_OVERRIDES	0x44
#define MEM_CDR_LOS_SOURCE_MASK		GENMASK(10, 9)
#define MEM_CDR_LOS_SOURCE_SHIFT	9
#define PLL_IDLE_TIME   100     /* in milliseconds */
#define PLL_LOCK_TIME   100     /* in milliseconds */
