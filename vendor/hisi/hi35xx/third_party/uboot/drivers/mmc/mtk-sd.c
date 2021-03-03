#include <clk.h>
#include <common.h>
#include <dm.h>
#include <mmc.h>
#include <errno.h>
#include <malloc.h>
#include <stdbool.h>
#include <watchdog.h>
#include <asm/gpio.h>
#include <dm/pinctrl.h>
#include <linux/bitops.h>
#include <linux/io.h>
#include <linux/iopoll.h>
#define MSDC_CFG_HS400_CK_MODE_EXT	BIT(22)
#define MSDC_CFG_CKMOD_EXT_M		0x300000
#define MSDC_CFG_CKMOD_EXT_S		20
#define MSDC_CFG_CKDIV_EXT_M		0xfff00
#define MSDC_CFG_CKDIV_EXT_S		8
#define MSDC_CFG_HS400_CK_MODE		BIT(18)
#define MSDC_CFG_CKMOD_M		0x30000
#define MSDC_CFG_CKMOD_S		16
#define MSDC_CFG_CKDIV_M		0xff00
#define MSDC_CFG_CKDIV_S		8
#define MSDC_CFG_CKSTB			BIT(7)
#define MSDC_CFG_PIO			BIT(3)
#define MSDC_CFG_RST			BIT(2)
#define MSDC_CFG_CKPDN			BIT(1)
#define MSDC_CFG_MODE			BIT(0)
#define MSDC_IOCON_W_DSPL		BIT(8)
#define MSDC_IOCON_DSPL			BIT(2)
#define MSDC_IOCON_RSPL			BIT(1)
#define MSDC_PS_DAT0			BIT(16)
#define MSDC_PS_CDDBCE_M		0xf000
#define MSDC_PS_CDDBCE_S		12
#define MSDC_PS_CDSTS			BIT(1)
#define MSDC_PS_CDEN			BIT(0)
#define MSDC_INT_ACMDRDY		BIT(3)
#define MSDC_INT_ACMDTMO		BIT(4)
#define MSDC_INT_ACMDCRCERR		BIT(5)
#define MSDC_INT_CMDRDY			BIT(8)
#define MSDC_INT_CMDTMO			BIT(9)
#define MSDC_INT_RSPCRCERR		BIT(10)
#define MSDC_INT_XFER_COMPL		BIT(12)
#define MSDC_INT_DATTMO			BIT(14)
#define MSDC_INT_DATCRCERR		BIT(15)
#define MSDC_FIFOCS_CLR			BIT(31)
#define MSDC_FIFOCS_TXCNT_M		0xff0000
#define MSDC_FIFOCS_TXCNT_S		16
#define MSDC_FIFOCS_RXCNT_M		0xff
#define MSDC_FIFOCS_RXCNT_S		0
#define SDC_CFG_DTOC_M			0xff000000
#define SDC_CFG_DTOC_S			24
#define SDC_CFG_SDIOIDE			BIT(20)
#define SDC_CFG_SDIO			BIT(19)
#define SDC_CFG_BUSWIDTH_M		0x30000
#define SDC_CFG_BUSWIDTH_S		16
#define SDC_CMD_BLK_LEN_M		0xfff0000
#define SDC_CMD_BLK_LEN_S		16
#define SDC_CMD_STOP			BIT(14)
#define SDC_CMD_WR			BIT(13)
#define SDC_CMD_DTYPE_M			0x1800
#define SDC_CMD_DTYPE_S			11
#define SDC_CMD_RSPTYP_M		0x380
#define SDC_CMD_RSPTYP_S		7
#define SDC_CMD_CMD_M			0x3f
#define SDC_CMD_CMD_S			0
#define SDC_STS_CMDBUSY			BIT(1)
#define SDC_STS_SDCBUSY			BIT(0)
#define SDC_RX_ENHANCE_EN		BIT(20)
#define MSDC_INT_DAT_LATCH_CK_SEL_M	0x380
#define MSDC_INT_DAT_LATCH_CK_SEL_S	7
#define MSDC_PB1_STOP_DLY_M		0xf00
#define MSDC_PB1_STOP_DLY_S		8
#define MSDC_PB2_CRCSTSENSEL_M		0xe0000000
#define MSDC_PB2_CRCSTSENSEL_S		29
#define MSDC_PB2_CFGCRCSTS		BIT(28)
#define MSDC_PB2_RESPSTSENSEL_M		0x70000
#define MSDC_PB2_RESPSTSENSEL_S		16
#define MSDC_PB2_CFGRESP		BIT(15)
#define MSDC_PB2_RESPWAIT_M		0x0c
#define MSDC_PB2_RESPWAIT_S		2
#define MSDC_PAD_TUNE_CMDRRDLY_M	0x7c00000
#define MSDC_PAD_TUNE_CMDRRDLY_S	22
#define MSDC_PAD_TUNE_CMD_SEL		BIT(21)
#define MSDC_PAD_TUNE_CMDRDLY_M		0x1f0000
#define MSDC_PAD_TUNE_CMDRDLY_S		16
#define MSDC_PAD_TUNE_RXDLYSEL		BIT(15)
#define MSDC_PAD_TUNE_RD_SEL		BIT(13)
#define MSDC_PAD_TUNE_DATRRDLY_M	0x1f00
#define MSDC_PAD_TUNE_DATRRDLY_S	8
#define MSDC_PAD_TUNE_DATWRDLY_M	0x1f
#define MSDC_PAD_TUNE_DATWRDLY_S	0
#define PAD_CMD_TUNE_RX_DLY3		0x3E
#define PAD_CMD_TUNE_RX_DLY3_S		1
#define EMMC50_CFG_CFCSTS_SEL		BIT(4)
#define SDC_FIFO_CFG_WRVALIDSEL		BIT(24)
#define SDC_FIFO_CFG_RDVALIDSEL		BIT(25)
#define MSDC_BUS_1BITS			0x0
#define MSDC_BUS_4BITS			0x1
#define MSDC_BUS_8BITS			0x2
#define MSDC_FIFO_SIZE			128
#define PAD_DELAY_MAX			32
#define DEFAULT_CD_DEBOUNCE		8
#define CMD_INTS_MASK	\
#define DATA_INTS_MASK	\
#if CONFIG_IS_ENABLED(DM_GPIO)
#endif
#if CONFIG_IS_ENABLED(DM_GPIO)
#else
#endif
#if CONFIG_IS_ENABLED(DM_GPIO)
#else
#endif
#ifdef MMC_SUPPORTS_TUNING
#endif
#ifdef CONFIG_PINCTRL
#endif
#if CONFIG_IS_ENABLED(DM_GPIO)
#endif
#ifdef MMC_SUPPORTS_TUNING
#endif
