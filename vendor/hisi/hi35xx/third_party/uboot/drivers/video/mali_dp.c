#define DEBUG
#include <common.h>
#include <video.h>
#include <dm.h>
#ifdef CONFIG_DISPLAY
#include <display.h>
#endif
#include <fdtdec.h>
#include <asm/io.h>
#include <os.h>
#include <fdt_support.h>
#include <clk.h>
#include <linux/sizes.h>
#define MALIDP_CORE_ID		0x0018
#define MALIDP_REG_BG_COLOR	0x0044
#define MALIDP_LAYER_LV1	0x0100
#define MALIDP_DC_STATUS	0xc000
#define MALIDP_DC_CONTROL	0xc010
#define MALIDP_DC_CFG_VALID	0xc014
#define MALIDP_H_INTERVALS	0x0000
#define MALIDP_V_INTERVALS	0x0004
#define MALIDP_SYNC_CONTROL	0x0008
#define MALIDP_HV_ACTIVESIZE	0x000c
#define MALIDP_OUTPUT_DEPTH	0x001c
#define MALIDP_LAYER_FORMAT	0x0000
#define MALIDP_LAYER_CONTROL	0x0004
#define MALIDP_LAYER_IN_SIZE	0x000c
#define MALIDP_LAYER_CMP_SIZE	0x0010
#define MALIDP_LAYER_STRIDE	0x0018
#define MALIDP_LAYER_PTR_LOW	0x0024
#define MALIDP_LAYER_PTR_HIGH	0x0028
#define MALIDP_REG_MASKIRQ	0x0008
#define MALIDP_REG_CLEARIRQ	0x000c
#define M1BITS	0x0001
#define M2BITS	0x0003
#define M4BITS	0x000f
#define M8BITS	0x00ff
#define M10BITS	0x03ff
#define M12BITS	0x0fff
#define M13BITS	0x1fff
#define M16BITS	0xffff
#define M17BITS	0x1ffff
#define MALIDP_H_FRONTPORCH(x)	(((x) & M12BITS) << 0)
#define MALIDP_H_BACKPORCH(x)	(((x) & M10BITS) << 16)
#define MALIDP_V_FRONTPORCH(x)	(((x) & M12BITS) << 0)
#define MALIDP_V_BACKPORCH(x)	(((x) & M8BITS) << 16)
#define MALIDP_H_SYNCWIDTH(x)	(((x) & M10BITS) << 0)
#define MALIDP_V_SYNCWIDTH(x)	(((x) & M8BITS) << 16)
#define MALIDP_H_ACTIVE(x)	(((x) & M13BITS) << 0)
#define MALIDP_V_ACTIVE(x)	(((x) & M13BITS) << 16)
#define MALIDP_CMP_V_SIZE(x)	(((x) & M13BITS) << 16)
#define MALIDP_CMP_H_SIZE(x)	(((x) & M13BITS) << 0)
#define MALIDP_IN_V_SIZE(x)	(((x) & M13BITS) << 16)
#define MALIDP_IN_H_SIZE(x)	(((x) & M13BITS) << 0)
#define MALIDP_DC_CM_CONTROL(x)	((x) & M1BITS) << 16, 1 << 16
#define MALIDP_DC_STATUS_GET_CM(reg) (((reg) >> 16) & M1BITS)
#define MALIDP_FORMAT_ARGB8888	0x08
#define MALIDP_DEFAULT_BG_R 0x0
#define MALIDP_DEFAULT_BG_G 0x0
#define MALIDP_DEFAULT_BG_B 0x0
#define MALIDP_PRODUCT_ID(core_id)	((u32)(core_id) >> 16)
#define MALIDP500	0x500
#ifdef CONFIG_DISPLAY
#endif
