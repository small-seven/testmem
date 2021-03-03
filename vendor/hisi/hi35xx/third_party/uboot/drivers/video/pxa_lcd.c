#include <common.h>
#include <asm/arch/pxa-regs.h>
#include <asm/io.h>
#include <lcd.h>
#include <linux/types.h>
#include <stdarg.h>
#include <stdio_dev.h>
#ifdef CONFIG_LCD
#ifdef CONFIG_PXA_VGA
# define LCD_BPP	LCD_COLOR8
# define REG_LCCR0	0x003008f8
# define REG_LCCR3	0x0300FF01
#endif /* CONFIG_PXA_VIDEO */
#ifdef CONFIG_SHARP_LM8V31
# define LCD_BPP	LCD_COLOR8
# define LCD_INVERT_COLORS	/* Needed for colors to be correct, but why?	*/
# define REG_LCCR0	0x0030087C
# define REG_LCCR3	0x0340FF08
#endif /* CONFIG_SHARP_LM8V31 */
#ifdef CONFIG_VOIPAC_LCD
# define LCD_BPP	LCD_COLOR8
# define LCD_INVERT_COLORS
# define REG_LCCR0	0x043008f8
# define REG_LCCR3	0x0340FF08
#endif /* CONFIG_VOIPAC_LCD */
#ifdef CONFIG_HITACHI_SX14
#define LCD_BPP		LCD_COLOR8
#define REG_LCCR0	0x00301079
#define REG_LCCR3	0x0340FF20
#endif /* CONFIG_HITACHI_SX14 */
#ifdef CONFIG_LMS283GF05
# define LCD_BPP	LCD_COLOR8
# define REG_LCCR0	0x043008f8
# define REG_LCCR3	0x03b00009
#endif /* CONFIG_LMS283GF05 */
#ifdef CONFIG_ACX517AKN
# define LCD_BPP	LCD_COLOR8
# define REG_LCCR0	0x003008f9
# define REG_LCCR3	0x03700006
#endif /* CONFIG_ACX517AKN */
#ifdef CONFIG_ACX544AKN
# define LCD_BPP	LCD_COLOR16
# define REG_LCCR0	0x003008f9
# define REG_LCCR3	0x04700007 /* 16bpp */
#endif /* CONFIG_ACX544AKN */
#ifdef CONFIG_LQ038J7DH53
# define LCD_BPP	LCD_COLOR8
# define REG_LCCR0	0x003008f9
# define REG_LCCR3	0x03700004
#endif /* CONFIG_ACX517AKN */
#ifdef CONFIG_LITTLETON_LCD
# define LCD_BPP	LCD_COLOR8
# define REG_LCCR0	0x003008f8
# define REG_LCCR3	0x0300FF04
#endif /* CONFIG_LITTLETON_LCD */
#if LCD_BPP == LCD_COLOR8
#ifdef LCD_INVERT_COLORS
#else
#endif
#endif /* LCD_COLOR8 */
#ifdef	CONFIG_CPU_MONAHANS
#else
#endif
#ifdef	CONFIG_CPU_MONAHANS
#else
#endif
#endif /* CONFIG_LCD */
