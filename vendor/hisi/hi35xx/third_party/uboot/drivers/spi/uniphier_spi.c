#include <clk.h>
#include <common.h>
#include <dm.h>
#include <time.h>
#include <linux/bitfield.h>
#include <linux/io.h>
#include <spi.h>
#include <wait_bit.h>
#define SSI_CTL			0x00
#define   SSI_CTL_EN		BIT(0)
#define SSI_CKS			0x04
#define   SSI_CKS_CKRAT_MASK	GENMASK(7, 0)
#define   SSI_CKS_CKPHS		BIT(14)
#define   SSI_CKS_CKINIT	BIT(13)
#define   SSI_CKS_CKDLY		BIT(12)
#define SSI_TXWDS		0x08
#define   SSI_TXWDS_WDLEN_MASK	GENMASK(13, 8)
#define   SSI_TXWDS_TDTF_MASK	GENMASK(7, 6)
#define   SSI_TXWDS_DTLEN_MASK	GENMASK(5, 0)
#define SSI_RXWDS		0x0c
#define   SSI_RXWDS_RDTF_MASK	GENMASK(7, 6)
#define   SSI_RXWDS_DTLEN_MASK	GENMASK(5, 0)
#define SSI_FPS			0x10
#define   SSI_FPS_FSPOL		BIT(15)
#define   SSI_FPS_FSTRT		BIT(14)
#define SSI_SR			0x14
#define   SSI_SR_BUSY		BIT(7)
#define   SSI_SR_TNF		BIT(5)
#define   SSI_SR_RNE		BIT(0)
#define SSI_IE			0x18
#define SSI_IC			0x1c
#define   SSI_IC_TCIC		BIT(4)
#define   SSI_IC_RCIC		BIT(3)
#define   SSI_IC_RORIC		BIT(0)
#define SSI_FC			0x20
#define   SSI_FC_TXFFL		BIT(12)
#define   SSI_FC_TXFTH_MASK	GENMASK(11, 8)
#define   SSI_FC_RXFFL		BIT(4)
#define   SSI_FC_RXFTH_MASK	GENMASK(3, 0)
#define SSI_XDR			0x24	/* TXDR for write, RXDR for read */
#define SSI_FIFO_DEPTH		8U
#define SSI_REG_TIMEOUT		(CONFIG_SYS_HZ / 100)	/* 10 ms */
#define SSI_XFER_TIMEOUT	(CONFIG_SYS_HZ)		/* 1 sec */
#define SSI_CLK			50000000	/* internal I/O clock: 50MHz */
