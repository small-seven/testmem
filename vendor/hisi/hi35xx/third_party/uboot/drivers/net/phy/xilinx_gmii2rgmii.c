#include <dm.h>
#include <phy.h>
#include <config.h>
#include <common.h>
#define ZYNQ_GMII2RGMII_REG		0x10
#define ZYNQ_GMII2RGMII_SPEED_MASK	(BMCR_SPEED1000 | BMCR_SPEED100)
