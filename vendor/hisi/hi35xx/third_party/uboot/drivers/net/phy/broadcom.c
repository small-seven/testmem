#include <common.h>
#include <phy.h>
#define MIIM_BCM54xx_AUXCNTL			0x18
#define MIIM_BCM54xx_AUXCNTL_ENCODE(val) (((val & 0x7) << 12)|(val & 0x7))
#define MIIM_BCM54xx_AUXSTATUS			0x19
#define MIIM_BCM54xx_AUXSTATUS_LINKMODE_MASK	0x0700
#define MIIM_BCM54xx_AUXSTATUS_LINKMODE_SHIFT	8
#define MIIM_BCM54XX_SHD			0x1c
#define MIIM_BCM54XX_SHD_WRITE			0x8000
#define MIIM_BCM54XX_SHD_VAL(x)			((x & 0x1f) << 10)
#define MIIM_BCM54XX_SHD_DATA(x)		((x & 0x3ff) << 0)
#define MIIM_BCM54XX_SHD_WR_ENCODE(val, data)	\
#define MIIM_BCM54XX_EXP_DATA		0x15	/* Expansion register data */
#define MIIM_BCM54XX_EXP_SEL		0x17	/* Expansion register select */
#define MIIM_BCM54XX_EXP_SEL_SSD	0x0e00	/* Secondary SerDes select */
#define MIIM_BCM54XX_EXP_SEL_ER		0x0f00	/* Expansion register select */
#define MIIM_BCM_AUXCNTL_SHDWSEL_MISC	0x0007
#define MIIM_BCM_AUXCNTL_ACTL_SMDSP_EN	0x0800
#define MIIM_BCM_CHANNEL_WIDTH    0x2000
