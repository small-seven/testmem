#include <common.h>
#include <clk.h>
#include <cpu_func.h>
#include <dm.h>
#include <errno.h>
#include <miiphy.h>
#include <malloc.h>
#include <linux/mii.h>
#include <wait_bit.h>
#include <asm/io.h>
#include <asm/gpio.h>
#define RAVB_REG_CCC		0x000
#define RAVB_REG_DBAT		0x004
#define RAVB_REG_CSR		0x00C
#define RAVB_REG_APSR		0x08C
#define RAVB_REG_RCR		0x090
#define RAVB_REG_TGC		0x300
#define RAVB_REG_TCCR		0x304
#define RAVB_REG_RIC0		0x360
#define RAVB_REG_RIC1		0x368
#define RAVB_REG_RIC2		0x370
#define RAVB_REG_TIC		0x378
#define RAVB_REG_ECMR		0x500
#define RAVB_REG_RFLR		0x508
#define RAVB_REG_ECSIPR		0x518
#define RAVB_REG_PIR		0x520
#define RAVB_REG_GECMR		0x5b0
#define RAVB_REG_MAHR		0x5c0
#define RAVB_REG_MALR		0x5c8
#define CCC_OPC_CONFIG		BIT(0)
#define CCC_OPC_OPERATION	BIT(1)
#define CCC_BOC			BIT(20)
#define CSR_OPS			0x0000000F
#define CSR_OPS_CONFIG		BIT(1)
#define APSR_TDM		BIT(14)
#define TCCR_TSRQ0		BIT(0)
#define RFLR_RFL_MIN		0x05EE
#define PIR_MDI			BIT(3)
#define PIR_MDO			BIT(2)
#define PIR_MMD			BIT(1)
#define PIR_MDC			BIT(0)
#define ECMR_TRCCM		BIT(26)
#define ECMR_RZPF		BIT(20)
#define ECMR_PFR		BIT(18)
#define ECMR_RXF		BIT(17)
#define ECMR_RE			BIT(6)
#define ECMR_TE			BIT(5)
#define ECMR_DM			BIT(1)
#define ECMR_CHG_DM		(ECMR_TRCCM | ECMR_RZPF | ECMR_PFR | ECMR_RXF)
#define RAVB_NUM_BASE_DESC		16
#define RAVB_NUM_TX_DESC		8
#define RAVB_NUM_RX_DESC		8
#define RAVB_TX_QUEUE_OFFSET		0
#define RAVB_RX_QUEUE_OFFSET		4
#define RAVB_DESC_DT(n)			((n) << 28)
#define RAVB_DESC_DT_FSINGLE		RAVB_DESC_DT(0x7)
#define RAVB_DESC_DT_LINKFIX		RAVB_DESC_DT(0x9)
#define RAVB_DESC_DT_EOS		RAVB_DESC_DT(0xa)
#define RAVB_DESC_DT_FEMPTY		RAVB_DESC_DT(0xc)
#define RAVB_DESC_DT_EEMPTY		RAVB_DESC_DT(0x3)
#define RAVB_DESC_DT_MASK		RAVB_DESC_DT(0xf)
#define RAVB_DESC_DS(n)			(((n) & 0xfff) << 0)
#define RAVB_DESC_DS_MASK		0xfff
#define RAVB_RX_DESC_MSC_MC		BIT(23)
#define RAVB_RX_DESC_MSC_CEEF		BIT(22)
#define RAVB_RX_DESC_MSC_CRL		BIT(21)
#define RAVB_RX_DESC_MSC_FRE		BIT(20)
#define RAVB_RX_DESC_MSC_RTLF		BIT(19)
#define RAVB_RX_DESC_MSC_RTSF		BIT(18)
#define RAVB_RX_DESC_MSC_RFE		BIT(17)
#define RAVB_RX_DESC_MSC_CRC		BIT(16)
#define RAVB_RX_DESC_MSC_MASK		(0xff << 16)
#define RAVB_RX_DESC_MSC_RX_ERR_MASK \
#define RAVB_TX_TIMEOUT_MS		1000
static int ravb_remove(struct udevice *dev)
{
	struct ravb_priv *eth = dev_get_priv(dev);

	clk_disable(&eth->clk);

	free(eth->phydev);
	mdio_unregister(eth->bus);
	mdio_free(eth->bus);
	if (dm_gpio_is_valid(&eth->reset_gpio))
		dm_gpio_free(dev, &eth->reset_gpio);
	unmap_physmem(eth->iobase, MAP_NOCACHE);

	return 0;
}
