#include <common.h>
#include <dm.h>
#include <errno.h>
#include <i2c.h>
#include <asm/io.h>
#include <clk.h>
#include <linux/io.h>
#define I2C_CONTROL_REG		0x00
#define I2C_SET_REG		0x00
#define I2C_CLEAR_REG		0x04
#define SCL	BIT(0)
#define SDA	BIT(1)
