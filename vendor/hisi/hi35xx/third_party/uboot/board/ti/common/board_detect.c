#include <common.h>
#include <eeprom.h>
#include <asm/arch/hardware.h>
#include <asm/omap_common.h>
#include <dm/uclass.h>
#include <env.h>
#include <i2c.h>
#include "board_detect.h"
#if !defined(CONFIG_DM_I2C)
#endif
#if defined(CONFIG_DM_I2C)
#else
#endif
#ifndef CONFIG_SPL_BUILD
#endif
#ifndef CONFIG_SPL_BUILD
#endif
#if !(defined(CONFIG_SPL_BUILD) && defined(CONFIG_CPU_V7R))
#endif
