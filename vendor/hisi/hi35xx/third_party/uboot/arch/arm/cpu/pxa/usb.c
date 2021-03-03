#include <common.h>
#if defined(CONFIG_USB_OHCI_NEW) && defined(CONFIG_SYS_USB_OHCI_CPU_INIT)
# if defined(CONFIG_CPU_MONAHANS) || defined(CONFIG_CPU_PXA27X)
#include <asm/arch/pxa-regs.h>
#include <asm/io.h>
#include <usb.h>
#if defined(CONFIG_CPU_MONAHANS)
#endif
#if defined(CONFIG_CPU_PXA27X)
#endif
#if defined(CONFIG_CPU_MONAHANS)
#endif
#if defined(CONFIG_CPU_MONAHANS) || defined(CONFIG_PXA27X)
#endif
#if defined(CONFIG_CPU_PXA27X)
#endif
#if defined(CONFIG_CPU_MONAHANS) || defined(CONFIG_PXA27X)
#endif
#if defined(CONFIG_CPU_PXA27X)
#endif
#if defined(CONFIG_CPU_MONAHANS)
#endif
#if defined(CONFIG_CPU_PXA27X)
#endif
# endif /* defined(CONFIG_CPU_MONAHANS) || defined(CONFIG_CPU_PXA27X) */
#endif /* defined(CONFIG_USB_OHCI) && defined(CONFIG_SYS_USB_OHCI_CPU_INIT) */
