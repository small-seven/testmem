#include <common.h>
#include <clk-uclass.h>
#include <dm.h>
#include <dm/device.h>
#include <dm/lists.h>
#include <dt-bindings/phy/phy.h>
#include <generic-phy.h>
#include <asm/io.h>
#include <asm/arch/sys_proto.h>
#include <power-domain.h>
#include <regmap.h>
#include <syscon.h>
#define CMU_R07C		0x7c
#define CMU_MASTER_CDN_O	BIT(24)
#define COMLANE_R138		0xb38
#define CONFIG_VERSION_REG_MASK	GENMASK(23, 16)
#define CONFIG_VERSION_REG_SHIFT 16
#define VERSION			0x70
#define COMLANE_R190		0xb90
#define L1_MASTER_CDN_O		BIT(9)
#define COMLANE_R194		0xb94
#define CMU_OK_I_0		BIT(19)
#define SERDES_CTRL		0x1fd0
#define POR_EN			BIT(29)
#define WIZ_LANEXCTL_STS	0x1fe0
#define TX0_ENABLE_OVL		BIT(31)
#define TX0_ENABLE_MASK		GENMASK(30, 29)
#define TX0_ENABLE_SHIFT	29
#define TX0_DISABLE_STATE	0x0
#define TX0_SLEEP_STATE		0x1
#define TX0_SNOOZE_STATE	0x2
#define TX0_ENABLE_STATE	0x3
#define RX0_ENABLE_OVL		BIT(15)
#define RX0_ENABLE_MASK		GENMASK(14, 13)
#define RX0_ENABLE_SHIFT	13
#define RX0_DISABLE_STATE	0x0
#define RX0_SLEEP_STATE		0x1
#define RX0_SNOOZE_STATE	0x2
#define RX0_ENABLE_STATE	0x3
#define WIZ_PLL_CTRL		0x1ff4
#define PLL_ENABLE_OVL		BIT(31)
#define PLL_ENABLE_MASK		GENMASK(30, 29)
#define PLL_ENABLE_SHIFT	29
#define PLL_DISABLE_STATE	0x0
#define PLL_SLEEP_STATE		0x1
#define PLL_SNOOZE_STATE	0x2
#define PLL_ENABLE_STATE	0x3
#define PLL_OK			BIT(28)
#define PLL_LOCK_TIME		1000	/* in milliseconds */
#define SLEEP_TIME		100	/* in microseconds */
#define LANE_USB3		0x0
#define LANE_PCIE0_LANE0	0x1
#define LANE_PCIE1_LANE0	0x0
#define LANE_PCIE0_LANE1	0x1
#define SERDES_NUM_CLOCKS	3
#define SERDES_CTL_LANE_FUNC_SEL_SHIFT	0
#define SERDES_CTL_LANE_FUNC_SEL_MASK	GENMASK(1, 0)
#define SERDES_CTL_CLK_SEL_SHIFT	4
#define SERDES_CTL_CLK_SEL_MASK		GENMASK(7, 4)
