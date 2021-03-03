#include <asm/io.h>
#include <common.h>
#include <clk.h>
#include <dm.h>
#include <errno.h>
#include <fdtdec.h>
#include <i2c.h>
#include <linux/bitops.h>
#include <mach/clk.h>
#include "at91_i2c.h"
#define I2C_TIMEOUT_MS	100
