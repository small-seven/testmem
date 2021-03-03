#include <common.h>
#include <cpu_func.h>
#include <dm.h>
#include <malloc.h>
#include <miiphy.h>
#include <net.h>
#include <reset.h>
#include <wait_bit.h>
#include <asm/io.h>
#include <linux/bitfield.h>
#include <linux/err.h>
#define PDMA_RELATED		0x0800
#define TX_BASE_PTR0		(PDMA_RELATED + 0x000)
#define TX_MAX_CNT0		(PDMA_RELATED + 0x004)
#define TX_CTX_IDX0		(PDMA_RELATED + 0x008)
#define TX_DTX_IDX0		(PDMA_RELATED + 0x00c)
#define RX_BASE_PTR0		(PDMA_RELATED + 0x100)
#define RX_MAX_CNT0		(PDMA_RELATED + 0x104)
#define RX_CALC_IDX0		(PDMA_RELATED + 0x108)
#define PDMA_GLO_CFG		(PDMA_RELATED + 0x204)
#define PDMA_RST_IDX		(PDMA_RELATED + 0x208)
#define DLY_INT_CFG		(PDMA_RELATED + 0x20c)
#define SDM_RELATED		0x0c00
#define SDM_MAC_ADRL		(SDM_RELATED + 0x0c)	/* MAC address LSB */
#define SDM_MAC_ADRH		(SDM_RELATED + 0x10)	/* MAC Address MSB */
#define RST_DTX_IDX0		BIT(0)
#define RST_DRX_IDX0		BIT(16)
#define TX_DMA_EN		BIT(0)
#define TX_DMA_BUSY		BIT(1)
#define RX_DMA_EN		BIT(2)
#define RX_DMA_BUSY		BIT(3)
#define TX_WB_DDONE		BIT(6)
#define MT7628_SWITCH_FCT0	0x0008
#define MT7628_SWITCH_PFC1	0x0014
#define MT7628_SWITCH_PVIDC0	0x0040
#define MT7628_SWITCH_PVIDC1	0x0044
#define MT7628_SWITCH_PVIDC2	0x0048
#define MT7628_SWITCH_PVIDC3	0x004c
#define MT7628_SWITCH_VMSC0	0x0070
#define MT7628_SWITCH_FPA	0x0084
#define MT7628_SWITCH_SOCPC	0x008c
#define MT7628_SWITCH_POC0	0x0090
#define MT7628_SWITCH_POC2	0x0098
#define MT7628_SWITCH_SGC	0x009c
#define MT7628_SWITCH_PCR0	0x00c0
#define PCR0_PHY_ADDR		GENMASK(4, 0)
#define PCR0_PHY_REG		GENMASK(12, 8)
#define PCR0_WT_PHY_CMD		BIT(13)
#define PCR0_RD_PHY_CMD		BIT(14)
#define PCR0_WT_DATA		GENMASK(31, 16)
#define MT7628_SWITCH_PCR1	0x00c4
#define PCR1_WT_DONE		BIT(0)
#define PCR1_RD_RDY		BIT(1)
#define PCR1_RD_DATA		GENMASK(31, 16)
#define MT7628_SWITCH_FPA1	0x00c8
#define MT7628_SWITCH_FCT2	0x00cc
#define MT7628_SWITCH_SGC2	0x00e4
#define MT7628_SWITCH_BMU_CTRL	0x0110
#define RX_DMA_DONE		BIT(31)
#define RX_DMA_LSO		BIT(30)
#define RX_DMA_PLEN0		GENMASK(29, 16)
#define RX_DMA_TAG		BIT(15)
#define TX_DMA_PLEN0		GENMASK(29, 16)
#define TX_DMA_LS1		BIT(14)
#define TX_DMA_LS0		BIT(30)
#define TX_DMA_DONE		BIT(31)
#define TX_DMA_INS_VLAN_MT7621	BIT(16)
#define TX_DMA_INS_VLAN		BIT(7)
#define TX_DMA_INS_PPPOE	BIT(12)
#define TX_DMA_PN		GENMASK(26, 24)
#define NUM_RX_DESC		256
#define NUM_TX_DESC		4
#define NUM_PHYS		5
#define PADDING_LENGTH		60
#define MTK_QDMA_PAGE_SIZE	2048
#define CONFIG_MDIO_TIMEOUT	100
#define CONFIG_DMA_STOP_TIMEOUT	100
#define CONFIG_TX_DMA_TIMEOUT	100
