#include <common.h>
#include <dm.h>
#include <asm/arch/pinmux.h>
#include <asm/arch/gp_padctrl.h>
#include <asm/arch/gpio.h>
#include <asm/gpio.h>
#include "pinmux-config-tamonten-ng.h"
#include <i2c.h>
#define PMU_I2C_ADDRESS		0x2D
#define PMU_REG_LDO5		0x32
#define PMU_REG_LDO_HIGH_POWER	1
#define PMU_REG_LDO_SEL_100(mV)	((((mV - 1000) / 100) + 2) << 2)
#define PMU_REG_LDO_100(st, mV)	(PMU_REG_LDO_##st | PMU_REG_LDO_SEL_100(mV))
#define PMU_LDO5(st, mV)	PMU_REG_LDO_100(st, mV)
