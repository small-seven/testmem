#include <common.h>
#include <backlight.h>
#include <dm.h>
#include <mipi_dsi.h>
#include <panel.h>
#include <asm/gpio.h>
#include <power/regulator.h>
#define MCS_CMD_MODE_SW	0xFE /* CMD Mode Switch */
#define MCS_CMD1_UCS	0x00 /* User Command Set (UCS = CMD1) */
#define MCS_CMD2_P0	0x01 /* Manufacture Command Set Page0 (CMD2 P0) */
#define MCS_CMD2_P1	0x02 /* Manufacture Command Set Page1 (CMD2 P1) */
#define MCS_CMD2_P2	0x03 /* Manufacture Command Set Page2 (CMD2 P2) */
#define MCS_CMD2_P3	0x04 /* Manufacture Command Set Page3 (CMD2 P3) */
#define MCS_STBCTR	0x12 /* TE1 Output Setting Zig-Zag Connection */
#define MCS_SGOPCTR	0x16 /* Source Bias Current */
#define MCS_SDCTR	0x1A /* Source Output Delay Time */
#define MCS_INVCTR	0x1B /* Inversion Type */
#define MCS_EXT_PWR_IC	0x24 /* External PWR IC Control */
#define MCS_SETAVDD	0x27 /* PFM Control for AVDD Output */
#define MCS_SETAVEE	0x29 /* PFM Control for AVEE Output */
#define MCS_BT2CTR	0x2B /* DDVDL Charge Pump Control */
#define MCS_BT3CTR	0x2F /* VGH Charge Pump Control */
#define MCS_BT4CTR	0x34 /* VGL Charge Pump Control */
#define MCS_VCMCTR	0x46 /* VCOM Output Level Control */
#define MCS_SETVGN	0x52 /* VG M/S N Control */
#define MCS_SETVGP	0x54 /* VG M/S P Control */
#define MCS_SW_CTRL	0x5F /* Interface Control for PFM and MIPI */
#define GOA_VSTV1		0x00
#define GOA_VSTV2		0x07
#define GOA_VCLK1		0x0E
#define GOA_VCLK2		0x17
#define GOA_VCLK_OPT1		0x20
#define GOA_BICLK1		0x2A
#define GOA_BICLK2		0x37
#define GOA_BICLK3		0x44
#define GOA_BICLK4		0x4F
#define GOA_BICLK_OPT1		0x5B
#define GOA_BICLK_OPT2		0x60
#define MCS_GOA_GPO1		0x6D
#define MCS_GOA_GPO2		0x71
#define MCS_GOA_EQ		0x74
#define MCS_GOA_CLK_GALLON	0x7C
#define MCS_GOA_FS_SEL0		0x7E
#define MCS_GOA_FS_SEL1		0x87
#define MCS_GOA_FS_SEL2		0x91
#define MCS_GOA_FS_SEL3		0x9B
#define MCS_GOA_BS_SEL0		0xAC
#define MCS_GOA_BS_SEL1		0xB5
#define MCS_GOA_BS_SEL2		0xBF
#define MCS_GOA_BS_SEL3		0xC9
#define MCS_GOA_BS_SEL4		0xD3
#define MCS_GAMMA_VP		0x60 /* Gamma VP1~VP16 */
#define MCS_GAMMA_VN		0x70 /* Gamma VN1~VN16 */
#define dcs_write_seq(ctx, seq...)				\
#define dcs_write_cmd_seq(ctx, cmd, seq...)			\
