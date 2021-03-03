#include <common.h>
#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/sys_proto.h>
#if defined(CONFIG_MX6SL) || defined(CONFIG_MX6SLL)
#endif
#ifdef CONFIG_IOMUX_LPSR
#ifdef CONFIG_MX7
#else
#endif
#endif
#ifdef CONFIG_IOMUX_SHARE_CONF_REG
#else
#if defined(CONFIG_MX6SLL)
#endif
#endif
#ifdef CONFIG_IOMUX_LPSR
#endif
#if defined(CONFIG_MX6QDL)
#else
#endif
#ifdef CONFIG_IOMUX_SHARE_CONF_REG
#endif
