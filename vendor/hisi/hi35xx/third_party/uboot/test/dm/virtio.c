#include <common.h>
#include <dm.h>
#include <virtio_types.h>
#include <virtio.h>
#include <virtio_ring.h>
#include <dm/device-internal.h>
#include <dm/uclass-internal.h>
#include <dm/root.h>
#include <dm/test.h>
#include <test/ut.h>
static int dm_test_virtio_remove(struct unit_test_state *uts)
{
	struct udevice *bus, *dev;

	/* check probe success */
	ut_assertok(uclass_first_device(UCLASS_VIRTIO, &bus));

	/* check the child virtio-blk device is bound */
	ut_assertok(device_find_first_child(bus, &dev));

	/* set driver status to VIRTIO_CONFIG_S_DRIVER_OK */
	ut_assertok(virtio_set_status(dev, VIRTIO_CONFIG_S_DRIVER_OK));

	/* check the device can be successfully removed */
	dev->flags |= DM_FLAG_ACTIVATED;
	ut_assertok(device_remove(bus, DM_REMOVE_ACTIVE_ALL));

	return 0;
}
