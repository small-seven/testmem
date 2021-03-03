#include <common.h>
#include <dm.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <asm-generic/gpio.h>
#include <asm/arch/clock.h>
#include <asm/arch-tegra/usb.h>
#include <asm/arch-tegra/clk_rst.h>
#include <usb.h>
#include <usb/ulpi.h>
#include <linux/libfdt.h>
#include "ehci.h"
#define USB1_ADDR_MASK	0xFFFF0000
#define HOSTPC1_DEVLC	0x84
#define HOSTPC1_PSPD(x)		(((x) >> 25) & 0x3)
#ifdef CONFIG_USB_ULPI
#endif
#if defined(CONFIG_TEGRA20)
#else
#endif
#ifdef CONFIG_USB_ULPI
#ifndef CONFIG_ULPI_REF_CLK
#define CONFIG_ULPI_REF_CLK 24000000
#endif
#else
#endif
