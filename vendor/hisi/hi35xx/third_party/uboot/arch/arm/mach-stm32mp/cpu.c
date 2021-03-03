#include <common.h>
#include <clk.h>
#include <cpu_func.h>
#include <debug_uart.h>
#include <env.h>
#include <misc.h>
#include <asm/io.h>
#include <asm/arch/stm32.h>
#include <asm/arch/sys_proto.h>
#include <dm/device.h>
#include <dm/uclass.h>
#define RCC_TZCR		(STM32_RCC_BASE + 0x00)
#define RCC_DBGCFGR		(STM32_RCC_BASE + 0x080C)
#define RCC_BDCR		(STM32_RCC_BASE + 0x0140)
#define RCC_MP_APB5ENSETR	(STM32_RCC_BASE + 0x0208)
#define RCC_MP_AHB5ENSETR	(STM32_RCC_BASE + 0x0210)
#define RCC_BDCR_VSWRST		BIT(31)
#define RCC_BDCR_RTCSRC		GENMASK(17, 16)
#define RCC_DBGCFGR_DBGCKEN	BIT(8)
#define ETZPC_TZMA1_SIZE	(STM32_ETZPC_BASE + 0x04)
#define ETZPC_DECPROT0		(STM32_ETZPC_BASE + 0x10)
#define TZC_GATE_KEEPER		(STM32_TZC_BASE + 0x008)
#define TZC_REGION_ATTRIBUTE0	(STM32_TZC_BASE + 0x110)
#define TZC_REGION_ID_ACCESS0	(STM32_TZC_BASE + 0x114)
#define TAMP_CR1		(STM32_TAMP_BASE + 0x00)
#define PWR_CR1			(STM32_PWR_BASE + 0x00)
#define PWR_CR1_DBP		BIT(8)
#define DBGMCU_IDC		(STM32_DBGMCU_BASE + 0x00)
#define DBGMCU_APB4FZ1		(STM32_DBGMCU_BASE + 0x2C)
#define DBGMCU_APB4FZ1_IWDG2	BIT(2)
#define DBGMCU_IDC_DEV_ID_MASK	GENMASK(11, 0)
#define DBGMCU_IDC_DEV_ID_SHIFT	0
#define DBGMCU_IDC_REV_ID_MASK	GENMASK(31, 16)
#define DBGMCU_IDC_REV_ID_SHIFT	16
#define GPIOZ_SECCFGR		0x54004030
#define BOOTROM_PARAM_ADDR	0x2FFC0078
#define BOOTROM_MODE_MASK	GENMASK(15, 0)
#define BOOTROM_MODE_SHIFT	0
#define BOOTROM_INSTANCE_MASK	 GENMASK(31, 16)
#define BOOTROM_INSTANCE_SHIFT	16
#define BSEC_OTP_RPN	1
#define BSEC_OTP_SERIAL	13
#define BSEC_OTP_PKG	16
#define BSEC_OTP_MAC	57
#define RPN_SHIFT	0
#define RPN_MASK	GENMASK(7, 0)
#define PKG_SHIFT	27
#define PKG_MASK	GENMASK(2, 0)
#if !defined(CONFIG_SPL) || defined(CONFIG_SPL_BUILD)
#ifndef CONFIG_STM32MP1_TRUSTED
#endif /* CONFIG_STM32MP1_TRUSTED */
#endif /* !defined(CONFIG_SPL) || defined(CONFIG_SPL_BUILD) */
#if !defined(CONFIG_STM32MP1_TRUSTED) && \
#endif
#if !defined(CONFIG_SPL) || defined(CONFIG_SPL_BUILD)
#ifndef CONFIG_STM32MP1_TRUSTED
#endif
#endif
#if defined(CONFIG_DEBUG_UART) && \
#endif
#if defined(CONFIG_DISPLAY_CPUINFO)
#endif /* CONFIG_DISPLAY_CPUINFO */
#if defined(CONFIG_NET)
#endif
