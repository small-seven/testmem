#include <common.h>
#include <cpu_func.h>
#include <asm/arch/cpu.h>
#include <asm/arch/armada100.h>
#define UARTCLK14745KHZ	(APBC_APBCLK | APBC_FNCLK | APBC_FNCLKSEL(1))
#define SET_MRVL_ID	(1<<8)
#define L2C_RAM_SEL	(1<<4)
#ifdef CONFIG_I2C_MV
#endif
#if (CONFIG_SYS_NS16550_COM1 == ARMD1_UART3_BASE)
#elif (CONFIG_SYS_NS16550_COM1 == ARMD1_UART2_BASE)
#else
#endif
#if defined(CONFIG_DISPLAY_CPUINFO)
#endif
#ifdef CONFIG_I2C_MV
#endif
