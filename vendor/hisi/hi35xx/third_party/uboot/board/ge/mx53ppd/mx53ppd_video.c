#include <common.h>
#include <linux/list.h>
#include <asm/gpio.h>
#include <asm/arch/iomux-mx53.h>
#include <linux/fb.h>
#include <ipu_pixfmt.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/imx-regs.h>
#include <asm/io.h>
#include <pwm.h>
#include "ppd_gpio.h"
#define MX53PPD_LCD_POWER		IMX_GPIO_NR(3, 24)
