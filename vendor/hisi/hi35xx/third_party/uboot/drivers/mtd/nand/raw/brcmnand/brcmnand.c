#include <common.h>
#include <asm/io.h>
#include <memalign.h>
#include <nand.h>
#include <clk.h>
#include <linux/ioport.h>
#include <linux/completion.h>
#include <linux/errno.h>
#include <linux/log2.h>
#include <asm/processor.h>
#include <dm.h>
#include "brcmnand.h"
#include "brcmnand_compat.h"
#define DRV_NAME			"brcmnand"
#define CMD_NULL			0x00
#define CMD_PAGE_READ			0x01
#define CMD_SPARE_AREA_READ		0x02
#define CMD_STATUS_READ			0x03
#define CMD_PROGRAM_PAGE		0x04
#define CMD_PROGRAM_SPARE_AREA		0x05
#define CMD_COPY_BACK			0x06
#define CMD_DEVICE_ID_READ		0x07
#define CMD_BLOCK_ERASE			0x08
#define CMD_FLASH_RESET			0x09
#define CMD_BLOCKS_LOCK			0x0a
#define CMD_BLOCKS_LOCK_DOWN		0x0b
#define CMD_BLOCKS_UNLOCK		0x0c
#define CMD_READ_BLOCKS_LOCK_STATUS	0x0d
#define CMD_PARAMETER_READ		0x0e
#define CMD_PARAMETER_CHANGE_COL	0x0f
#define CMD_LOW_LEVEL_OP		0x10
#define FLASH_DMA_ECC_ERROR	(1 << 8)
#define FLASH_DMA_CORR_ERROR	(1 << 9)
#define FC_SHIFT		9U
#define FC_BYTES		512U
#define FC_WORDS		(FC_BYTES >> 2)
#define BRCMNAND_MIN_PAGESIZE	512
#define BRCMNAND_MIN_BLOCKSIZE	(8 * 1024)
#define BRCMNAND_MIN_DEVSIZE	(4ULL * 1024 * 1024)
#define NAND_CTRL_RDY			(INTFC_CTLR_READY | INTFC_FLASH_READY)
#define NAND_POLL_STATUS_TIMEOUT_MS	100
#ifndef __UBOOT__
#else
#endif /* __UBOOT__ */
#ifndef __UBOOT__
#else
#endif /* __UBOOT__ */
#ifndef __UBOOT__
#else
#endif /* __UBOOT__ */
#define NAND_ACC_CONTROL_ECC_SHIFT	16
#define NAND_ACC_CONTROL_ECC_EXT_SHIFT	13
#ifndef __UBOOT__
#else
#endif /* __UBOOT__ */
#ifndef __UBOOT__
#else
#endif /* __UBOOT__ */
#ifndef __UBOOT__
#else
#endif
#ifndef __UBOOT__
#else
#endif /* __UBOOT__ */
#ifndef __UBOOT__
#endif /* __UBOOT__ */
#ifndef __UBOOT__
#else
#endif /* __UBOOT__ */
#ifndef __UBOOT__
#ifdef CONFIG_CPU_BIG_ENDIAN
#endif
#endif /* __UBOOT__ */
#ifndef __UBOOT__
#else
#endif
#ifndef __UBOOT__
#else
#endif /* __UBOOT__ */
#ifndef __UBOOT__
#endif /* __UBOOT__ */
#ifndef __UBOOT__
#else
#endif /* __UBOOT__ */
#ifndef __UBOOT__
#else
#endif
#ifndef __UBOOT__
#else
#endif /* __UBOOT__ */
#ifndef __UBOOT__
#else
#endif
#ifndef __UBOOT__
#else
#endif /* __UBOOT__ */
#ifndef __UBOOT__
#else
#endif /* __UBOOT__ */
#ifndef __UBOOT__
#else
#endif /* __UBOOT__ */
#ifndef __UBOOT__
#endif  /* __UBOOT__ */
#ifndef __UBOOT__
#else
#endif /* __UBOOT__ */
#ifndef __UBOOT__
#else
#endif /* __UBOOT__ */
#ifndef __UBOOT__
#else
#endif /* __UBOOT__ */
#ifndef __UBOOT__
#endif /* __UBOOT__ */
#ifndef __UBOOT__
#else
#endif /* __UBOOT__ */
#ifndef __UBOOT__
#else
#endif
#ifndef __UBOOT__
#else
#endif
#ifndef __UBOOT__
#endif /* __UBOOT__ */
#ifndef __UBOOT__
#endif /* __UBOOT__ */
#ifndef __UBOOT__
#else
#endif /* __UBOOT__ */
#ifndef __UBOOT__
#else
#endif /* __UBOOT__ */
#ifndef __UBOOT__
int brcmnand_remove(struct platform_device *pdev)
{
	struct brcmnand_controller *ctrl = dev_get_drvdata(&pdev->dev);
	struct brcmnand_host *host;

	list_for_each_entry(host, &ctrl->host_list, node)
		nand_release(nand_to_mtd(&host->chip));

	clk_disable_unprepare(ctrl->clk);

	dev_set_drvdata(&pdev->dev, NULL);

	return 0;
}
#else
int brcmnand_remove(struct udevice *pdev)
{
	return 0;
}
#endif /* __UBOOT__ */
