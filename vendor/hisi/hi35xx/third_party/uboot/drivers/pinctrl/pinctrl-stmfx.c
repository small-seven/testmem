#include <common.h>
#include <dm.h>
#include <i2c.h>
#include <asm/gpio.h>
#include <dm/device.h>
#include <dm/device-internal.h>
#include <dm/lists.h>
#include <dm/pinctrl.h>
#include <linux/bitfield.h>
#include <power/regulator.h>
#define STMFX_MAX_GPIO			16
#define STMFX_MAX_AGPIO			8
#define STMFX_REG_CHIP_ID		0x00 /* R */
#define STMFX_REG_FW_VERSION_MSB	0x01 /* R */
#define STMFX_REG_FW_VERSION_LSB	0x02 /* R */
#define STMFX_REG_SYS_CTRL		0x40 /* RW */
#define STMFX_BOOT_TIME_MS 10
#define STMFX_REG_GPIO_STATE		0x10 /* R */
#define STMFX_REG_GPIO_DIR		0x60 /* RW */
#define STMFX_REG_GPIO_TYPE		0x64 /* RW */
#define STMFX_REG_GPIO_PUPD		0x68 /* RW */
#define STMFX_REG_GPO_SET		0x6C /* RW */
#define STMFX_REG_GPO_CLR		0x70 /* RW */
#define STMFX_REG_CHIP_ID_MASK		GENMASK(7, 0)
#define STMFX_REG_SYS_CTRL_GPIO_EN	BIT(0)
#define STMFX_REG_SYS_CTRL_ALTGPIO_EN	BIT(3)
#define STMFX_REG_SYS_CTRL_SWRST	BIT(7)
#define NR_GPIO_REGS			3
#define NR_GPIOS_PER_REG		8
#define get_reg(offset)			((offset) / NR_GPIOS_PER_REG)
#define get_shift(offset)		((offset) % NR_GPIOS_PER_REG)
#define get_mask(offset)		(BIT(get_shift(offset)))
#if CONFIG_IS_ENABLED(PINCONF)
#endif
#define MAX_PIN_NAME_LEN 7
#if CONFIG_IS_ENABLED(PINCONF)
#endif
