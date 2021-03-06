#include "meson_vpu.h"
#define OSD_CANVAS_SEL		16
#define OSD_ENDIANNESS_LE	BIT(15)
#define OSD_ENDIANNESS_BE	(0)
#define OSD_BLK_MODE_422	(0x03 << 8)
#define OSD_BLK_MODE_16		(0x04 << 8)
#define OSD_BLK_MODE_32		(0x05 << 8)
#define OSD_BLK_MODE_24		(0x07 << 8)
#define OSD_OUTPUT_COLOR_RGB	BIT(7)
#define OSD_OUTPUT_COLOR_YUV	(0)
#define OSD_COLOR_MATRIX_32_RGBA	(0x00 << 2)
#define OSD_COLOR_MATRIX_32_ARGB	(0x01 << 2)
#define OSD_COLOR_MATRIX_32_ABGR	(0x02 << 2)
#define OSD_COLOR_MATRIX_32_BGRA	(0x03 << 2)
#define OSD_COLOR_MATRIX_24_RGB		(0x00 << 2)
#define OSD_COLOR_MATRIX_16_RGB655	(0x00 << 2)
#define OSD_COLOR_MATRIX_16_RGB565	(0x04 << 2)
#define OSD_INTERLACE_ENABLED	BIT(1)
#define OSD_INTERLACE_ODD	BIT(0)
#define OSD_INTERLACE_EVEN	(0)
#define OSD_ENABLE		BIT(21)
#define OSD_BLK0_ENABLE		BIT(0)
#define OSD_GLOBAL_ALPHA_SHIFT	12
#define OSD_REPLACE_EN		BIT(14)
#define OSD_REPLACE_SHIFT	6
