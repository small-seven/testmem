#include <common.h>
#include <errno.h>
#include <dm.h>
#include <dm/of_access.h>
#include <dm/of_addr.h>
#include <asm/io.h>
#include <linux/ioport.h>
#include <linux/io.h>
#include <smem.h>
#define SMEM_MASTER_SBL_VERSION_INDEX	7
#define SMEM_GLOBAL_HEAP_VERSION	11
#define SMEM_GLOBAL_PART_VERSION	12
#define SMEM_ITEM_LAST_FIXED	8
#define SMEM_ITEM_COUNT		512
#define SMEM_HOST_APPS		0
#define SMEM_GLOBAL_HOST	0xfffe
#define SMEM_HOST_COUNT		10
#define AUX_BASE_MASK		0xfffffffc
#define SMEM_PRIVATE_CANARY	0xa5a5
static int qcom_smem_remove(struct udevice *dev)
{
	__smem = NULL;

	return 0;
}
