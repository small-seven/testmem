#include <common.h>
#include <config.h>
#include <errno.h>
#include <dm.h>
#include <dm/pinctrl.h>
#include <dm/root.h>
#include <dm/device-internal.h>
#include <dm/lists.h>
#include <asm/system.h>
#include <asm/io.h>
#include <asm/gpio.h>
#define MAX_PINS_PER_BANK 16
#if !CONFIG_IS_ENABLED(OF_CONTROL) || CONFIG_IS_ENABLED(OF_BOARD)
#endif
