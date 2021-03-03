#include <config.h>
#include <common.h>
#include <phy.h>
#include <dm.h>
#define MII_PHY_STATUS_SPD_MASK		0x0C00
#define MII_PHY_STATUS_FULLDUPLEX	0x1000
#define MII_PHY_STATUS_1000		0x0800
#define MII_PHY_STATUS_100		0x0400
#define XPCSPMA_PHY_CTRL_ISOLATE_DISABLE 0xFBFF
#define XILINX_PHY_ID_MASK		0xfffffff0
#define XILINX_PHY_ID			0x01740c00
#define XAE_PHY_TYPE_MII		0
#define XAE_PHY_TYPE_GMII		1
#define XAE_PHY_TYPE_RGMII_1_3		2
#define XAE_PHY_TYPE_RGMII_2_0		3
#define XAE_PHY_TYPE_SGMII		4
#define XAE_PHY_TYPE_1000BASE_X		5
