#include <sys/cdefs.h>
#include <sys/kobj.h>
#include <sys/systm.h>
#include <sys/bus.h>
#include "device_if.h"
#include "bus_if.h"
#include <sys/malloc.h>
#include <sys/module.h>
#ifdef LOSCFG_DRIVERS_HDF_USB
#include "hdf_usb.h"
#endif
#ifdef LOSCFG_DRIVERS_HDF_USB
#endif
nexus_alloc_resource(device_t bus, device_t child, int type, int *rid,
    rman_res_t start, rman_res_t end, rman_res_t count, u_int flags)
{
	devclass_t dc = device_get_devclass(child);
	struct resource_list *res_list = NULL;
	if (dc == NULL || rid == NULL) {
		return (NULL);
	}
	res_list = get_resource_list(devclass_get_name(dc));
	if (res_list == NULL) {
		return (NULL);
	}
	struct resource_list_entry *rle = resource_list_find(res_list, type, *rid);
	if (rle == NULL) {
		return(NULL);
	}
	return (rle->res);
}
