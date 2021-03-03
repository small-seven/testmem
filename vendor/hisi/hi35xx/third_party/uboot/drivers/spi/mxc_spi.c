#include <common.h>
#include <dm.h>
#include <malloc.h>
#include <spi.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/clock.h>
#include <asm/mach-imx/spi.h>
#ifdef CONFIG_MX27
#error "i.MX27 CSPI not supported due to drastic differences in register definitions" \
#endif
#define OUT	MXC_GPIO_DIRECTION_OUT
#define reg_read readl
#define reg_write(a, v) writel(v, a)
#if !defined(CONFIG_SYS_SPI_MXC_WAIT)
#define CONFIG_SYS_SPI_MXC_WAIT		(CONFIG_SYS_HZ/100)	/* 10 ms */
#endif
#define MAX_CS_COUNT	4
#if defined(MXC_ECSPI)
#endif
#if defined(CONFIG_DM_SPI)
#else
#endif
#if defined(CONFIG_DM_SPI)
#else
#endif
#ifdef MXC_CSPI
#ifdef CONFIG_MX35
#endif
#endif
#ifdef MXC_ECSPI
#endif
#ifdef MXC_ECSPI
#endif
#ifndef CONFIG_DM_SPI
#else
#endif
