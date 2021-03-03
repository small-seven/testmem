#include <common.h>
#include <clk.h>
#include <dm.h>
#include <dsi_host.h>
#include <mipi_dsi.h>
#include <panel.h>
#include <reset.h>
#include <video.h>
#include <video_bridge.h>
#include <asm/io.h>
#include <asm/arch/gpio.h>
#include <dm/device-internal.h>
#include <dm/lists.h>
#include <linux/iopoll.h>
#include <power/regulator.h>
#define HWVER_130			0x31333000	/* IP version 1.30 */
#define HWVER_131			0x31333100	/* IP version 1.31 */
#define DSI_VERSION			0x00
#define VERSION				GENMASK(31, 8)
#define DSI_WCFGR	0x0400		/* Wrapper ConFiGuration Reg */
#define WCFGR_DSIM	BIT(0)		/* DSI Mode */
#define WCFGR_COLMUX	GENMASK(3, 1)	/* COLor MUltipleXing */
#define DSI_WCR		0x0404		/* Wrapper Control Reg */
#define WCR_DSIEN	BIT(3)		/* DSI ENable */
#define DSI_WISR	0x040C		/* Wrapper Interrupt and Status Reg */
#define WISR_PLLLS	BIT(8)		/* PLL Lock Status */
#define WISR_RRS	BIT(12)		/* Regulator Ready Status */
#define DSI_WPCR0	0x0418		/* Wrapper Phy Conf Reg 0 */
#define WPCR0_UIX4	GENMASK(5, 0)	/* Unit Interval X 4 */
#define WPCR0_TDDL	BIT(16)		/* Turn Disable Data Lanes */
#define DSI_WRPCR	0x0430		/* Wrapper Regulator & Pll Ctrl Reg */
#define WRPCR_PLLEN	BIT(0)		/* PLL ENable */
#define WRPCR_NDIV	GENMASK(8, 2)	/* pll loop DIVision Factor */
#define WRPCR_IDF	GENMASK(14, 11)	/* pll Input Division Factor */
#define WRPCR_ODF	GENMASK(17, 16)	/* pll Output Division Factor */
#define WRPCR_REGEN	BIT(24)		/* REGulator ENable */
#define WRPCR_BGREN	BIT(28)		/* BandGap Reference ENable */
#define IDF_MIN		1
#define IDF_MAX		7
#define NDIV_MIN	10
#define NDIV_MAX	125
#define ODF_MIN		1
#define ODF_MAX		8
#define LANE_MIN_KBPS	31250
#define LANE_MAX_KBPS	500000
#define TIMEOUT_US	200000
