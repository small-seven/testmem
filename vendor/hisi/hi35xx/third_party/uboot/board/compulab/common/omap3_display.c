#include <common.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <env.h>
#include <stdio_dev.h>
#include <asm/arch/dss.h>
#include <lcd.h>
#include <scf0403_lcd.h>
#include <asm/arch-omap3/dss.h>
#define CMAP_ADDR	0x80100000
#define PIXEL_CLK_NUMERATOR (26 * 432 / 39)
#ifdef CONFIG_SCF0403_LCD
#else
#endif
