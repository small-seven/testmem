#include <version.h>
#include <common.h>
#include <env.h>
#include <fdtdec.h>
#include <i2c.h>
#include <lcd.h>
#include "bur_common.h"
#if defined(CONFIG_LCD) && defined(CONFIG_AM335X_LCD) && \
#include <asm/arch/hardware.h>
#include <asm/arch/cpu.h>
#include <asm/gpio.h>
#include <power/tps65217.h>
#include "../../../drivers/video/am335x-fb.h"
#endif /* CONFIG_LCD */
#if defined(CONFIG_SPL_BUILD) && defined(CONFIG_AM33XX)
#include <asm/arch/hardware.h>
#include <asm/arch/omap.h>
#include <asm/arch/clock.h>
#include <asm/arch/sys_proto.h>
#include <power/tps65217.h>
#endif /* CONFIG_SPL_BUILD && CONFIG_AM33XX */
