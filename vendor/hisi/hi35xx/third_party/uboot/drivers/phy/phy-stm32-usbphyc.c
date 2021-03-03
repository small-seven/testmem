#include <common.h>
#include <clk.h>
#include <div64.h>
#include <dm.h>
#include <fdtdec.h>
#include <generic-phy.h>
#include <reset.h>
#include <syscon.h>
#include <usb.h>
#include <asm/io.h>
#include <linux/bitops.h>
#include <power/regulator.h>
#define STM32_USBPHYC_PLL	0x0
#define STM32_USBPHYC_MISC	0x8
#define PLLNDIV			GENMASK(6, 0)
#define PLLNDIV_SHIFT		0
#define PLLFRACIN		GENMASK(25, 10)
#define PLLFRACIN_SHIFT		10
#define PLLEN			BIT(26)
#define PLLSTRB			BIT(27)
#define PLLSTRBYP		BIT(28)
#define PLLFRACCTL		BIT(29)
#define PLLDITHEN0		BIT(30)
#define PLLDITHEN1		BIT(31)
#define SWITHOST		BIT(0)
#define MAX_PHYS		2
#define PLL_INIT_TIME_US	200
#define PLL_PWR_DOWN_TIME_US	5
#define PLL_FVCO		2880	 /* in MHz */
#define PLL_INFF_MIN_RATE	19200000 /* in Hz */
#define PLL_INFF_MAX_RATE	38400000 /* in Hz */
