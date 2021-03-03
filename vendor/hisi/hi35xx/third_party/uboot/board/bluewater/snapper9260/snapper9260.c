#include <common.h>
#include <dm.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <asm/mach-types.h>
#include <asm/arch/at91sam9260_matrix.h>
#include <asm/arch/at91sam9_smc.h>
#include <asm/arch/at91_common.h>
#include <asm/arch/clk.h>
#include <asm/arch/gpio.h>
#include <asm/arch/atmel_serial.h>
#include <net.h>
#include <netdev.h>
#include <i2c.h>
#include <pca953x.h>
#define IO_EXP_ETH_RESET	(0 << 1)
#define IO_EXP_ETH_POWER	(1 << 1)
