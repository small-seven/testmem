#include <common.h>
#include <clk-uclass.h>
#include <div64.h>
#include <dm.h>
#include <linux/io.h>
#define CGU_ARC_IDIV		0x080
#define CGU_TUN_IDIV_TUN	0x380
#define CGU_TUN_IDIV_ROM	0x390
#define CGU_TUN_IDIV_PWM	0x3A0
#define CGU_HDMI_IDIV_APB	0x480
#define CGU_SYS_IDIV_APB	0x180
#define CGU_SYS_IDIV_AXI	0x190
#define CGU_SYS_IDIV_ETH	0x1A0
#define CGU_SYS_IDIV_USB	0x1B0
#define CGU_SYS_IDIV_SDIO	0x1C0
#define CGU_SYS_IDIV_HDMI	0x1D0
#define CGU_SYS_IDIV_GFX_CORE	0x1E0
#define CGU_SYS_IDIV_GFX_DMA	0x1F0
#define CGU_SYS_IDIV_GFX_CFG	0x200
#define CGU_SYS_IDIV_DMAC_CORE	0x210
#define CGU_SYS_IDIV_DMAC_CFG	0x220
#define CGU_SYS_IDIV_SDIO_REF	0x230
#define CGU_SYS_IDIV_SPI_REF	0x240
#define CGU_SYS_IDIV_I2C_REF	0x250
#define CGU_SYS_IDIV_UART_REF	0x260
#define CGU_SYS_IDIV_EBI_REF	0x270
#define CGU_IDIV_MASK		0xFF /* All idiv have 8 significant bits */
#define CGU_ARC_PLL		0x0
#define CGU_SYS_PLL		0x10
#define CGU_DDR_PLL		0x20
#define CGU_TUN_PLL		0x30
#define CGU_HDMI_PLL		0x40
#define CGU_PLL_CTRL		0x000 /* ARC PLL control register */
#define CGU_PLL_STATUS		0x004 /* ARC PLL status register */
#define CGU_PLL_FMEAS		0x008 /* ARC PLL frequency measurement register */
#define CGU_PLL_MON		0x00C /* ARC PLL monitor register */
#define CGU_PLL_CTRL_ODIV_SHIFT		2
#define CGU_PLL_CTRL_IDIV_SHIFT		4
#define CGU_PLL_CTRL_FBDIV_SHIFT	9
#define CGU_PLL_CTRL_BAND_SHIFT		20
#define CGU_PLL_CTRL_ODIV_MASK		GENMASK(3, CGU_PLL_CTRL_ODIV_SHIFT)
#define CGU_PLL_CTRL_IDIV_MASK		GENMASK(8, CGU_PLL_CTRL_IDIV_SHIFT)
#define CGU_PLL_CTRL_FBDIV_MASK		GENMASK(15, CGU_PLL_CTRL_FBDIV_SHIFT)
#define CGU_PLL_CTRL_PD			BIT(0)
#define CGU_PLL_CTRL_BYPASS		BIT(1)
#define CGU_PLL_STATUS_LOCK		BIT(0)
#define CGU_PLL_STATUS_ERR		BIT(1)
#define HSDK_PLL_MAX_LOCK_TIME		100 /* 100 us */
#define CREG_CORE_IF_DIV		0x000 /* ARC CORE interface divider */
#define CORE_IF_CLK_THRESHOLD_HZ	500000000
#define CREG_CORE_IF_CLK_DIV_1		0x0
#define CREG_CORE_IF_CLK_DIV_2		0x1
#define MIN_PLL_RATE			100000000 /* 100 MHz */
#define PARENT_RATE			33333333 /* fixed clock - xtal */
#define CGU_MAX_CLOCKS			26
#define CGU_SYS_CLOCKS			16
#define MAX_AXI_CLOCKS			4
#define CGU_TUN_CLOCKS			3
#define MAX_TUN_CLOCKS			6
