#include "regulator_common.h"
#include <common.h>
#include <fdtdec.h>
#include <errno.h>
#include <dm.h>
#include <i2c.h>
#include <asm/gpio.h>
#include <power/pmic.h>
#include <power/regulator.h>
#define GPIO_REGULATOR_MAX_STATES	2
