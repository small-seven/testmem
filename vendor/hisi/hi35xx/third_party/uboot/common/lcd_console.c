#include <common.h>
#include <lcd.h>
#include <serial.h>
#include <video_font.h>		/* Get font data, width and height */
#if defined(CONFIG_LCD_LOGO)
#include <bmp_logo.h>
#endif
#if defined(CONFIG_LCD_LOGO) && !defined(CONFIG_LCD_INFO_BELOW_LOGO)
#else
#endif
