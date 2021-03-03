#include <common.h>
#include <dm.h>
#include <errno.h>
#include <malloc.h>
#include <dm/test.h>
#include <test/ut.h>
#include <asm/io.h>
static int test_remove(struct udevice *dev)
{
	/* Private data should still be allocated */
	ut_assert(dev_get_priv(dev));

	dm_testdrv_op_count[DM_TEST_OP_REMOVE]++;
	return 0;
}
static int test_manual_remove(struct udevice *dev)
{
	dm_testdrv_op_count[DM_TEST_OP_REMOVE]++;
	return 0;
}
