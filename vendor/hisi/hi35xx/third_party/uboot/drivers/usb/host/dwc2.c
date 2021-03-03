#include <common.h>
#include <cpu_func.h>
#include <dm.h>
#include <errno.h>
#include <usb.h>
#include <malloc.h>
#include <memalign.h>
#include <phys2bus.h>
#include <usbroothubdes.h>
#include <wait_bit.h>
#include <asm/io.h>
#include <power/regulator.h>
#include <reset.h>
#include "dwc2.h"
#define DWC2_HC_CHANNEL			0
#define DWC2_STATUS_BUF_SIZE		64
#define DWC2_DATA_BUF_SIZE		(CONFIG_USB_DWC2_BUFFER_SIZE * 1024)
#define MAX_DEVICE			16
#define MAX_ENDPOINT			16
#if CONFIG_IS_ENABLED(DM_USB)
#ifdef CONFIG_DM_REGULATOR
#endif
#else
#endif
#if !CONFIG_IS_ENABLED(DM_USB)
#endif
#if (CONFIG_DWC2_PHY_TYPE == DWC2_PHY_TYPE_FS)
#else
#endif
#ifdef CONFIG_DWC2_ULPI_FS_LS
#endif
#if CONFIG_IS_ENABLED(DM_USB) && defined(CONFIG_DM_REGULATOR)
#else
#if CONFIG_IS_ENABLED(DM_USB)
#endif
#endif
#ifdef CONFIG_DWC2_DFLT_SPEED_FULL
#endif
#ifdef CONFIG_DWC2_ENABLE_DYNAMIC_FIFO
#endif
#ifdef CONFIG_DWC2_TS_DLINE
#else
#endif
#if defined(CONFIG_DWC2_DFLT_SPEED_FULL) && \
#ifdef CONFIG_DWC2_I2C_ENABLE
#endif
#else
#ifdef CONFIG_DWC2_PHY_ULPI_DDR
#else
#endif
#if (CONFIG_DWC2_UTMI_WIDTH == 16)
#endif
#endif
#ifdef CONFIG_DWC2_ULPI_FS_LS
#endif
#ifdef CONFIG_DWC2_DMA_ENABLE
#endif
#ifdef CONFIG_DWC2_DMA_ENABLE
#endif
#ifdef CONFIG_DWC2_IC_USB_CAP
#endif
#ifdef CONFIG_DWC2_PHY_ULPI_EXT_VBUS
#else
#endif
#if !CONFIG_IS_ENABLED(DM_USB)
#endif
#if CONFIG_IS_ENABLED(DM_USB)
static int dwc2_usb_remove(struct udevice *dev)
{
	struct dwc2_priv *priv = dev_get_priv(dev);
	int ret;

	ret = dwc_vbus_supply_exit(dev);
	if (ret)
		return ret;

	dwc2_uninit_common(priv->regs);

	reset_release_bulk(&priv->resets);

	return 0;
}
#endif
