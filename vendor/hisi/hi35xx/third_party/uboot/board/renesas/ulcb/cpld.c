#include <common.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <dm.h>
#include <errno.h>
#include <linux/err.h>
#include <sysreset.h>
#define CPLD_ADDR_MODE		0x00 /* RW */
#define CPLD_ADDR_MUX		0x02 /* RW */
#define CPLD_ADDR_DIPSW6	0x08 /* R */
#define CPLD_ADDR_RESET		0x80 /* RW */
#define CPLD_ADDR_VERSION	0xFF /* R */
