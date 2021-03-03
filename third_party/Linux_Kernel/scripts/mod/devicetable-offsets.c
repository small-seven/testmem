#include <linux/kbuild.h>
#include <linux/mod_devicetable.h>
#define DEVID(devid) DEFINE(SIZE_##devid, sizeof(struct devid))
#define DEVID_FIELD(devid, field) \
