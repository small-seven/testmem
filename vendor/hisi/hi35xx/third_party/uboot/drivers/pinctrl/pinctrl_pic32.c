#include <common.h>
#include <dm.h>
#include <errno.h>
#include <asm/io.h>
#include <dm/pinctrl.h>
#include <mach/pic32.h>
#define PIN_CONFIG_PIC32_DIGITAL	(PIN_CONFIG_END + 1)
#define PIN_CONFIG_PIC32_ANALOG		(PIN_CONFIG_END + 2)
#define PIN_CONFIG(_prt, _pin, _cfg) \
#define PPS_OUT(__port, __pin) \
