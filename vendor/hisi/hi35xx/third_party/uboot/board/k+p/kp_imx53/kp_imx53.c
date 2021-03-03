#include <common.h>
#include <init.h>
#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/clock.h>
#include <asm/arch/iomux-mx53.h>
#include <asm/arch/clock.h>
#include <asm/gpio.h>
#include <env.h>
#include <power/pmic.h>
#include <fsl_pmic.h>
#include "kp_id_rev.h"
#define BOOSTER_OFF IMX_GPIO_NR(2, 23)
#define LCD_BACKLIGHT IMX_GPIO_NR(1, 1)
#define KEY1 IMX_GPIO_NR(2, 26)
