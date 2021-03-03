#include <common.h>
#include <linux/bug.h>
#include <asm/io.h>
#include <asm/arch/gp_padctrl.h>
#include <asm/arch/mc.h>
#include <asm/arch-tegra/ap.h>
#include <asm/arch-tegra/clock.h>
#include <asm/arch-tegra/fuse.h>
#include <asm/arch-tegra/pmc.h>
#include <asm/arch-tegra/scu.h>
#include <asm/arch-tegra/tegra.h>
#include <asm/arch-tegra/warmboot.h>
#ifndef CONFIG_ARM64
#if defined(CONFIG_TEGRA_SUPPORT_NON_SECURE)
#endif
#ifdef CONFIG_ARMV7_SECURE_RESERVE_SIZE
#endif
#if defined(CONFIG_ARMV7_NONSEC)
#else
#endif
#endif
