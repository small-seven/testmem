#include <common.h>
#include <memalign.h>
#include <video_fb.h>
#include <linux/list.h>
#include <linux/fb.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <asm/arch/hardware.h>
#include "videomodes.h"
#include "da8xx-fb.h"
#if !defined(DA8XX_LCD_CNTL_BASE)
#define DA8XX_LCD_CNTL_BASE	DAVINCI_LCD_CNTL_BASE
#endif
#define DRIVER_NAME "da8xx_lcdc"
#define LCD_VERSION_1	1
#define LCD_VERSION_2	2
#define LCD_END_OF_FRAME1		(1 << 9)
#define LCD_END_OF_FRAME0		(1 << 8)
#define LCD_PL_LOAD_DONE		(1 << 6)
#define LCD_FIFO_UNDERFLOW		(1 << 5)
#define LCD_SYNC_LOST			(1 << 2)
#define LCD_DMA_BURST_SIZE(x)		((x) << 4)
#define LCD_DMA_BURST_1			0x0
#define LCD_DMA_BURST_2			0x1
#define LCD_DMA_BURST_4			0x2
#define LCD_DMA_BURST_8			0x3
#define LCD_DMA_BURST_16		0x4
#define LCD_V1_END_OF_FRAME_INT_ENA	(1 << 2)
#define LCD_V2_END_OF_FRAME0_INT_ENA	(1 << 8)
#define LCD_V2_END_OF_FRAME1_INT_ENA	(1 << 9)
#define LCD_DUAL_FRAME_BUFFER_ENABLE	(1 << 0)
#define LCD_V2_TFT_24BPP_MODE		(1 << 25)
#define LCD_V2_TFT_24BPP_UNPACK		(1 << 26)
#define LCD_CLK_DIVISOR(x)		((x) << 8)
#define LCD_RASTER_MODE			0x01
#define LCD_PALETTE_LOAD_MODE(x)	((x) << 20)
#define PALETTE_AND_DATA		0x00
#define PALETTE_ONLY			0x01
#define DATA_ONLY			0x02
#define LCD_MONO_8BIT_MODE		(1 << 9)
#define LCD_RASTER_ORDER		(1 << 8)
#define LCD_TFT_MODE			(1 << 7)
#define LCD_V1_UNDERFLOW_INT_ENA	(1 << 6)
#define LCD_V2_UNDERFLOW_INT_ENA	(1 << 5)
#define LCD_V1_PL_INT_ENA		(1 << 4)
#define LCD_V2_PL_INT_ENA		(1 << 6)
#define LCD_MONOCHROME_MODE		(1 << 1)
#define LCD_RASTER_ENABLE		(1 << 0)
#define LCD_TFT_ALT_ENABLE		(1 << 23)
#define LCD_STN_565_ENABLE		(1 << 24)
#define LCD_V2_DMA_CLK_EN		(1 << 2)
#define LCD_V2_LIDD_CLK_EN		(1 << 1)
#define LCD_V2_CORE_CLK_EN		(1 << 0)
#define LCD_V2_LPP_B10			26
#define LCD_V2_TFT_24BPP_MODE		(1 << 25)
#define LCD_V2_TFT_24BPP_UNPACK		(1 << 26)
#define LCD_AC_BIAS_TRANSITIONS_PER_INT(x)	((x) << 16)
#define LCD_AC_BIAS_FREQUENCY(x)		((x) << 8)
#define LCD_SYNC_CTRL				(1 << 25)
#define LCD_SYNC_EDGE				(1 << 24)
#define LCD_INVERT_PIXEL_CLOCK			(1 << 22)
#define LCD_INVERT_LINE_CLOCK			(1 << 21)
#define LCD_INVERT_FRAME_CLOCK			(1 << 20)
#define  LCD_CLK_MAIN_RESET			(1 << 3)
#define LCD_NUM_BUFFERS	1
#define WSI_TIMEOUT	50
#define PALETTE_SIZE	256
#define LEFT_MARGIN	64
#define RIGHT_MARGIN	64
#define UPPER_MARGIN	32
#define LOWER_MARGIN	32
#define WAIT_FOR_FRAME_DONE	true
#define NO_WAIT_FOR_FRAME_DONE	false
#define calc_fbsize() (panel.plnSizeX * panel.plnSizeY * panel.gdfBytesPP)
#if (LCD_NUM_BUFFERS == 2)
#else
#endif
