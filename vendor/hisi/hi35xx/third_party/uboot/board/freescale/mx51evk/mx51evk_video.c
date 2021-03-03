#include <common.h>
#include <env.h>
#include <linux/list.h>
#include <asm/gpio.h>
#include <asm/arch/iomux-mx51.h>
#include <linux/fb.h>
#include <ipu_pixfmt.h>
#define MX51EVK_LCD_3V3		IMX_GPIO_NR(4, 9)
#define MX51EVK_LCD_5V		IMX_GPIO_NR(4, 10)
#define MX51EVK_LCD_BACKLIGHT	IMX_GPIO_NR(3, 4)
