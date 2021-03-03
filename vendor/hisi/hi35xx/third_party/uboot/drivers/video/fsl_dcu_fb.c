#include <init.h>
#include <asm/io.h>
#include <common.h>
#include <dm.h>
#include <fdt_support.h>
#include <fsl_dcu_fb.h>
#include <linux/fb.h>
#include <malloc.h>
#include <video.h>
#include <video_fb.h>
#include "videomodes.h"
#define RESOLUTION(x, y) (((u32)(x) << 16) | (y))
#ifdef CONFIG_SYS_FSL_DCU_LE
#define	dcu_read32	in_le32
#define	dcu_write32	out_le32
#elif defined(CONFIG_SYS_FSL_DCU_BE)
#define	dcu_read32	in_be32
#define	dcu_write32	out_be32
#endif
#define DCU_MODE_BLEND_ITER(x)          ((x) << 20)
#define DCU_MODE_RASTER_EN		(1 << 14)
#define DCU_MODE_NORMAL			1
#define DCU_MODE_COLORBAR               3
#define DCU_BGND_R(x)			((x) << 16)
#define DCU_BGND_G(x)			((x) << 8)
#define DCU_BGND_B(x)			(x)
#define DCU_DISP_SIZE_DELTA_Y(x)	((x) << 16)
#define DCU_DISP_SIZE_DELTA_X(x)	(x)
#define DCU_HSYN_PARA_BP(x)		((x) << 22)
#define DCU_HSYN_PARA_PW(x)		((x) << 11)
#define DCU_HSYN_PARA_FP(x)		(x)
#define DCU_VSYN_PARA_BP(x)		((x) << 22)
#define DCU_VSYN_PARA_PW(x)		((x) << 11)
#define DCU_VSYN_PARA_FP(x)		(x)
#define DCU_SYN_POL_INV_PXCK_FALL	(1 << 6)
#define DCU_SYN_POL_NEG_REMAIN		(0 << 5)
#define DCU_SYN_POL_INV_VS_LOW		(1 << 1)
#define DCU_SYN_POL_INV_HS_LOW		(1)
#define DCU_THRESHOLD_LS_BF_VS(x)	((x) << 16)
#define DCU_THRESHOLD_OUT_BUF_HIGH(x)	((x) << 8)
#define DCU_THRESHOLD_OUT_BUF_LOW(x)	(x)
#define DCU_UPDATE_MODE_MODE            (1 << 31)
#define DCU_UPDATE_MODE_READREG         (1 << 30)
#define DCU_CTRLDESCLN_1_HEIGHT(x)	((x) << 16)
#define DCU_CTRLDESCLN_1_WIDTH(x)	(x)
#define DCU_CTRLDESCLN_2_POSY(x)	((x) << 16)
#define DCU_CTRLDESCLN_2_POSX(x)	(x)
#define DCU_CTRLDESCLN_4_EN		(1 << 31)
#define DCU_CTRLDESCLN_4_TILE_EN	(1 << 30)
#define DCU_CTRLDESCLN_4_DATA_SEL_CLUT	(1 << 29)
#define DCU_CTRLDESCLN_4_SAFETY_EN	(1 << 28)
#define DCU_CTRLDESCLN_4_TRANS(x)	((x) << 20)
#define DCU_CTRLDESCLN_4_BPP(x)		((x) << 16)
#define DCU_CTRLDESCLN_4_RLE_EN		(1 << 15)
#define DCU_CTRLDESCLN_4_LUOFFS(x)	((x) << 4)
#define DCU_CTRLDESCLN_4_BB_ON		(1 << 2)
#define DCU_CTRLDESCLN_4_AB(x)		(x)
#define DCU_CTRLDESCLN_5_CKMAX_R(x)	((x) << 16)
#define DCU_CTRLDESCLN_5_CKMAX_G(x)	((x) << 8)
#define DCU_CTRLDESCLN_5_CKMAX_B(x)	(x)
#define DCU_CTRLDESCLN_6_CKMIN_R(x)	((x) << 16)
#define DCU_CTRLDESCLN_6_CKMIN_G(x)	((x) << 8)
#define DCU_CTRLDESCLN_6_CKMIN_B(x)	(x)
#define DCU_CTRLDESCLN_7_TILE_VER(x)	((x) << 16)
#define DCU_CTRLDESCLN_7_TILE_HOR(x)	(x)
#define DCU_CTRLDESCLN_8_FG_FCOLOR(x)	(x)
#define DCU_CTRLDESCLN_9_BG_BCOLOR(x)	(x)
#define BPP_16_RGB565			4
#define BPP_24_RGB888			5
#define BPP_32_ARGB8888			6
#if !CONFIG_IS_ENABLED(DM_VIDEO)
#endif
#ifndef CONFIG_DM_VIDEO
#if defined(CONFIG_OF_BOARD_SETUP)
#endif
#else /* ifndef CONFIG_DM_VIDEO */
#endif /* ifndef CONFIG_DM_VIDEO */
