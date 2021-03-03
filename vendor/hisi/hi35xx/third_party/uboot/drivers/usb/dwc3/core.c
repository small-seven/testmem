#include <common.h>
#include <cpu_func.h>
#include <malloc.h>
#include <dwc3-uboot.h>
#include <asm/dma-mapping.h>
#include <linux/ioport.h>
#include <dm.h>
#include <generic-phy.h>
#include <linux/usb/ch9.h>
#include <linux/usb/gadget.h>
#include "core.h"
#include "gadget.h"
#include "io.h"
#include "linux-compat.h"
#define DWC3_ALIGN_MASK		(16 - 1)
#if CONFIG_IS_ENABLED(PHY) && CONFIG_IS_ENABLED(DM_USB)
#endif
#if CONFIG_IS_ENABLED(DM_USB)
void dwc3_remove(struct dwc3 *dwc)
{
	dwc3_core_exit_mode(dwc);
	dwc3_event_buffers_cleanup(dwc);
	dwc3_free_event_buffers(dwc);
	dwc3_core_exit(dwc);
	kfree(dwc->mem);
}
#endif
