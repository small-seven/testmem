#include <common.h>
#include <asm/io.h>
#include <clk.h>
#include <dm.h>
#include <i2c.h>
#define I2C_TIMEOUT_MS		100
#define REG_CTRL_START		BIT(0)
#define REG_CTRL_ACK_IGNORE	BIT(1)
#define REG_CTRL_STATUS		BIT(2)
#define REG_CTRL_ERROR		BIT(3)
#define REG_CTRL_CLKDIV_SHIFT	12
#define REG_CTRL_CLKDIV_MASK	GENMASK(21, 12)
#define REG_CTRL_CLKDIVEXT_SHIFT 28
#define REG_CTRL_CLKDIVEXT_MASK	GENMASK(29, 28)
