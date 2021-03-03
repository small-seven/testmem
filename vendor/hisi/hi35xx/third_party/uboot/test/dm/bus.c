#include <common.h>
#ifdef CONFIG_SANDBOX
#include <os.h>
#endif
#include <dm.h>
#include <dm/device.h>
#include <dm/device-internal.h>
#include <dm/test.h>
#include <dm/uclass-internal.h>
#include <dm/util.h>
#include <test/ut.h>
static int testbus_child_post_remove(struct udevice *dev)
{
	struct dm_test_parent_data *parent_data = dev_get_parent_priv(dev);
	struct dm_test_state *dms = test_state;

	parent_data->flag += FLAG_CHILD_REMOVED;
	if (dms)
		dms->removed = dev;

	return 0;
}
#ifdef CONFIG_SANDBOX
#endif
#ifdef CONFIG_SANDBOX
#endif
