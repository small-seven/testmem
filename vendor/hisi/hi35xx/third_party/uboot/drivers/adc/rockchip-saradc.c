#include <common.h>
#include <adc.h>
#include <clk.h>
#include <dm.h>
#include <errno.h>
#include <asm/io.h>
#define SARADC_CTRL_CHN_MASK		GENMASK(2, 0)
#define SARADC_CTRL_POWER_CTRL		BIT(3)
#define SARADC_CTRL_IRQ_ENABLE		BIT(5)
#define SARADC_CTRL_IRQ_STATUS		BIT(6)
#define SARADC_TIMEOUT			(100 * 1000)
