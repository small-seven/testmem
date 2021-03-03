#include <common.h>
#include <env.h>
#include <env_internal.h>
#include <net.h>
#include <malloc.h>
#include <netdev.h>
#include <miiphy.h>
#include <spi.h>
#include <spi_flash.h>
#include <asm/arch/soc.h>
#include <asm/arch/cpu.h>
#include <asm/arch/mpp.h>
#include <asm/arch/gpio.h>
#include "lsxl.h"
#ifndef CONFIG_ENV_OVERWRITE
# error "You need to set CONFIG_ENV_OVERWRITE"
#endif
#define LED_OFF             0
#define LED_ALARM_ON        1
#define LED_ALARM_BLINKING  2
#define LED_POWER_ON        3
#define LED_POWER_BLINKING  4
#define LED_INFO_ON         5
#define LED_INFO_BLINKING   6
#ifdef CONFIG_MISC_INIT_R
#endif
#ifdef CONFIG_SHOW_BOOT_PROGRESS
#endif
