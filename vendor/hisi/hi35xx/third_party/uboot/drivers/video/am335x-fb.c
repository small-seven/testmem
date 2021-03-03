#include <common.h>
#include <asm/io.h>
#include <asm/arch/hardware.h>
#include <asm/arch/omap.h>
#include <asm/arch/clock.h>
#include <asm/arch/sys_proto.h>
#include <lcd.h>
#include "am335x-fb.h"
#if !defined(LCD_CNTL_BASE)
#error "hw-base address of LCD-Controller (LCD_CNTL_BASE) not defined!"
#endif
#define LCDC_FMAX				200000000
#define LCD_CLK_DIVISOR(x)			((x) << 8)
#define LCD_RASTER_MODE				0x01
#define LCD_CORECLKEN				(0x01 << 0)
#define LCD_LIDDCLKEN				(0x01 << 1)
#define LCD_DMACLKEN				(0x01 << 2)
#define LCD_DMA_BURST_SIZE(x)			((x) << 4)
#define LCD_DMA_BURST_1				0x0
#define LCD_DMA_BURST_2				0x1
#define LCD_DMA_BURST_4				0x2
#define LCD_DMA_BURST_8				0x3
#define LCD_DMA_BURST_16			0x4
#define LCD_HBPLSB(x)				((((x)-1) & 0xFF) << 24)
#define LCD_HFPLSB(x)				((((x)-1) & 0xFF) << 16)
#define LCD_HSWLSB(x)				((((x)-1) & 0x3F) << 10)
#define LCD_HORLSB(x)				(((((x) >> 4)-1) & 0x3F) << 4)
#define LCD_HORMSB(x)				(((((x) >> 4)-1) & 0x40) >> 4)
#define LCD_VBP(x)				((x) << 24)
#define LCD_VFP(x)				((x) << 16)
#define LCD_VSW(x)				(((x)-1) << 10)
#define LCD_VERLSB(x)				(((x)-1) & 0x3FF)
#define LCD_HSWMSB(x)				((((x)-1) & 0x3C0) << 21)
#define LCD_VERMSB(x)				((((x)-1) & 0x400) << 16)
#define LCD_HBPMSB(x)				((((x)-1) & 0x300) >> 4)
#define LCD_HFPMSB(x)				((((x)-1) & 0x300) >> 8)
#define LCD_INVMASK(x)				((x) & 0x3F00000)
#define LCD_TFT_24BPP_MODE			(1 << 25)
#define LCD_TFT_24BPP_UNPACK			(1 << 26)
#define LCD_PALMODE_RAWDATA			(0x02 << 20)
#define LCD_TFT_MODE				(0x01 << 7)
#define LCD_RASTER_ENABLE			(0x01 << 0)
#define FBSIZE(x)	((x->hactive * x->vactive * x->bpp) >> 3)
