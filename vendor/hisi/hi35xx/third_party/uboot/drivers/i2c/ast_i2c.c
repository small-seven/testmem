#include <common.h>
#include <clk.h>
#include <dm.h>
#include <errno.h>
#include <fdtdec.h>
#include <i2c.h>
#include <asm/io.h>
#include <asm/arch/scu_ast2500.h>
#include "ast_i2c.h"
#define I2C_TIMEOUT_US 100000
#define I2C_SLEEP_STEP_US 20
#define HIGHSPEED_TTIMEOUT		3
