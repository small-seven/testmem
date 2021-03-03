#include <common.h>
#include <errno.h>
#include <dm.h>
#include <fdtdec.h>
#include <malloc.h>
#include <dm/device-internal.h>
#include <dm/root.h>
#include <dm/util.h>
#include <dm/test.h>
#include <dm/uclass-internal.h>
#include <test/ut.h>
static int dm_test_remove(struct unit_test_state *uts)
{
	struct udevice *dev;
	int i;

	for (i = 0; i < 3; i++) {
		ut_assertok(uclass_find_device(UCLASS_TEST, i, &dev));
		ut_assert(dev);
		ut_assertf(dev->flags & DM_FLAG_ACTIVATED,
			   "Driver %d/%s not activated", i, dev->name);
		ut_assertok(device_remove(dev, DM_REMOVE_NORMAL));
		ut_assertf(!(dev->flags & DM_FLAG_ACTIVATED),
			   "Driver %d/%s should have deactivated", i,
			   dev->name);
		ut_assert(!dev->priv);
	}

	return 0;
}
#define NODE_COUNT	10
