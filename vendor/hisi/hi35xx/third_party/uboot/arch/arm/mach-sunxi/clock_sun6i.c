#include <common.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/prcm.h>
#include <asm/arch/sys_proto.h>
#ifdef CONFIG_SPL_BUILD
#if !defined(CONFIG_MACH_SUNXI_H3_H5) && !defined(CONFIG_MACH_SUN50I)
#endif
#if defined(CONFIG_MACH_SUN8I_R40) || defined(CONFIG_MACH_SUN50I)
#endif
#if defined(CONFIG_MACH_SUN8I_R40) && defined(CONFIG_SUNXI_AHCI)
#endif
#endif
#ifdef CONFIG_MACH_SUNXI_H3_H5
#endif
#if CONFIG_CONS_INDEX < 5
#else
#endif
#ifdef CONFIG_SPL_BUILD
#endif
#ifdef CONFIG_SUNXI_DE2
#else
#endif
#ifdef CONFIG_SUNXI_DE2
#endif
#ifdef CONFIG_MACH_SUNXI_H3_H5
#endif
#ifdef CONFIG_MACH_SUN6I
#endif
#ifdef CONFIG_SUNXI_DE2
#endif
#if defined(CONFIG_MACH_SUN8I_A33) || \
#endif
