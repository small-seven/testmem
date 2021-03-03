#include <dm.h>
#include <linux/bitops.h>
#include <linux/errno.h>
#include <linux/io.h>
#include <linux/sizes.h>
#define UNIPHIER_PRO4_DWC3_RESET	0x40
#define   UNIPHIER_PRO4_DWC3_RESET_XIOMMU	BIT(5)
#define   UNIPHIER_PRO4_DWC3_RESET_XLINK	BIT(4)
#define   UNIPHIER_PRO4_DWC3_RESET_PHY_SS	BIT(2)
#define UNIPHIER_PRO5_DWC3_RESET	0x00
#define   UNIPHIER_PRO5_DWC3_RESET_PHY_S1	BIT(17)
#define   UNIPHIER_PRO5_DWC3_RESET_PHY_S0	BIT(16)
#define   UNIPHIER_PRO5_DWC3_RESET_XLINK	BIT(15)
#define   UNIPHIER_PRO5_DWC3_RESET_XIOMMU	BIT(14)
#define UNIPHIER_PXS2_DWC3_RESET	0x00
#define   UNIPHIER_PXS2_DWC3_RESET_XLINK	BIT(15)
