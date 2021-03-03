#include <common.h>
#include <cpu_func.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include <asm/mp.h>
#include <asm/fsl_serdes.h>
#include <phy.h>
#include <hwconfig.h>
#ifndef CONFIG_USB_MAX_CONTROLLER_COUNT
#define CONFIG_USB_MAX_CONTROLLER_COUNT	1
#endif
#if defined(CONFIG_MP) && (defined(CONFIG_MPC85xx) || defined(CONFIG_MPC86xx))
#endif /* defined(CONFIG_MPC85xx) || defined(CONFIG_MPC86xx) */
#ifdef CONFIG_SYS_SRIO
#ifdef CONFIG_SRIO1
#endif
#ifdef CONFIG_SRIO2
#endif
#endif
