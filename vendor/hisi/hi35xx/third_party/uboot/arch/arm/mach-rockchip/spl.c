#include <common.h>
#include <debug_uart.h>
#include <dm.h>
#include <ram.h>
#include <spl.h>
#include <asm/arch-rockchip/bootrom.h>
#include <asm/io.h>
#if defined(CONFIG_TARGET_CHROMEBOOK_JERRY) || \
#endif
#if !defined(CONFIG_ROCKCHIP_RK3188)
#define TIMER_LOAD_COUNT_L	0x00
#define TIMER_LOAD_COUNT_H	0x04
#define TIMER_CONTROL_REG	0x10
#define TIMER_EN	0x1
#define	TIMER_FMODE	BIT(0)
#define	TIMER_RMODE	BIT(1)
#ifndef CONFIG_ARM64
#endif
#endif
#if !defined(CONFIG_TPL) || defined(CONFIG_SPL_OS_BOOT)
#endif
#ifdef CONFIG_DEBUG_UART
#endif
#if !defined(CONFIG_ROCKCHIP_RK3188)
#endif
#ifdef CONFIG_SYS_ARCH_TIMER
#endif
#if !defined(CONFIG_TPL) || defined(CONFIG_SPL_OS_BOOT)
#endif
#ifdef CONFIG_SPL_LOAD_FIT
#endif
