#include <common.h>
#include <asm/io.h>
#include <asm/arch/at91_common.h>
#include <asm/arch/clk.h>
#include <asm/arch/gpio.h>
#ifdef CONFIG_AT91_GPIO_PULLUP
# define PUP CONFIG_AT91_GPIO_PULLUP
#else
# define PUP 0
#endif
#ifdef CONFIG_ATMEL_SPI
#endif
#if defined(CONFIG_GENERIC_ATMEL_MCI)
#if defined(CONFIG_ATMEL_MCI_PORTB)
#else
#endif
#endif
#ifdef CONFIG_MACB
#ifndef CONFIG_RMII
#endif
#endif
#ifdef CONFIG_USB_OHCI_NEW
#endif
#ifdef CONFIG_AT91_CAN
#endif
