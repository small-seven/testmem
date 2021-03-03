#include <common.h>
#include <errno.h>
#include <dm.h>
#include <malloc.h>
#include <asm/arch/imx-regs.h>
#include <asm/gpio.h>
#include <asm/io.h>
#define GPIO_PER_BANK			32
#ifndef CONFIG_DM_GPIO
#define GPIO_TO_PORT(n)		((n) / 32)
#if defined(CONFIG_MX25) || defined(CONFIG_MX27) || defined(CONFIG_MX51) || \
#endif
#if defined(CONFIG_MX27) || defined(CONFIG_MX53) || defined(CONFIG_MX6) || \
#if !(defined(CONFIG_MX6UL) || defined(CONFIG_MX6ULL) || defined(CONFIG_IMX8M))
#endif
#endif
#if defined(CONFIG_MX53) || defined(CONFIG_MX6) || defined(CONFIG_MX7) || \
#if !(defined(CONFIG_MX6UL) || defined(CONFIG_MX6ULL))
#endif
#endif
#if defined(CONFIG_ARCH_IMX8)
#endif
int gpio_free(unsigned gpio)
{
	return 0;
}
#endif
#ifdef CONFIG_DM_GPIO
#include <fdtdec.h>
#if !CONFIG_IS_ENABLED(OF_CONTROL)
#if defined(CONFIG_MX25) || defined(CONFIG_MX27) || defined(CONFIG_MX51) || \
#endif
#if defined(CONFIG_MX27) || defined(CONFIG_MX53) || defined(CONFIG_MX6) || \
#ifndef CONFIG_IMX8M
#endif
#endif
#if defined(CONFIG_MX53) || defined(CONFIG_MX6) || defined(CONFIG_ARCH_IMX8)
#endif
#if defined(CONFIG_ARCH_IMX8)
#endif
#if defined(CONFIG_MX25) || defined(CONFIG_MX27) || defined(CONFIG_MX51) || \
#endif
#if defined(CONFIG_MX27) || defined(CONFIG_MX53) || defined(CONFIG_MX6) || \
#ifndef CONFIG_IMX8M
#endif
#endif
#if defined(CONFIG_MX53) || defined(CONFIG_MX6) || defined(CONFIG_ARCH_IMX8)
#endif
#if defined(CONFIG_ARCH_IMX8)
#endif
#endif
#endif
