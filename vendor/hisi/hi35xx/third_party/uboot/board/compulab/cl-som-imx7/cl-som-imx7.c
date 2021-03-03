#include <common.h>
#include <env.h>
#include <init.h>
#include <mmc.h>
#include <phy.h>
#include <netdev.h>
#include <fsl_esdhc_imx.h>
#include <power/pmic.h>
#include <power/pfuze3000_pmic.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/arch-mx7/mx7-pins.h>
#include <asm/arch-mx7/sys_proto.h>
#include <asm/arch-mx7/clock.h>
#include "../common/eeprom.h"
#include "common.h"
#ifdef CONFIG_SYS_I2C_MXC
#define I2C_PAD_CTRL		(PAD_CTL_DSE_3P3V_32OHM | PAD_CTL_SRE_SLOW | \
#define CL_SOM_IMX7_GPIO_I2C2_SCL	IMX_GPIO_NR(1, 6)
#define CL_SOM_IMX7_GPIO_I2C2_SDA	IMX_GPIO_NR(1, 7)
#else /* !CONFIG_SYS_I2C_MXC */
#endif /* CONFIG_SYS_I2C_MXC */
#ifdef CONFIG_FSL_ESDHC_IMX
#define CL_SOM_IMX7_GPIO_USDHC3_PWR	IMX_GPIO_NR(6, 11)
#endif /* CONFIG_FSL_ESDHC_IMX */
#ifdef CONFIG_FEC_MXC
#define CL_SOM_IMX7_ETH1_PHY_NRST	IMX_GPIO_NR(1, 4)
#define CL_SOM_IMX7_FEC_DEV_ID_PRI 0
#else /* !CONFIG_FEC_MXC */
#endif /* CONFIG_FEC_MXC */
#ifdef CONFIG_SPI
#else /* !CONFIG_SPI */
#endif /* CONFIG_SPI */
#ifdef CONFIG_POWER
#define I2C_PMIC	0
#endif /* CONFIG_POWER */
