#include <common.h>
#include <config.h>
#include <dm.h>
#include <dm/device-internal.h>
#include <dm/lists.h>
#include <dm/pinctrl.h>
#include <dm/root.h>
#include <errno.h>
#include <fdtdec.h>
#include <linux/io.h>
#include <asm/gpio.h>
#include <asm/system.h>
#include "mscc-common.h"
#define SERVALT_PIN(n) {					\
