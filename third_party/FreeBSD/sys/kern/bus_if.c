#include <sys/param.h>
#include <sys/queue.h>
#include <sys/kernel.h>
#include <sys/kobj.h>
#include <sys/systm.h>
#include <sys/bus.h>
#include "bus_if.h"
null_alloc_resource(device_t dev, device_t child,
    int type, int *rid, rman_res_t start, rman_res_t end,
    rman_res_t count, u_int flags)
{
    return (0);
}
