#include <common.h>
#include <asm/io.h>
#include <spl.h>
#include <asm/arch/hardware.h>
#include <asm/arch/sysfw-loader.h>
#include <asm/arch/sys_proto.h>
#include "common.h"
#include <dm.h>
#include <dm/uclass-internal.h>
#include <dm/pinctrl.h>
#include <linux/soc/ti/ti_sci_protocol.h>
#ifdef CONFIG_SPL_BUILD
#if defined(CONFIG_K3_LOAD_SYSFW) || defined(CONFIG_K3_AM654_DDRSS)
#endif
#ifdef CONFIG_CPU_V7R
#endif
#ifdef CONFIG_K3_LOAD_SYSFW
#else
#endif
#if defined(CONFIG_CPU_V7R) && defined(CONFIG_K3_AVS0)
#endif
#ifdef CONFIG_K3_AM654_DDRSS
#endif
#if defined(CONFIG_SUPPORT_EMMC_BOOT)
#endif
#if defined(CONFIG_SPL_FS_FAT) || defined(CONFIG_SPL_FS_EXT4)
#else
#endif
#endif
#ifdef CONFIG_SYS_K3_SPL_ATF
#define AM6_DEV_MCU_RTI0			134
#define AM6_DEV_MCU_RTI1			135
#define AM6_DEV_MCU_ARMSS0_CPU0			159
#define AM6_DEV_MCU_ARMSS0_CPU1			245
#endif
