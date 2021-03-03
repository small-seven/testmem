#include <asm/io.h>
#include <clk.h>
#include <common.h>
#include <dm.h>
#define UFS_SS_CTRL             0x4
#define UFS_SS_RST_N_PCS        BIT(0)
#define UFS_SS_CLK_26MHZ        BIT(4)
static int ti_j721e_ufs_remove(struct udevice *dev)
{
	void __iomem *base = dev_remap_addr_index(dev, 0);
	u32 reg = readl(base + UFS_SS_CTRL);

	reg &= ~UFS_SS_RST_N_PCS;
	writel(reg, base + UFS_SS_CTRL);

	return 0;
}
