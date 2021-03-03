#include <common.h>
#include <asm/io.h>
#include <linux/errno.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/clock.h>
#include <asm/arch/iomux-mx35.h>
#include <i2c.h>
#include <power/pmic.h>
#include <fsl_pmic.h>
#include <mc13892.h>
#include <mmc.h>
#include <fsl_esdhc_imx.h>
#include <linux/types.h>
#include <asm/gpio.h>
#include <asm/arch/sys_proto.h>
#include <netdev.h>
#include <spl.h>
#define CCM_CCMR_CONFIG		0x003F4208
#define ESDCTL_DDR2_CONFIG	0x007FFC3F
#define GPIO_MMC_CD	7
#define GPIO_MMC_WP	8
#if defined(CONFIG_SPL_BUILD)
#endif
#if defined(CONFIG_FSL_ESDHC_IMX)
#endif
