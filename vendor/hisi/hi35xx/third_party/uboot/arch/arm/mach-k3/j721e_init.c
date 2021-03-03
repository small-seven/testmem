#include <common.h>
#include <spl.h>
#include <asm/io.h>
#include <asm/armv7_mpu.h>
#include <asm/arch/hardware.h>
#include <asm/arch/sysfw-loader.h>
#include "common.h"
#include <asm/arch/sys_proto.h>
#include <linux/soc/ti/ti_sci_protocol.h>
#include <dm.h>
#include <dm/uclass-internal.h>
#include <dm/pinctrl.h>
#ifdef CONFIG_SPL_BUILD
#if defined(CONFIG_K3_J721E_DDRSS) || defined(CONFIG_K3_LOAD_SYSFW)
#endif
#ifdef CONFIG_CPU_V7R
#endif
#ifdef CONFIG_K3_LOAD_SYSFW
#else
#endif
#if defined(CONFIG_CPU_V7R) && defined(CONFIG_K3_AVS0)
#endif
#if defined(CONFIG_K3_J721E_DDRSS)
#endif
#endif
#ifdef CONFIG_SYS_K3_SPL_ATF
#define J721E_DEV_MCU_RTI0			262
#define J721E_DEV_MCU_RTI1			263
#define J721E_DEV_MCU_ARMSS0_CPU0		250
#define J721E_DEV_MCU_ARMSS0_CPU1		251
#endif
