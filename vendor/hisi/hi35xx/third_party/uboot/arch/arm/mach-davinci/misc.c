#include <common.h>
#include <env.h>
#include <i2c.h>
#include <net.h>
#include <asm/arch/hardware.h>
#include <asm/io.h>
#include <asm/arch/davinci_misc.h>
#ifndef CONFIG_SPL_BUILD
#endif
#ifdef CONFIG_DRIVER_TI_EMAC
#ifdef CONFIG_SYS_I2C_EEPROM_ADDR
#endif /* CONFIG_SYS_I2C_EEPROM_ADDR */
#endif	/* CONFIG_DRIVER_TI_EMAC */
