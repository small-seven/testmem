#include <common.h>
#include <clk.h>
#include <dm.h>
#include <mailbox-uclass.h>
#include <asm/io.h>
#define IPCC_PROC_OFFST		0x010
#define IPCC_XSCR		0x008
#define IPCC_XTOYSR		0x00c
#define IPCC_HWCFGR		0x3f0
#define IPCFGR_CHAN_MASK	GENMASK(7, 0)
#define RX_BIT_CHAN(chan)	BIT(chan)
#define TX_BIT_SHIFT		16
#define TX_BIT_CHAN(chan)	BIT(TX_BIT_SHIFT + (chan))
#define STM32_MAX_PROCS		2
static int stm32_ipcc_free(struct mbox_chan *chan)
{
	debug("%s(chan=%p)\n", __func__, chan);

	return 0;
}
