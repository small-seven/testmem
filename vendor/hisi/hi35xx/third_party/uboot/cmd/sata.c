#include <common.h>
#include <ahci.h>
#include <dm.h>
#include <command.h>
#include <part.h>
#include <sata.h>
#include <dm/device-internal.h>
#include <dm/uclass-internal.h>
int sata_remove(int devnum)
{
#ifdef CONFIG_AHCI
	struct udevice *dev;
	int rc;

	rc = uclass_find_device(UCLASS_AHCI, devnum, &dev);
	if (!rc && !dev)
		rc = uclass_find_first_device(UCLASS_AHCI, &dev);
	if (rc || !dev) {
		printf("Cannot find SATA device %d (err=%d)\n", devnum, rc);
		return CMD_RET_FAILURE;
	}

	rc = device_remove(dev, DM_REMOVE_NORMAL);
	if (rc) {
		printf("Cannot remove SATA device '%s' (err=%d)\n", dev->name,
		       rc);
		return CMD_RET_FAILURE;
	}

	return 0;
#else
	return sata_stop();
#endif
}
#ifdef CONFIG_AHCI
#else
#endif
