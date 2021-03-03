#include <common.h>
#include <spl.h>
#include <spl_gpio.h>
#include <syscon.h>
#include <asm/armv8/mmu.h>
#include <asm/io.h>
#include <asm/arch-rockchip/bootrom.h>
#include <asm/arch-rockchip/clock.h>
#include <asm/arch-rockchip/gpio.h>
#include <asm/arch-rockchip/grf_rk3399.h>
#include <asm/arch-rockchip/hardware.h>
#include <power/regulator.h>
#define GRF_EMMCCORE_CON11 0xff77f02c
#define GRF_BASE	0xff770000
#ifdef CONFIG_SPL_BUILD
#define TIMER_END_COUNT_L	0x00
#define TIMER_END_COUNT_H	0x04
#define TIMER_INIT_COUNT_L	0x10
#define TIMER_INIT_COUNT_H	0x14
#define TIMER_CONTROL_REG	0x1c
#define TIMER_EN	0x1
#define TIMER_FMODE	BIT(0)
#define TIMER_RMODE	BIT(1)
#endif
#ifdef CONFIG_SPL_BUILD
#endif
#ifdef CONFIG_DEBUG_UART_BOARD_INIT
#define GRF_BASE	0xff770000
#define GPIO0_BASE	0xff720000
#define PMUGRF_BASE	0xff320000
#ifdef CONFIG_TARGET_CHROMEBOOK_BOB
#endif
#if defined(CONFIG_DEBUG_UART_BASE) && (CONFIG_DEBUG_UART_BASE == 0xff180000)
#elif defined(CONFIG_DEBUG_UART_BASE) && (CONFIG_DEBUG_UART_BASE == 0xff1B0000)
#else
# ifdef CONFIG_TARGET_CHROMEBOOK_BOB
#endif /* CONFIG_TARGET_CHROMEBOOK_BOB */
#endif
#endif
#if defined(CONFIG_SPL_BUILD) && !defined(CONFIG_TPL_BUILD)
#if defined(SPL_GPIO_SUPPORT)
#endif
#if defined(SPL_GPIO_SUPPORT)
#endif
#if defined(SPL_DM_REGULATOR)
#endif
#endif
