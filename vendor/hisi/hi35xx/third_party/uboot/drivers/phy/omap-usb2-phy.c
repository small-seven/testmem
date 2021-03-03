#include <common.h>
#include <asm/io.h>
#include <dm.h>
#include <errno.h>
#include <generic-phy.h>
#include <regmap.h>
#include <syscon.h>
#define OMAP_USB2_CALIBRATE_FALSE_DISCONNECT	BIT(0)
#define OMAP_DEV_PHY_PD		BIT(0)
#define OMAP_USB2_PHY_PD	BIT(28)
#define AM437X_USB2_PHY_PD		BIT(0)
#define AM437X_USB2_OTG_PD		BIT(1)
#define AM437X_USB2_OTGVDET_EN		BIT(19)
#define AM437X_USB2_OTGSESSEND_EN	BIT(20)
#define USB2PHY_DISCON_BYP_LATCH	BIT(31)
#define USB2PHY_ANA_CONFIG1		(0x4c)
