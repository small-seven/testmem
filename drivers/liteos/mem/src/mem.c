#include <los_sys.h>
#include <fcntl.h>
#include "linux/kernel.h"
#include "los_vm_map.h"
#include "los_arch_mmu.h"
static int mem_open(struct file *filep)
{
    return 0;
}
static int mem_close(struct file *filep)
{
    return 0;
}
static ssize_t mem_read(FAR struct file *filep, FAR char *buffer, size_t buflen)
{
    return 0;
}
static ssize_t mem_write(FAR struct file *filep, FAR const char *buffer, size_t buflen)
{
    return 0;
}
static ssize_t mem_map(FAR struct file* filep, FAR LosVmMapRegion *region)
{
    size_t size = region->range.size;
    PADDR_T paddr = region->pgOff << PAGE_SHIFT;
    VADDR_T vaddr = region->range.base;
    LosVmSpace *space = LOS_SpaceGet(vaddr);

    if ((paddr >= SYS_MEM_BASE) && (paddr < SYS_MEM_END)) {
        return -EINVAL;
    }

    /* Peripheral register memory adds strongly ordered attributes */
    region->regionFlags |= VM_MAP_REGION_FLAG_UNCACHED;

    if (space == NULL) {
        return -EAGAIN;
    }
    if (LOS_ArchMmuMap(&space->archMmu, vaddr, paddr, size >> PAGE_SHIFT, region->regionFlags) <= 0) {
        return -EAGAIN;
    }

    return 0;
}
#ifndef CONFIG_DISABLE_POLL
#endif
