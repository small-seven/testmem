#include <common.h>
#include <config.h>
#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#include "mxs_init.h"
#ifdef CONFIG_SYS_MXS_VDD5V_ONLY
#define DCDC4P2_DROPOUT_CONFIG	POWER_DCDC4P2_DROPOUT_CTRL_100MV | \
#else
#define DCDC4P2_DROPOUT_CONFIG	POWER_DCDC4P2_DROPOUT_CTRL_100MV | \
#endif
#ifdef CONFIG_MX23
#endif
#if defined(CONFIG_MX23)
#else
#endif
#ifdef CONFIG_MX23
#endif
#ifdef CONFIG_MX23
#endif
#ifdef CONFIG_MX23
#endif
#ifdef	CONFIG_SPL_MXS_PSWITCH_WAIT
#endif
