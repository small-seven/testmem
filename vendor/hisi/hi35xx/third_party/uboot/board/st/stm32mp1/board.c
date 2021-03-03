#include <common.h>
#include <dm.h>
#include <asm/io.h>
#include <asm/arch/ddr.h>
#include <power/pmic.h>
#include <power/stpmic1.h>
#ifdef CONFIG_DEBUG_UART_BOARD_INIT
#if (CONFIG_DEBUG_UART_BASE == STM32_UART4_BASE)
#define RCC_MP_APB1ENSETR (STM32_RCC_BASE + 0x0A00)
#define RCC_MP_AHB4ENSETR (STM32_RCC_BASE + 0x0A28)
#define GPIOG_BASE 0x50008000
#else
#error("CONFIG_DEBUG_UART_BASE: not supported value")
#endif
#endif
#ifdef CONFIG_PMIC_STPMIC1
#endif
