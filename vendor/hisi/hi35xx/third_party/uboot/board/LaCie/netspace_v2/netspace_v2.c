#include <common.h>
#include <command.h>
#include <env.h>
#include <asm/mach-types.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include <asm/arch/mpp.h>
#include <asm/arch/gpio.h>
#include "netspace_v2.h"
#include "../common/common.h"
#if defined(CONFIG_MISC_INIT_R)
#if defined(CONFIG_CMD_I2C) && defined(CONFIG_SYS_I2C_EEPROM_ADDR)
#endif
#endif
#if defined(CONFIG_CMD_NET) && defined(CONFIG_RESET_PHY_R)
#if defined(CONFIG_NETSPACE_LITE_V2) || defined(CONFIG_NETSPACE_MINI_V2)
#else
#endif
#endif
#if defined(CONFIG_KIRKWOOD_GPIO)
#endif
