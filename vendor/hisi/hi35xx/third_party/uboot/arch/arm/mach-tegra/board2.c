#include <common.h>
#include <dm.h>
#include <env.h>
#include <errno.h>
#include <init.h>
#include <ns16550.h>
#include <usb.h>
#include <asm/io.h>
#include <asm/arch-tegra/ap.h>
#include <asm/arch-tegra/board.h>
#include <asm/arch-tegra/cboot.h>
#include <asm/arch-tegra/clk_rst.h>
#include <asm/arch-tegra/pmc.h>
#include <asm/arch-tegra/pmu.h>
#include <asm/arch-tegra/sys_proto.h>
#include <asm/arch-tegra/uart.h>
#include <asm/arch-tegra/warmboot.h>
#include <asm/arch-tegra/gpu.h>
#include <asm/arch-tegra/usb.h>
#include <asm/arch-tegra/xusb-padctl.h>
#if IS_ENABLED(CONFIG_TEGRA_CLKRST)
#include <asm/arch/clock.h>
#endif
#if IS_ENABLED(CONFIG_TEGRA_PINCTRL)
#include <asm/arch/funcmux.h>
#include <asm/arch/pinmux.h>
#endif
#include <asm/arch/tegra.h>
#ifdef CONFIG_TEGRA_CLOCK_SCALING
#include <asm/arch/emc.h>
#endif
#include "emc.h"
#ifdef CONFIG_SPL_BUILD
#endif
#if defined(CONFIG_TEGRA_NAND)
#endif
#if defined(CONFIG_TEGRA20)
#endif
#ifdef CONFIG_DISPLAY_BOARDINFO
#endif	/* CONFIG_DISPLAY_BOARDINFO */
#if IS_ENABLED(CONFIG_TEGRA_CLKRST)
#endif
#ifdef CONFIG_TEGRA_SPI
#endif
#ifdef CONFIG_MMC_SDHCI_TEGRA
#endif
#if defined(CONFIG_DM_VIDEO)
#endif
#ifdef CONFIG_SYS_I2C_TEGRA
# ifdef CONFIG_TEGRA_PMU
#  ifdef CONFIG_TEGRA_CLOCK_SCALING
#  endif
# endif /* CONFIG_TEGRA_PMU */
#endif /* CONFIG_SYS_I2C_TEGRA */
#ifdef CONFIG_USB_EHCI_TEGRA
#endif
#if defined(CONFIG_DM_VIDEO)
#endif
#ifdef CONFIG_TEGRA_NAND
#endif
#ifdef CONFIG_TEGRA_LP0
#endif
#ifdef CONFIG_BOARD_EARLY_INIT_F
#if IS_ENABLED(CONFIG_TEGRA_CLKRST)
#endif
#if defined(CONFIG_TEGRA_DISCONNECT_UDC_ON_BOOT)
#define USBCMD_FS2 (1 << 15)
#endif
#if IS_ENABLED(CONFIG_TEGRA_CLKRST)
#  if defined(CONFIG_TEGRA_SUPPORT_NON_SECURE)
#  endif
#endif
#endif	/* EARLY_INIT */
#if defined(CONFIG_TEGRA_SUPPORT_NON_SECURE)
#endif
#ifdef CONFIG_ARM64
#elif defined(CONFIG_ARMV7_SECURE_RESERVE_SIZE)
#else
#endif
#ifdef CONFIG_PCI
#endif
#ifdef CONFIG_PHYS_64BIT
#endif
