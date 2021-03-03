#include <common.h>
#include <clk.h>
#include <dm.h>
#include <errno.h>
#include <spi.h>
#include <spi-mem.h>
#include <stdbool.h>
#include <watchdog.h>
#include <dm/pinctrl.h>
#include <linux/bitops.h>
#include <linux/io.h>
#include <linux/iopoll.h>
#define SNFI_MAC_CTL			0x500
#define MAC_XIO_SEL			BIT(4)
#define SF_MAC_EN			BIT(3)
#define SF_TRIG				BIT(2)
#define WIP_READY			BIT(1)
#define WIP				BIT(0)
#define SNFI_MAC_OUTL			0x504
#define SNFI_MAC_INL			0x508
#define SNFI_MISC_CTL			0x538
#define SW_RST				BIT(28)
#define FIFO_RD_LTC_SHIFT		25
#define FIFO_RD_LTC			GENMASK(26, 25)
#define LATCH_LAT_SHIFT			8
#define LATCH_LAT			GENMASK(9, 8)
#define CS_DESELECT_CYC_SHIFT		0
#define CS_DESELECT_CYC			GENMASK(4, 0)
#define SNF_STA_CTL1			0x550
#define SPI_STATE			GENMASK(3, 0)
#define SNFI_GPRAM_OFFSET		0x800
#define SNFI_GPRAM_SIZE			0x80
#define SNFI_POLL_INTERVAL		500000
#define SNFI_RST_POLL_INTERVAL		1000000
#ifdef CONFIG_PINCTRL
#endif
#ifdef CONFIG_PINCTRL
#endif
