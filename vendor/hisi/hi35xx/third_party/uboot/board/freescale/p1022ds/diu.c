#include <common.h>
#include <command.h>
#include <linux/ctype.h>
#include <asm/io.h>
#include <stdio_dev.h>
#include <video_fb.h>
#include "../common/ngpixis.h"
#include <fsl_diu_fb.h>
#define PX_CTL_ALTACC		0x80
#define PX_BRDCFG0_ELBC_SPI_MASK	0xc0
#define PX_BRDCFG0_ELBC_SPI_ELBC	0x00
#define PX_BRDCFG0_ELBC_SPI_NULL	0xc0
#define PX_BRDCFG0_ELBC_DIU		0x02
#define PX_BRDCFG1_DVIEN	0x80
#define PX_BRDCFG1_DFPEN	0x40
#define PX_BRDCFG1_BACKLIGHT	0x20
#define PMUXCR_ELBCDIU_MASK	0xc0000000
#define PMUXCR_ELBCDIU_NOR16	0x80000000
#define PMUXCR_ELBCDIU_DIU	0x40000000
#define AD_BYTE_F		0x10000000
#define AD_ALPHA_C_SHIFT	25
#define AD_BLUE_C_SHIFT		23
#define AD_GREEN_C_SHIFT	21
#define AD_RED_C_SHIFT		19
#define AD_PIXEL_S_SHIFT	16
#define AD_COMP_3_SHIFT		12
#define AD_COMP_2_SHIFT		8
#define AD_COMP_1_SHIFT		4
#define AD_COMP_0_SHIFT		0
#ifdef CONFIG_PHYS_64BIT
#else
#endif
#ifdef CONFIG_CFI_FLASH_USE_WEAK_ACCESSORS
#endif
