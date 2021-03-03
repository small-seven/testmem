#include <dm.h>
#include <common.h>
#include <asm/io.h>
#include <dm/platform_data/serial_pl01x.h>
#include <asm/arch/hi3798cv200.h>
#include <asm/armv8/mmu.h>
#if !CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#define KERNEL_TEXT_OFFSET	0x00080000
#if defined(CONFIG_USB_GADGET) && defined(CONFIG_USB_GADGET_DWC2_OTG)
#include <env.h>
#include <usb.h>
#include <usb/dwc2_udc.h>
#include <g_dnl.h>
#endif
