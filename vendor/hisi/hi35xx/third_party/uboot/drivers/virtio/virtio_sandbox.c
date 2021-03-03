#include <common.h>
#include <dm.h>
#include <virtio_types.h>
#include <virtio.h>
#include <virtio_ring.h>
#include <linux/compat.h>
#include <linux/io.h>
static int virtio_sandbox_child_post_remove(struct udevice *vdev)
{
	u8 status;

	virtio_get_status(vdev, &status);
	if (status)
		panic("virtio device was not reset\n");

	return 0;
}
