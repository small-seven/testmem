#include <common.h>
#include <command.h>
#include <malloc.h>
#include <asm/io.h>
#include <linux/errno.h>
#include <i2c.h>
#define IO_CONFIG_REG26     0x1F000068
#define IO_CONFIG_REG27     0x1F00006C
#define IO_CONFIG_REG31     0x1F00007C
#define IO_CONFIG_REG32     0x1F000080
#define I2C10_EN_MASK           BIT(1)
#define I2C_EN_MASK           (BIT(1) | BIT(0))
#define I2C_SPEED_100K  100000
