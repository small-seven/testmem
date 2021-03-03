#include <common.h>
#include <cpu_func.h>
#include <env.h>
#include <fdtdec.h>
#include <gzip.h>
#include <version.h>
#include <malloc.h>
#include <video.h>
#include <linux/compiler.h>
#if defined(CONFIG_VIDEO_MXS)
#define VIDEO_FB_16BPP_WORD_SWAP
#endif
#ifdef CONFIG_VIDEO_MB862xx
#ifdef CONFIG_VIDEO_CORALP
#define VIDEO_FB_LITTLE_ENDIAN
#endif
#ifdef CONFIG_VIDEO_MB862xx_ACCEL
#define VIDEO_HW_RECTFILL
#define VIDEO_HW_BITBLT
#endif
#endif
#if defined(CONFIG_VIDEO_MX3) || defined(CONFIG_VIDEO_IPUV3)
#define VIDEO_FB_16BPP_WORD_SWAP
#endif
#include <video_fb.h>
#include <splash.h>
#define VIDEO_VISIBLE_COLS	(pGD->winSizeX)
#define VIDEO_VISIBLE_ROWS	(pGD->winSizeY)
#define VIDEO_PIXEL_SIZE	(pGD->gdfBytesPP)
#define VIDEO_DATA_FORMAT	(pGD->gdfIndex)
#define VIDEO_FB_ADRS		(pGD->frameAdrs)
#include <version.h>
#include <linux/types.h>
#include <stdio_dev.h>
#include <video_font.h>
#if defined(CONFIG_CMD_DATE)
#include <rtc.h>
#endif
#if defined(CONFIG_CMD_BMP) || defined(CONFIG_SPLASH_SCREEN)
#include <watchdog.h>
#include <bmp_layout.h>
#include <splash.h>
#endif
#if !defined(CONFIG_VIDEO_SW_CURSOR)
#define CURSOR_ON
#define CURSOR_OFF
#define CURSOR_SET
#endif
#if defined(CONFIG_VIDEO_SW_CURSOR)
#define CURSOR_ON  console_cursor(1)
#define CURSOR_OFF console_cursor(0)
#define CURSOR_SET video_set_cursor()
#endif /* CONFIG_VIDEO_SW_CURSOR */
#ifdef	CONFIG_VIDEO_LOGO
#ifdef	CONFIG_VIDEO_BMP_LOGO
#include <bmp_logo.h>
#include <bmp_logo_data.h>
#define VIDEO_LOGO_WIDTH	BMP_LOGO_WIDTH
#define VIDEO_LOGO_HEIGHT	BMP_LOGO_HEIGHT
#define VIDEO_LOGO_LUT_OFFSET	BMP_LOGO_OFFSET
#define VIDEO_LOGO_COLORS	BMP_LOGO_COLORS
#else  /* CONFIG_VIDEO_BMP_LOGO */
#define LINUX_LOGO_WIDTH	80
#define LINUX_LOGO_HEIGHT	80
#define LINUX_LOGO_COLORS	214
#define LINUX_LOGO_LUT_OFFSET	0x20
#define __initdata
#include <linux_logo.h>
#define VIDEO_LOGO_WIDTH	LINUX_LOGO_WIDTH
#define VIDEO_LOGO_HEIGHT	LINUX_LOGO_HEIGHT
#define VIDEO_LOGO_LUT_OFFSET	LINUX_LOGO_LUT_OFFSET
#define VIDEO_LOGO_COLORS	LINUX_LOGO_COLORS
#endif /* CONFIG_VIDEO_BMP_LOGO */
#define VIDEO_INFO_X		(VIDEO_LOGO_WIDTH)
#define VIDEO_INFO_Y		(VIDEO_FONT_HEIGHT/2)
#else  /* CONFIG_VIDEO_LOGO */
#define VIDEO_LOGO_WIDTH	0
#define VIDEO_LOGO_HEIGHT	0
#endif /* CONFIG_VIDEO_LOGO */
#define VIDEO_COLS		VIDEO_VISIBLE_COLS
#define VIDEO_ROWS		VIDEO_VISIBLE_ROWS
#ifndef VIDEO_LINE_LEN
#define VIDEO_LINE_LEN		(VIDEO_COLS * VIDEO_PIXEL_SIZE)
#endif
#define VIDEO_SIZE		(VIDEO_ROWS * VIDEO_LINE_LEN)
#define VIDEO_BURST_LEN		(VIDEO_COLS/8)
#ifdef	CONFIG_VIDEO_LOGO
#define CONSOLE_ROWS		((VIDEO_ROWS - video_logo_height) / VIDEO_FONT_HEIGHT)
#else
#define CONSOLE_ROWS		(VIDEO_ROWS / VIDEO_FONT_HEIGHT)
#endif
#define CONSOLE_COLS		(VIDEO_COLS / VIDEO_FONT_WIDTH)
#define CONSOLE_ROW_SIZE	(VIDEO_FONT_HEIGHT * VIDEO_LINE_LEN)
#define CONSOLE_ROW_FIRST	(video_console_address)
#define CONSOLE_ROW_SECOND	(video_console_address + CONSOLE_ROW_SIZE)
#define CONSOLE_ROW_LAST	(video_console_address + CONSOLE_SIZE - CONSOLE_ROW_SIZE)
#define CONSOLE_SIZE		(CONSOLE_ROW_SIZE * CONSOLE_ROWS)
#ifndef CONFIG_CONSOLE_SCROLL_LINES
#define CONFIG_CONSOLE_SCROLL_LINES 1
#endif
#ifdef	VIDEO_FB_LITTLE_ENDIAN
#define SWAP16(x)		((((x) & 0x00ff) << 8) | \
#define SWAP32(x)		((((x) & 0x000000ff) << 24) | \
#define SHORTSWAP32(x)		((((x) & 0x000000ff) <<  8) | \
#else
#define SWAP16(x)		(x)
#define SWAP32(x)		(x)
#if defined(VIDEO_FB_16BPP_WORD_SWAP)
#define SHORTSWAP32(x)		(((x) >> 16) | ((x) << 16))
#else
#define SHORTSWAP32(x)		(x)
#endif
#endif
#ifdef CONFIG_CFB_CONSOLE_ANSI
#endif
#if defined(CONFIG_VIDEO_SW_CURSOR)
#endif
#ifndef VIDEO_HW_RECTFILL
#endif
#ifndef VIDEO_HW_BITBLT
#endif
#ifdef VIDEO_HW_RECTFILL
#else
#endif
#ifdef VIDEO_HW_BITBLT
#else
#endif
#ifdef CONFIG_CFB_CONSOLE_ANSI
#ifdef VIDEO_HW_RECTFILL
#else
#endif
#else
#endif
#ifdef CONFIG_CFB_CONSOLE_ANSI
#else
#endif
#if defined(CONFIG_CMD_BMP) || defined(CONFIG_SPLASH_SCREEN)
#define FILL_8BIT_332RGB(r,g,b)	{			\
#define FILL_15BIT_555RGB(r,g,b) {			\
#define FILL_16BIT_565RGB(r,g,b) {			\
#define FILL_32BIT_X888RGB(r,g,b) {			\
#ifdef VIDEO_FB_LITTLE_ENDIAN
#define FILL_24BIT_888RGB(r,g,b) {			\
#else
#define FILL_24BIT_888RGB(r,g,b) {			\
#endif
#if defined(VIDEO_FB_16BPP_PIXEL_SWAP)
#endif
#ifdef CONFIG_VIDEO_BMP_RLE8
#endif
#ifdef CONFIG_VIDEO_BMP_GZIP
#endif
#ifdef CONFIG_VIDEO_BMP_GZIP
#else
#endif /* CONFIG_VIDEO_BMP_GZIP */
#ifdef CONFIG_VIDEO_BMP_RLE8
#endif
#ifdef CONFIG_VIDEO_BMP_GZIP
#endif
#ifdef CONFIG_SPLASH_SCREEN_ALIGN
#endif /* CONFIG_SPLASH_SCREEN_ALIGN */
#ifdef CONFIG_VIDEO_BMP_RLE8
#endif
#if defined(VIDEO_FB_16BPP_PIXEL_SWAP)
#endif
#if defined(VIDEO_FB_16BPP_PIXEL_SWAP)
#else
#endif
#if defined(VIDEO_FB_16BPP_PIXEL_SWAP)
#endif
#if defined(VIDEO_FB_16BPP_PIXEL_SWAP)
#else
#endif
#ifdef CONFIG_VIDEO_BMP_GZIP
#endif
#endif
#ifdef CONFIG_VIDEO_LOGO
#ifdef CONFIG_SPLASH_SCREEN_ALIGN
#endif /* CONFIG_SPLASH_SCREEN_ALIGN */
#ifdef CONFIG_VIDEO_BMP_LOGO
#else
#endif
#if defined(VIDEO_FB_16BPP_PIXEL_SWAP)
#endif
#if defined(VIDEO_FB_16BPP_PIXEL_SWAP)
#else
#endif
#ifdef VIDEO_FB_LITTLE_ENDIAN
#else
#endif
#ifdef CONFIG_VIDEO_BMP_LOGO
#endif
#ifdef CONFIG_SPLASH_SCREEN
#endif /* CONFIG_SPLASH_SCREEN */
#ifdef CONFIG_SPLASH_SCREEN_ALIGN
#endif
#ifndef CONFIG_HIDE_LOGO_VERSION
#ifdef CONFIG_CONSOLE_EXTRA_INFO
#endif
#endif
#endif
#if defined(CONFIG_ARM) || defined(CONFIG_NDS32) || \
#else
#endif
#ifdef VIDEO_HW_RECTFILL
#else
#endif
#ifdef CONFIG_VIDEO_LOGO
#else
#endif
#if defined(CONFIG_VGA_AS_SINGLE_DEVICE)
#elif defined(CONFIG_OF_CONTROL)
#else
#endif
#if !defined(CONFIG_VGA_AS_SINGLE_DEVICE)
#endif
#if !defined(CONFIG_VGA_AS_SINGLE_DEVICE)
#endif
