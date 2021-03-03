#include <common.h>
#include <malloc.h>
#include <dm.h>
#include <errno.h>
#include <asm/io.h>
#include <dm/test.h>
#include <linux/list.h>
#include <test/ut.h>
static int test_pre_remove(struct udevice *dev)
{
	dm_testdrv_op_count[DM_TEST_OP_PRE_REMOVE]++;

	return 0;
}
static int test_destroy(struct uclass *uc)
{
	dm_testdrv_op_count[DM_TEST_OP_DESTROY]++;

	return 0;
}
