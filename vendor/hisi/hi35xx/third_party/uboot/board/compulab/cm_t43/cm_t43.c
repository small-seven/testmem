#include <common.h>
#include <i2c.h>
#include <miiphy.h>
#include <cpsw.h>
#include <asm/gpio.h>
#include <asm/arch/sys_proto.h>
#include <asm/emif.h>
#include <power/pmic.h>
#include <power/tps65218.h>
#include "board.h"
#include <usb.h>
#include <asm/omap_common.h>
#ifdef CONFIG_DRIVER_TI_CPSW
#define GPIO_PHY1_RST		170
#define GPIO_PHY2_RST		168
#endif
