#include <common.h>
#include <i2c.h>
#include <spi.h>
#include <spi_flash.h>
#include <asm/arch/hardware.h>
#include <asm/arch/pinmux_defs.h>
#include <asm/io.h>
#include <asm/arch/davinci_misc.h>
#include <linux/errno.h>
#include <hwconfig.h>
#include <asm/mach-types.h>
#include <asm/setup.h>
#define EEPROM_I2C_ADDR		0x50
#define EEPROM_REV_OFFSET	0x3F00
#define EEPROM_MAC_OFFSET	0x3F06
