#include <eeprom.h>
#include <init.h>
#include <asm/io.h>
#include <common.h>
#include <dm.h>
#include <env.h>
#include <env_internal.h>
#include <i2c.h>
#include <i2c_eeprom.h>
#include <netdev.h>
#include "som.h"
#include <power/regulator.h>
#include <power/rk8xx_pmic.h>
#ifdef CONFIG_SPL_BUILD
#if !defined(CONFIG_SPL_OF_PLATDATA)
#if defined(CONFIG_SPL_POWER_SUPPORT)
#endif
#endif
#if !defined(CONFIG_SPL_OF_PLATDATA)
#endif
#endif
