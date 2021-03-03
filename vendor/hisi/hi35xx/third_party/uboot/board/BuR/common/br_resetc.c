#include <common.h>
#include <env.h>
#include <errno.h>
#include <i2c.h>
#include <dm/uclass.h>
#include "br_resetc.h"
#define	RSTCTRL_ADDR_PSOC	0x75
#define	RSTCTRL_ADDR_STM32	0x60
#define BMODE_DEFAULTAR		0
#define BMODE_SERVICE		2
#define BMODE_RUN		4
#define BMODE_PME		12
#define BMODE_DIAG		15
#ifdef CONFIG_LCD
#include <lcd.h>
#define LCD_SETCURSOR(x, y)	lcd_position_cursor(x, y)
#define LCD_PUTS(x)		lcd_puts(x)
#else
#define LCD_SETCURSOR(x, y)
#define LCD_PUTS(x)
#endif /* CONFIG_LCD */
