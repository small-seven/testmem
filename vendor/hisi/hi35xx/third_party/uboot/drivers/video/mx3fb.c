#include <common.h>
#include <env.h>
#include <malloc.h>
#include <video_fb.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/clock.h>
#include <linux/errno.h>
#include <asm/io.h>
#include "videomodes.h"
#define IF_CONF		0
#define IPU_CHA_BUF0_RDY	(0x04 + IPU_BASE)
#define IPU_CHA_BUF1_RDY	(0x08 + IPU_BASE)
#define IPU_CHA_DB_MODE_SEL	(0x0C + IPU_BASE)
#define IPU_CHA_CUR_BUF		(0x10 + IPU_BASE)
#define IPU_FS_PROC_FLOW	(0x14 + IPU_BASE)
#define IPU_FS_DISP_FLOW	(0x18 + IPU_BASE)
#define IPU_TASKS_STAT		(0x1C + IPU_BASE)
#define IPU_IMA_ADDR		(0x20 + IPU_BASE)
#define IPU_IMA_DATA		(0x24 + IPU_BASE)
#define IPU_INT_CTRL_1		(0x28 + IPU_BASE)
#define IPU_INT_CTRL_2		(0x2C + IPU_BASE)
#define IPU_INT_CTRL_3		(0x30 + IPU_BASE)
#define IPU_INT_CTRL_4		(0x34 + IPU_BASE)
#define IPU_INT_CTRL_5		(0x38 + IPU_BASE)
#define IPU_INT_STAT_1		(0x3C + IPU_BASE)
#define IPU_INT_STAT_2		(0x40 + IPU_BASE)
#define IPU_INT_STAT_3		(0x44 + IPU_BASE)
#define IPU_INT_STAT_4		(0x48 + IPU_BASE)
#define IPU_INT_STAT_5		(0x4C + IPU_BASE)
#define IPU_BRK_CTRL_1		(0x50 + IPU_BASE)
#define IPU_BRK_CTRL_2		(0x54 + IPU_BASE)
#define IPU_BRK_STAT		(0x58 + IPU_BASE)
#define IPU_DIAGB_CTRL		(0x5C + IPU_BASE)
#define IC_CONF			(0x88 + IPU_BASE)
#define IC_PRP_ENC_RSC		(0x8C + IPU_BASE)
#define IC_PRP_VF_RSC		(0x90 + IPU_BASE)
#define IC_PP_RSC		(0x94 + IPU_BASE)
#define IC_CMBP_1		(0x98 + IPU_BASE)
#define IC_CMBP_2		(0x9C + IPU_BASE)
#define PF_CONF			(0xA0 + IPU_BASE)
#define IDMAC_CONF		(0xA4 + IPU_BASE)
#define IDMAC_CHA_EN		(0xA8 + IPU_BASE)
#define IDMAC_CHA_PRI		(0xAC + IPU_BASE)
#define IDMAC_CHA_BUSY		(0xB0 + IPU_BASE)
#define IC_CONF_PRPENC_EN	0x00000001
#define IC_CONF_PRPENC_CSC1	0x00000002
#define IC_CONF_PRPENC_ROT_EN	0x00000004
#define IC_CONF_PRPVF_EN	0x00000100
#define IC_CONF_PRPVF_CSC1	0x00000200
#define IC_CONF_PRPVF_CSC2	0x00000400
#define IC_CONF_PRPVF_CMB	0x00000800
#define IC_CONF_PRPVF_ROT_EN	0x00001000
#define IC_CONF_PP_EN		0x00010000
#define IC_CONF_PP_CSC1		0x00020000
#define IC_CONF_PP_CSC2		0x00040000
#define IC_CONF_PP_CMB		0x00080000
#define IC_CONF_PP_ROT_EN	0x00100000
#define IC_CONF_IC_GLB_LOC_A	0x10000000
#define IC_CONF_KEY_COLOR_EN	0x20000000
#define IC_CONF_RWS_EN		0x40000000
#define IC_CONF_CSI_MEM_WR_EN	0x80000000
#define SDC_COM_CONF		(0xB4 + IPU_BASE)
#define SDC_GW_CTRL		(0xB8 + IPU_BASE)
#define SDC_FG_POS		(0xBC + IPU_BASE)
#define SDC_BG_POS		(0xC0 + IPU_BASE)
#define SDC_CUR_POS		(0xC4 + IPU_BASE)
#define SDC_PWM_CTRL		(0xC8 + IPU_BASE)
#define SDC_CUR_MAP		(0xCC + IPU_BASE)
#define SDC_HOR_CONF		(0xD0 + IPU_BASE)
#define SDC_VER_CONF		(0xD4 + IPU_BASE)
#define SDC_SHARP_CONF_1	(0xD8 + IPU_BASE)
#define SDC_SHARP_CONF_2	(0xDC + IPU_BASE)
#define SDC_COM_TFT_COLOR	0x00000001UL
#define SDC_COM_FG_EN		0x00000010UL
#define SDC_COM_GWSEL		0x00000020UL
#define SDC_COM_GLB_A		0x00000040UL
#define SDC_COM_KEY_COLOR_G	0x00000080UL
#define SDC_COM_BG_EN		0x00000200UL
#define SDC_COM_SHARP		0x00001000UL
#define SDC_V_SYNC_WIDTH_L	0x00000001UL
#define DI_DISP_IF_CONF		(0x0124 + IPU_BASE)
#define DI_DISP_SIG_POL		(0x0128 + IPU_BASE)
#define DI_SER_DISP1_CONF	(0x012C + IPU_BASE)
#define DI_SER_DISP2_CONF	(0x0130 + IPU_BASE)
#define DI_HSP_CLK_PER		(0x0134 + IPU_BASE)
#define DI_DISP0_TIME_CONF_1	(0x0138 + IPU_BASE)
#define DI_DISP0_TIME_CONF_2	(0x013C + IPU_BASE)
#define DI_DISP0_TIME_CONF_3	(0x0140 + IPU_BASE)
#define DI_DISP1_TIME_CONF_1	(0x0144 + IPU_BASE)
#define DI_DISP1_TIME_CONF_2	(0x0148 + IPU_BASE)
#define DI_DISP1_TIME_CONF_3	(0x014C + IPU_BASE)
#define DI_DISP2_TIME_CONF_1	(0x0150 + IPU_BASE)
#define DI_DISP2_TIME_CONF_2	(0x0154 + IPU_BASE)
#define DI_DISP2_TIME_CONF_3	(0x0158 + IPU_BASE)
#define DI_DISP3_TIME_CONF	(0x015C + IPU_BASE)
#define DI_DISP0_DB0_MAP	(0x0160 + IPU_BASE)
#define DI_DISP0_DB1_MAP	(0x0164 + IPU_BASE)
#define DI_DISP0_DB2_MAP	(0x0168 + IPU_BASE)
#define DI_DISP0_CB0_MAP	(0x016C + IPU_BASE)
#define DI_DISP0_CB1_MAP	(0x0170 + IPU_BASE)
#define DI_DISP0_CB2_MAP	(0x0174 + IPU_BASE)
#define DI_DISP1_DB0_MAP	(0x0178 + IPU_BASE)
#define DI_DISP1_DB1_MAP	(0x017C + IPU_BASE)
#define DI_DISP1_DB2_MAP	(0x0180 + IPU_BASE)
#define DI_DISP1_CB0_MAP	(0x0184 + IPU_BASE)
#define DI_DISP1_CB1_MAP	(0x0188 + IPU_BASE)
#define DI_DISP1_CB2_MAP	(0x018C + IPU_BASE)
#define DI_DISP2_DB0_MAP	(0x0190 + IPU_BASE)
#define DI_DISP2_DB1_MAP	(0x0194 + IPU_BASE)
#define DI_DISP2_DB2_MAP	(0x0198 + IPU_BASE)
#define DI_DISP2_CB0_MAP	(0x019C + IPU_BASE)
#define DI_DISP2_CB1_MAP	(0x01A0 + IPU_BASE)
#define DI_DISP2_CB2_MAP	(0x01A4 + IPU_BASE)
#define DI_DISP3_B0_MAP		(0x01A8 + IPU_BASE)
#define DI_DISP3_B1_MAP		(0x01AC + IPU_BASE)
#define DI_DISP3_B2_MAP		(0x01B0 + IPU_BASE)
#define DI_DISP_ACC_CC		(0x01B4 + IPU_BASE)
#define DI_DISP_LLA_CONF	(0x01B8 + IPU_BASE)
#define DI_DISP_LLA_DATA	(0x01BC + IPU_BASE)
#define DI_D3_VSYNC_POL		(1 << 28)
#define DI_D3_HSYNC_POL		(1 << 27)
#define DI_D3_DRDY_SHARP_POL	(1 << 26)
#define DI_D3_CLK_POL		(1 << 25)
#define DI_D3_DATA_POL		(1 << 24)
#define DI_D3_CLK_IDLE		(1 << 26)
#define DI_D3_CLK_SEL		(1 << 25)
#define DI_D3_DATAMSK		(1 << 24)
#define IOMUX_PADNUM_MASK	0x1ff
#define IOMUX_GPIONUM_SHIFT	9
#define IOMUX_GPIONUM_MASK	(0xff << IOMUX_GPIONUM_SHIFT)
#define IOMUX_PIN(gpionum, padnum) ((padnum) & IOMUX_PADNUM_MASK)
#define IOMUX_MODE_L(pin, mode) IOMUX_MODE(((pin) + 0xc) ^ 3, mode)
