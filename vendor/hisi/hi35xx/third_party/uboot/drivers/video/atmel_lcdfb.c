#include <common.h>
#include <atmel_lcd.h>
#include <dm.h>
#include <fdtdec.h>
#include <video.h>
#include <asm/io.h>
#include <asm/arch/gpio.h>
#include <asm/arch/clk.h>
#include <lcd.h>
#include <bmp_layout.h>
#include <atmel_lcdc.h>
#ifdef CONFIG_DM_VIDEO
#endif
#define ATMEL_LCDC_CVAL_DEFAULT		0xc8
#define ATMEL_LCDC_DMA_BURST_LEN	8
#ifndef ATMEL_LCDC_GUARD_TIME
#define ATMEL_LCDC_GUARD_TIME		1
#endif
#if defined(CONFIG_AT91SAM9263)
#define ATMEL_LCDC_FIFO_SIZE		2048
#else
#define ATMEL_LCDC_FIFO_SIZE		512
#endif
#define lcdc_readl(mmio, reg)		__raw_readl((mmio)+(reg))
#define lcdc_writel(mmio, reg, val)	__raw_writel((val), (mmio)+(reg))
#ifndef CONFIG_DM_VIDEO
#if defined(CONFIG_BMP_16BPP) && defined(CONFIG_ATMEL_LCD_BGR555)
#endif
#ifdef CONFIG_LCD_LOGO
#include <bmp_logo.h>
#ifdef CONFIG_ATMEL_LCD_BGR555
#else
#endif
#endif
#if defined(CONFIG_ATMEL_LCD_BGR555)
#else
#endif
#endif
#ifndef CONFIG_DM_VIDEO
#endif
#ifdef CONFIG_DM_VIDEO
#endif
