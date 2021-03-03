#include <common.h>
#include <clk.h>
#include <dm.h>
#include <errno.h>
#include <i2c.h>
#include <asm/io.h>
#include <asm/arch-rockchip/clock.h>
#include <asm/arch-rockchip/i2c.h>
#include <asm/arch-rockchip/periph.h>
#include <dm/pinctrl.h>
#include <linux/sizes.h>
#define I2C_TIMEOUT_MS		100
#define I2C_RETRY_COUNT		3
#define RK_I2C_FIFO_SIZE	32
#ifdef DEBUG
#endif
