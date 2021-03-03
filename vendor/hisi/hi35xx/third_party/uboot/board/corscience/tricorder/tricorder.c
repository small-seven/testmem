#include <common.h>
#include <twl4030.h>
#include <status_led.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <asm/arch/mmc_host_def.h>
#include <asm/arch/mux.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/mem.h>
#include "tricorder.h"
#include "tricorder-eeprom.h"
#if defined(CONFIG_MMC)
#endif
#if defined(CONFIG_MMC)
#endif
#define MT46H64M32_TDAL  6	/* Twr/Tck + Trp/tck		*/
#define MT46H64M32_TDPL  3	/* 15/6 = 2.5 -> 3 (Twr)	*/
#define MT46H64M32_TRRD  2	/* 12/6 = 2			*/
#define MT46H64M32_TRCD  3	/* 18/6 = 3			*/
#define MT46H64M32_TRP   3	/* 18/6 = 3			*/
#define MT46H64M32_TRAS  7	/* 42/6 = 7			*/
#define MT46H64M32_TRC  10	/* 60/6 = 10			*/
#define MT46H64M32_TRFC 12	/* 72/6 = 12			*/
#define MT46H64M32_TWTR 1
#define MT46H64M32_TCKE 1
#define MT46H64M32_XSR 19	/* 112.5/6 = 18.75 => ~19	*/
#define MT46H64M32_TXP 1
