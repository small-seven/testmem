#include <common.h>
#include <dm.h>
#include <dm/device.h>
#include <generic-phy.h>
#include <asm/io.h>
#include <asm/arch/psc_defs.h>
#define USB_PHY_CTL_UTMI		0x0000
#define USB_PHY_CTL_PIPE		0x0004
#define USB_PHY_CTL_PARAM_1		0x0008
#define USB_PHY_CTL_PARAM_2		0x000c
#define USB_PHY_CTL_CLOCK		0x0010
#define USB_PHY_CTL_PLL			0x0014
#define PHY_OTG_VBUSVLDECTSEL		BIT(16)
#define PHY_REF_SSP_EN			BIT(29)
