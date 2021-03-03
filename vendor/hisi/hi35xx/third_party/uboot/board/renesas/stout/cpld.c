#include <common.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include "cpld.h"
#define SCLK			(92 + 24)
#define SSTBZ			(92 + 25)
#define MOSI			(92 + 26)
#define MISO			(92 + 27)
#define CPLD_ADDR_MODE		0x00 /* RW */
#define CPLD_ADDR_MUX		0x01 /* RW */
#define CPLD_ADDR_HDMI		0x02 /* RW */
#define CPLD_ADDR_DIPSW		0x08 /* R */
#define CPLD_ADDR_RESET		0x80 /* RW */
#define CPLD_ADDR_VERSION	0xFF /* R */
#define PUPR3		0xe606010C
#define PUPR3_SD3_DAT1	(1 << 27)
#ifdef CONFIG_SH_SDHI
#endif
