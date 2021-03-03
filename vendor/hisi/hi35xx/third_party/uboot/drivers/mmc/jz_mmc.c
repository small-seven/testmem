#include <common.h>
#include <malloc.h>
#include <mmc.h>
#include <asm/io.h>
#include <asm/unaligned.h>
#include <errno.h>
#include <mach/jz4780.h>
#include <wait_bit.h>
#define MSC_STRPCL			0x000
#define MSC_STAT			0x004
#define MSC_CLKRT			0x008
#define MSC_CMDAT			0x00c
#define MSC_RESTO			0x010
#define MSC_RDTO			0x014
#define MSC_BLKLEN			0x018
#define MSC_NOB				0x01c
#define MSC_SNOB			0x020
#define MSC_IMASK			0x024
#define MSC_IREG			0x028
#define MSC_CMD				0x02c
#define MSC_ARG				0x030
#define MSC_RES				0x034
#define MSC_RXFIFO			0x038
#define MSC_TXFIFO			0x03c
#define MSC_LPM				0x040
#define MSC_DMAC			0x044
#define MSC_DMANDA			0x048
#define MSC_DMADA			0x04c
#define MSC_DMALEN			0x050
#define MSC_DMACMD			0x054
#define MSC_CTRL2			0x058
#define MSC_RTCNT			0x05c
#define MSC_DBG				0x0fc
#define MSC_STRPCL_EXIT_MULTIPLE	BIT(7)
#define MSC_STRPCL_EXIT_TRANSFER	BIT(6)
#define MSC_STRPCL_START_READWAIT	BIT(5)
#define MSC_STRPCL_STOP_READWAIT	BIT(4)
#define MSC_STRPCL_RESET		BIT(3)
#define MSC_STRPCL_START_OP		BIT(2)
#define MSC_STRPCL_CLOCK_CONTROL_STOP	BIT(0)
#define MSC_STRPCL_CLOCK_CONTROL_START	BIT(1)
#define MSC_STAT_AUTO_CMD_DONE		BIT(31)
#define MSC_STAT_IS_RESETTING		BIT(15)
#define MSC_STAT_SDIO_INT_ACTIVE	BIT(14)
#define MSC_STAT_PRG_DONE		BIT(13)
#define MSC_STAT_DATA_TRAN_DONE		BIT(12)
#define MSC_STAT_END_CMD_RES		BIT(11)
#define MSC_STAT_DATA_FIFO_AFULL	BIT(10)
#define MSC_STAT_IS_READWAIT		BIT(9)
#define MSC_STAT_CLK_EN			BIT(8)
#define MSC_STAT_DATA_FIFO_FULL		BIT(7)
#define MSC_STAT_DATA_FIFO_EMPTY	BIT(6)
#define MSC_STAT_CRC_RES_ERR		BIT(5)
#define MSC_STAT_CRC_READ_ERROR		BIT(4)
#define MSC_STAT_CRC_WRITE_ERROR	BIT(2)
#define MSC_STAT_CRC_WRITE_ERROR_NOSTS	BIT(4)
#define MSC_STAT_TIME_OUT_RES		BIT(1)
#define MSC_STAT_TIME_OUT_READ		BIT(0)
#define MSC_CLKRT_CLK_RATE_MASK		0x7
#define MSC_CMDAT_IO_ABORT		BIT(11)
#define MSC_CMDAT_BUS_WIDTH_1BIT	(0x0 << 9)
#define MSC_CMDAT_BUS_WIDTH_4BIT	(0x2 << 9)
#define MSC_CMDAT_DMA_EN		BIT(8)
#define MSC_CMDAT_INIT			BIT(7)
#define MSC_CMDAT_BUSY			BIT(6)
#define MSC_CMDAT_STREAM_BLOCK		BIT(5)
#define MSC_CMDAT_WRITE			BIT(4)
#define MSC_CMDAT_DATA_EN		BIT(3)
#define MSC_CMDAT_RESPONSE_MASK		(0x7 << 0)
#define MSC_CMDAT_RESPONSE_NONE		(0x0 << 0) /* No response */
#define MSC_CMDAT_RESPONSE_R1		(0x1 << 0) /* Format R1 and R1b */
#define MSC_CMDAT_RESPONSE_R2		(0x2 << 0) /* Format R2 */
#define MSC_CMDAT_RESPONSE_R3		(0x3 << 0) /* Format R3 */
#define MSC_CMDAT_RESPONSE_R4		(0x4 << 0) /* Format R4 */
#define MSC_CMDAT_RESPONSE_R5		(0x5 << 0) /* Format R5 */
#define MSC_CMDAT_RESPONSE_R6		(0x6 << 0) /* Format R6 */
#define MSC_IMASK_TIME_OUT_RES		BIT(9)
#define MSC_IMASK_TIME_OUT_READ		BIT(8)
#define MSC_IMASK_SDIO			BIT(7)
#define MSC_IMASK_TXFIFO_WR_REQ		BIT(6)
#define MSC_IMASK_RXFIFO_RD_REQ		BIT(5)
#define MSC_IMASK_END_CMD_RES		BIT(2)
#define MSC_IMASK_PRG_DONE		BIT(1)
#define MSC_IMASK_DATA_TRAN_DONE	BIT(0)
#define MSC_IREG_TIME_OUT_RES		BIT(9)
#define MSC_IREG_TIME_OUT_READ		BIT(8)
#define MSC_IREG_SDIO			BIT(7)
#define MSC_IREG_TXFIFO_WR_REQ		BIT(6)
#define MSC_IREG_RXFIFO_RD_REQ		BIT(5)
#define MSC_IREG_END_CMD_RES		BIT(2)
#define MSC_IREG_PRG_DONE		BIT(1)
#define MSC_IREG_DATA_TRAN_DONE		BIT(0)
#define JZ_MMC_BUS_WIDTH_MASK	0x3
#define JZ_MMC_BUS_WIDTH_1	0x0
#define JZ_MMC_BUS_WIDTH_4	0x2
#define JZ_MMC_BUS_WIDTH_8	0x3
#define JZ_MMC_SENT_INIT	BIT(2)
#if CONFIG_IS_ENABLED(MMC_WRITE)
#else
#endif
#if !CONFIG_IS_ENABLED(DM_MMC)
#else /* CONFIG_DM_MMC */
#include <dm.h>
#endif /* CONFIG_DM_MMC */
