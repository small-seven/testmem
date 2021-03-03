#include <common.h>
#include <malloc.h>
#include <dm/platform_data/serial_sh.h>
#include <asm/processor.h>
#include <asm/mach-types.h>
#include <asm/io.h>
#include <linux/errno.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/arch/rmobile.h>
#include <asm/arch/rcar-mstp.h>
#include <spl.h>
#define TMU0_MSTP125	BIT(25)
#define SCIFA0_MSTP204	BIT(4)
#define QSPI_MSTP917	BIT(17)
#define SD2CKCR		0xE615026C
#define SD_97500KHZ	0x7
