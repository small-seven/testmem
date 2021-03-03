#include <common.h>
#include <clk.h>
#include <dm.h>
#include <sdhci.h>
#include <wait_bit.h>
#include <asm/io.h>
#include <linux/bitops.h>
#define SDCC_MCI_POWER   0x0
#define SDCC_MCI_POWER_SW_RST BIT(7)
#define SDCC_MCI_VERSION             0x50
#define SDCC_MCI_VERSION_MAJOR_SHIFT 28
#define SDCC_MCI_VERSION_MAJOR_MASK  (0xf << SDCC_MCI_VERSION_MAJOR_SHIFT)
#define SDCC_MCI_VERSION_MINOR_MASK  0xff
#define SDCC_MCI_STATUS2 0x6C
#define SDCC_MCI_STATUS2_MCI_ACT 0x1
#define SDCC_MCI_HC_MODE 0x78
#define SDCC_SDHCI_OFFSET 0x900
#define SDHCI_VENDOR_SPEC_CAPABILITIES0  0x11c
static int msm_sdc_remove(struct udevice *dev)
{
	struct msm_sdhc *priv = dev_get_priv(dev);

	 /* Disable host-controller mode */
	writel(0, priv->base + SDCC_MCI_HC_MODE);

	return 0;
}
