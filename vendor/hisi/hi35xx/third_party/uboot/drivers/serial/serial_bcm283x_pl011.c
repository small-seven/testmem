#include <common.h>
#include <dm.h>
#include <asm/gpio.h>
#include <dm/pinctrl.h>
#include <dm/platform_data/serial_pl01x.h>
#include <serial.h>
#include "serial_pl01x_internal.h"
#if !CONFIG_IS_ENABLED(OF_CONTROL) || CONFIG_IS_ENABLED(OF_BOARD)
#endif
