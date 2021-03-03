#define DEBUG
#include "meson_vpu.h"
#define HHI_VDAC_CNTL0		0x2F4 /* 0xbd offset in data sheet */
#define HHI_VDAC_CNTL0_G12A	0x2EC /* 0xbd offset in data sheet */
#define HHI_VDAC_CNTL1		0x2F8 /* 0xbe offset in data sheet */
#define HHI_VDAC_CNTL1_G12A	0x2F0 /* 0xbe offset in data sheet */
#define HHI_HDMI_PHY_CNTL0	0x3a0 /* 0xe8 offset in data sheet */
#define OSD_REPLACE_EN		BIT(14)
#define OSD_REPLACE_SHIFT	6
#define COEFF_NORM(a) ((int)((((a) * 2048.0) + 1) / 2))
#define MATRIX_5X3_COEF_SIZE 24
#define EOTF_COEFF_NORM(a) ((int)((((a) * 4096.0) + 1) / 2))
#define EOTF_COEFF_SIZE 10
#define EOTF_COEFF_RIGHTSHIFT 1
#define OSD_EOTF_LUT_SIZE 33
#define OSD_OETF_LUT_SIZE 41
