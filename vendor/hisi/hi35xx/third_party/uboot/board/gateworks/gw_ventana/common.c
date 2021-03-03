#include <asm/arch/clock.h>
#include <asm/arch/mx6-pins.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/mach-imx/mxc_i2c.h>
#include <env.h>
#include <fsl_esdhc_imx.h>
#include <hwconfig.h>
#include <power/pmic.h>
#include <power/ltc3676_pmic.h>
#include <power/pfuze100_pmic.h>
#include "common.h"
#define SETUP_GPIO_OUTPUT(gpio, name, level) \
#define SETUP_GPIO_INPUT(gpio, name) \
#ifdef CONFIG_FSL_ESDHC_IMX
#endif /* CONFIG_FSL_ESDHC_IMX */
