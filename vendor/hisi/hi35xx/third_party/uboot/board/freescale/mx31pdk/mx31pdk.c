#include <common.h>
#include <init.h>
#include <netdev.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/sys_proto.h>
#include <watchdog.h>
#include <power/pmic.h>
#include <fsl_pmic.h>
#include <errno.h>
#ifdef CONFIG_SPL_BUILD
#endif
#ifdef CONFIG_HW_WATCHDOG
#endif
#ifdef CONFIG_SMC911X
#endif
