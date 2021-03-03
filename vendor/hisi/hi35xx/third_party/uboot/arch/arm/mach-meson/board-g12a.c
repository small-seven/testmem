#include <common.h>
#include <asm/arch/boot.h>
#include <asm/arch/eth.h>
#include <asm/arch/g12a.h>
#include <asm/arch/mem.h>
#include <asm/arch/meson-vpu.h>
#include <asm/io.h>
#include <asm/armv8/mmu.h>
#include <linux/sizes.h>
#include <usb.h>
#include <linux/usb/otg.h>
#include <asm/arch/usb.h>
#include <usb/dwc2_udc.h>
#include <phy.h>
#include <clk.h>
#if defined(CONFIG_VIDEO_MESON)
#endif
#if CONFIG_IS_ENABLED(USB_DWC3_MESON_G12A) && \
#endif
