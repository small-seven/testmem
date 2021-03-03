#include <common.h>
#include <cpu_func.h>
#include <asm/io.h>
#include <asm/arch/gpio.h>
#include <asm/arch/clk.h>
#include <clk.h>
#include <dm.h>
#include <fdtdec.h>
#include <lcd.h>
#include <video.h>
#include <wait_bit.h>
#include <atmel_hlcdc.h>
#if defined(CONFIG_LCD_LOGO)
#include <bmp_logo.h>
#endif
#ifndef CONFIG_DM_VIDEO
#define ATMEL_LCDC_CVAL_DEFAULT		0xc8
#define ATMEL_LCDC_DMA_BURST_LEN	8
#ifndef ATMEL_LCDC_GUARD_TIME
#define ATMEL_LCDC_GUARD_TIME		1
#endif
#define ATMEL_LCDC_FIFO_SIZE		512
#if defined(CONFIG_LCD_LOGO)
#else
#endif
#ifndef LCD_OUTPUT_BPP
#else
#endif
#else
#endif
