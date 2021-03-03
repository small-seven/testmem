#include <common.h>
#include <spi.h>
#include <dm.h>
#include <div64.h>
#include <errno.h>
#include <time.h>
#include <asm/io.h>
#include <asm/addrspace.h>
#include <asm/types.h>
#include <dm/pinctrl.h>
#include <mach/ar71xx_regs.h>
#define ATH79_SPI_CLK_DIV(x)           (((x) >> 1) - 1)
#define ATH79_SPI_RRW_DELAY_FACTOR     12000
#define ATH79_SPI_MHZ                  (1000 * 1000)
