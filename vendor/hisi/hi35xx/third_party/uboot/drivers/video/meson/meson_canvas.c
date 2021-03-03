#include "meson_vpu.h"
#define DMC_CAV_LUT_DATAL	0x48 /* 0x12 offset in data sheet */
#define CANVAS_WIDTH_LBIT	29
#define CANVAS_WIDTH_LWID	3
#define DMC_CAV_LUT_DATAH	0x4c /* 0x13 offset in data sheet */
#define CANVAS_WIDTH_HBIT	0
#define CANVAS_HEIGHT_BIT	9
#define CANVAS_BLKMODE_BIT	24
#define DMC_CAV_LUT_ADDR	0x50 /* 0x14 offset in data sheet */
#define CANVAS_LUT_WR_EN	(0x2 << 8)
#define CANVAS_LUT_RD_EN	(0x1 << 8)
