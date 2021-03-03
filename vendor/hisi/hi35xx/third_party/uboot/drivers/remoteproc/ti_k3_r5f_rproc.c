#include <common.h>
#include <dm.h>
#include <remoteproc.h>
#include <errno.h>
#include <clk.h>
#include <reset.h>
#include <asm/io.h>
#include <linux/kernel.h>
#include <linux/soc/ti/ti_sci_protocol.h>
#include "ti_sci_proc.h"
#define K3_R5_TCM_DEV_ADDR	0x41010000
#define PROC_BOOT_CFG_FLAG_R5_DBG_EN			0x00000001
#define PROC_BOOT_CFG_FLAG_R5_DBG_NIDEN			0x00000002
#define PROC_BOOT_CFG_FLAG_R5_LOCKSTEP			0x00000100
#define PROC_BOOT_CFG_FLAG_R5_TEINIT			0x00000200
#define PROC_BOOT_CFG_FLAG_R5_NMFI_EN			0x00000400
#define PROC_BOOT_CFG_FLAG_R5_TCM_RSTBASE		0x00000800
#define PROC_BOOT_CFG_FLAG_R5_BTCM_EN			0x00001000
#define PROC_BOOT_CFG_FLAG_R5_ATCM_EN			0x00002000
#define PROC_BOOT_CFG_FLAG_GEN_IGN_BOOTVECTOR		0x10000000
#define PROC_BOOT_CTRL_FLAG_R5_CORE_HALT		0x00000001
#define PROC_BOOT_STATUS_FLAG_R5_WFE			0x00000001
#define PROC_BOOT_STATUS_FLAG_R5_WFI			0x00000002
#define PROC_BOOT_STATUS_FLAG_R5_CLK_GATED		0x00000004
#define PROC_BOOT_STATUS_FLAG_R5_LOCKSTEP_PERMITTED	0x00000100
#define NR_CORES	2
static int k3_r5f_remove(struct udevice *dev)
{
	struct k3_r5f_core *core = dev_get_priv(dev);

	free(core->mem);

	ti_sci_proc_release(&core->tsp);

	return 0;
}
