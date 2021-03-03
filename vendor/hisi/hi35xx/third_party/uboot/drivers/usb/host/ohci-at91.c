#include <common.h>
#if defined(CONFIG_USB_OHCI_NEW) && defined(CONFIG_SYS_USB_OHCI_CPU_INIT)
#include <asm/arch/clk.h>
#ifdef CONFIG_USB_ATMEL_CLK_SEL_PLLB
#ifdef CONFIG_AT91SAM9N12
#endif
#elif defined(CONFIG_USB_ATMEL_CLK_SEL_UPLL)
#endif
#if defined(CONFIG_AT91SAM9261) || defined(CONFIG_AT91SAM9G10)
#endif
#if defined(CONFIG_AT91SAM9261) || defined(CONFIG_AT91SAM9G10)
#endif
#ifdef CONFIG_USB_ATMEL_CLK_SEL_PLLB
#ifdef CONFIG_AT91SAM9N12
#endif
#elif defined(CONFIG_USB_ATMEL_CLK_SEL_UPLL)
#endif
#endif /* defined(CONFIG_USB_OHCI) && defined(CONFIG_SYS_USB_OHCI_CPU_INIT) */
