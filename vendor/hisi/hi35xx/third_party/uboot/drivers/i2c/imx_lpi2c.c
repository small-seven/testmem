#include <common.h>
#include <errno.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <imx_lpi2c.h>
#include <asm/arch/sys_proto.h>
#include <dm.h>
#include <fdtdec.h>
#include <i2c.h>
#define LPI2C_FIFO_SIZE 4
#define LPI2C_NACK_TOUT_MS 1
#define LPI2C_TIMEOUT_MS 100
