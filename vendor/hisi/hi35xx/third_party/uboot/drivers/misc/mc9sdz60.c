#include <config.h>
#include <common.h>
#include <linux/errno.h>
#include <linux/types.h>
#include <i2c.h>
#include <mc9sdz60.h>
#ifndef CONFIG_SYS_FSL_MC9SDZ60_I2C_ADDR
#error "You have to configure I2C address for MC9SDZ60"
#endif
