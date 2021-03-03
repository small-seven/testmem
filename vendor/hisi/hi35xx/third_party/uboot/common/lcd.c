#include <config.h>
#include <common.h>
#include <command.h>
#include <cpu_func.h>
#include <env_callback.h>
#include <linux/types.h>
#include <stdio_dev.h>
#include <lcd.h>
#include <mapmem.h>
#include <watchdog.h>
#include <asm/unaligned.h>
#include <splash.h>
#include <asm/io.h>
#include <asm/unaligned.h>
#include <video_font.h>
#ifdef CONFIG_LCD_LOGO
#include <bmp_logo.h>
#include <bmp_logo_data.h>
#if (CONSOLE_COLOR_WHITE >= BMP_LOGO_OFFSET) && (LCD_BPP != LCD_COLOR16)
#error Default Color Map overlaps with Logo Color Map
#endif
#endif
#ifndef CONFIG_LCD_ALIGNMENT
#define CONFIG_LCD_ALIGNMENT PAGE_SIZE
#endif
#if (LCD_BPP != LCD_COLOR8) && (LCD_BPP != LCD_COLOR16) && \
#error Unsupported LCD BPP.
#endif
#if defined(CONFIG_ARM) && !CONFIG_IS_ENABLED(SYS_DCACHE_OFF)
#endif
#ifdef LCD_TEST_PATTERN
#if LCD_BPP == LCD_COLOR8
#define	N_BLK_VERT	2
#define	N_BLK_HOR	3
#elif LCD_BPP == LCD_COLOR16
#define	N_BLK_VERT	2
#define	N_BLK_HOR	4
#endif /*LCD_BPP == LCD_COLOR16 */
#if LCD_BPP == LCD_COLOR8
#elif LCD_BPP == LCD_COLOR16
#endif
#endif /* LCD_TEST_PATTERN */
#if LCD_BPP == LCD_COLOR8
#endif
#ifndef CONFIG_SYS_WHITE_ON_BLACK
#else
#endif	/* CONFIG_SYS_WHITE_ON_BLACK */
#ifdef	LCD_TEST_PATTERN
#else
#if (LCD_BPP != LCD_COLOR32)
#else
#endif
#endif
#if defined(CONFIG_LCD_LOGO) && !defined(CONFIG_LCD_INFO_BELOW_LOGO)
#endif
#ifdef CONFIG_LCD_INFO_BELOW_LOGO
#else
#endif
#ifdef CONFIG_LCD_LOGO
#else
#endif /* CONFIG_LCD_LOGO */
#if defined(CONFIG_CMD_BMP) || defined(CONFIG_SPLASH_SCREEN)
#ifdef CONFIG_SPLASH_SCREEN_ALIGN
#endif
#ifdef CONFIG_LCD_BMP_RLE8
#define BMP_RLE8_ESCAPE		0
#define BMP_RLE8_EOL		0
#define BMP_RLE8_EOBMP		1
#define BMP_RLE8_DELTA		2
#endif
#if defined(CONFIG_BMP_16BPP)
#endif /* CONFIG_BMP_16BPP */
#ifdef CONFIG_SPLASH_SCREEN_ALIGN
#endif /* CONFIG_SPLASH_SCREEN_ALIGN */
#ifdef CONFIG_LCD_BMP_RLE8
#endif
#if defined(CONFIG_BMP_16BPP)
#endif /* CONFIG_BMP_16BPP */
#if defined(CONFIG_BMP_24BPP)
#endif /* CONFIG_BMP_24BPP */
#if defined(CONFIG_BMP_32BPP)
#endif /* CONFIG_BMP_32BPP */
#endif
#ifdef CONFIG_LCD_INFO
#endif /* CONFIG_LCD_INFO */
#ifdef CONFIG_SPLASHIMAGE_GUARD
#endif
