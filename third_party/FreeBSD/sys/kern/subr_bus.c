#include <sys/cdefs.h>
#include <sys/param.h>
#include <sys/kobj.h>
#include <sys/malloc.h>
#include <sys/queue.h>
#include <sys/systm.h>
#include <sys/bus.h>
#include <sys/mutex.h>
#include "los_hwi.h"
#ifndef BOOTVERBOSE
#define BOOTVERBOSE     0
#endif
typedef struct driverlink *driverlink_t;
struct driverlink {
	kobj_class_t    driver;
	TAILQ_ENTRY(driverlink) link;   /* list of drivers in devclass */
	int             pass;
	TAILQ_ENTRY(driverlink) passlink;
};
typedef TAILQ_HEAD(devclass_list, devclass) devclass_list_t;
typedef TAILQ_HEAD(driver_list, driverlink) driver_list_t;
typedef TAILQ_HEAD(device_list, device) device_list_t;

struct devclass {
        TAILQ_ENTRY(devclass) link;
        devclass_t      parent;         /* parent in devclass hierarchy */
        driver_list_t   drivers;     /* bus devclasses store drivers for bus */
        char            *name;
        device_t        *devices;       /* array of devices indexed by unit */
        int             maxunit;        /* size of devices array */
        int             flags;
#define DC_HAS_CHILDREN         1
};
#ifdef BUS_DEBUG
#define PDEBUG(a)       if (bus_debug) {PRINTK("%s:%d: ", __func__, __LINE__), PRINTK a; PRINTK("\n");}
#define DEVICENAME(d)   ((d)? device_get_name(d): "no device")
#define DRIVERNAME(d)   ((d)? d->name : "no driver")
#define DEVCLANAME(d)   ((d)? d->name : "no devclass")
#define indentprintf(p) do { int iJ; PRINTK("."); for (iJ=0; iJ<indent; iJ++) PRINTK("  "); PRINTK p ; } while (0)
#else
#define PDEBUG(a)                       /* nop */
#define DEVICENAME(d)                   /* nop */
#define DRIVERNAME(d)                   /* nop */
#define DEVCLANAME(d)                   /* nop */
#define print_device_short(d,i)         /* nop */
#define print_device(d,i)               /* nop */
#define print_device_tree_short(d,i)    /* nop */
#define print_device_tree(d,i)          /* nop */
#define print_driver_short(d,i)         /* nop */
#define print_driver(d,i)               /* nop */
#define print_driver_list(d,i)          /* nop */
#define print_devclass_short(d,i)       /* nop */
#define print_devclass(d,i)             /* nop */
#define print_devclass_list_short()     /* nop */
#define print_devclass_list()           /* nop */
#endif
devclass_create(const char *classname)
{
        return (devclass_find_internal(classname, NULL, TRUE));
}
devclass_find_free_unit(devclass_t dc, int unit)
{
        if (dc == NULL)
                return (unit);
        while (unit < dc->maxunit && dc->devices[unit] != NULL)
                unit++;
        return (unit);
}
devclass_alloc_unit(devclass_t dc, device_t dev, int *unitp)
{
    int unit = *unitp;

    PDEBUG(("unit %d in devclass %s", unit, DEVCLANAME(dc)));

    /* Ask the parent bus if it wants to wire this device. */
    if (unit == -1)
        BUS_HINT_DEVICE_UNIT(device_get_parent(dev), dev, dc->name, &unit);

    /* If we were given a wired unit number, check for existing device */
    /* XXX imp XXX */
    if (unit != -1) {
        if (unit >= 0 && unit < dc->maxunit && dc->devices[unit] != NULL) {
            if (bootverbose)
                printf("%s: %s%d already exists; skipping it\n", dc->name, dc->name, *unitp);
            return (EEXIST);
        }
    } else {
        /* Unwired device, find the next available slot for it */
        unit = 0;
        for (unit = 0;; unit++) {
            /* If this device slot is already in use, skip it. */
            if (unit < dc->maxunit && dc->devices[unit] != NULL)
                continue;

            break;
        }
    }
    PDEBUG(("mid: unit %d in devclass %s", unit, DEVCLANAME(dc)));
    /*
     * We've selected a unit beyond the length of the table, so let's
     * extend the table to make room for all units up to and including
     * this one.
     */
    if (unit >= dc->maxunit) {
        device_t *newlist, *oldlist;
        int newsize;

        oldlist = dc->devices;
        newsize = roundup((unit + 1), MINALLOCSIZE / sizeof(device_t));
        newlist = bsd_malloc(sizeof(device_t) * newsize, M_BUS, M_NOWAIT);
		PDEBUG(("oldlist %p, newlist %p, newsize %d", oldlist, newlist, newsize));
        if (!newlist)
            return (ENOMEM);
		PDEBUG(("start memcpy, size %d", sizeof(device_t) * dc->maxunit));
        if (oldlist != NULL)
            (void)memcpy_s(oldlist, sizeof(device_t) * dc->maxunit, newlist, sizeof(device_t) * dc->maxunit);
        PDEBUG(("start memset, maxunit %d, size %d", dc->maxunit, sizeof(device_t) * (newsize - dc->maxunit)));
        (void)memset_s(newlist + dc->maxunit, sizeof(device_t) * (newsize - dc->maxunit), 0,
                       sizeof(device_t) * (newsize - dc->maxunit));
        dc->devices = newlist;
        dc->maxunit = newsize;
        if (oldlist != NULL)
            bsd_free(oldlist, M_BUS);
    }
    PDEBUG(("now: unit %d in devclass %s", unit, DEVCLANAME(dc)));

    *unitp = unit;
    return (0);
}
device_free_softc(void *softc)
{
        bsd_free(softc, M_BUS_SC);
}
#define RANDOM_PROBE_BIT_GUESS  4
bus_generic_detach(device_t dev)
{
        device_t child;
        int error;

        if (dev->state != DS_ATTACHED)
                return (EBUSY);

        /*
         * Detach children in the reverse order.
         * See bus_generic_suspend for details.
         */
        TAILQ_FOREACH_REVERSE(child, &dev->children, device_list, link) {
                if ((error = device_detach(child)) != 0)
                        return (error);
        }

        return (0);
}
#if 0
#endif
resource_list_free(struct resource_list *rl)
{
	struct resource_list_entry *rle;

	while ((rle = STAILQ_FIRST(rl)) != NULL) {
		if (rle->res)
			bsd_free(rle->res, M_BUS);
		STAILQ_REMOVE_HEAD(rl, link);
		bsd_free(rle, M_BUS);
	}
}
#ifdef BUS_DEBUG
#endif
