#include <common.h>
#include <dm.h>
#include <i2c.h>
#include <power/regulator.h>
#define TPS62360_REG_SET0	0
#define TPS62360_I2C_CHIP	0x60
#define TPS62360_VSEL_STEPSIZE	10000 /* In uV */
