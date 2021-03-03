#include <common.h>
#include <command.h>
#include <env.h>
#include <i2c.h>
#include <asm/mach-types.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include <asm/arch/mpp.h>
#include <asm/arch/gpio.h>
#include "net2big_v2.h"
#include "../common/common.h"
#include "../common/cpld-gpio-bus.h"
#if defined(CONFIG_MISC_INIT_R)
#if defined(CONFIG_CMD_I2C) && defined(CONFIG_SYS_I2C_G762_ADDR)
#else
#endif /* CONFIG_CMD_I2C && CONFIG_SYS_I2C_G762_ADDR */
#if defined(CONFIG_NET2BIG_V2) && defined(CONFIG_KIRKWOOD_GPIO)
#else
#endif /* CONFIG_NET2BIG_V2 && CONFIG_KIRKWOOD_GPIO */
#if defined(CONFIG_CMD_I2C) && defined(CONFIG_SYS_I2C_EEPROM_ADDR)
#endif
#endif /* CONFIG_MISC_INIT_R */
#if defined(CONFIG_CMD_NET) && defined(CONFIG_RESET_PHY_R)
#endif
#if defined(CONFIG_KIRKWOOD_GPIO)
#endif
