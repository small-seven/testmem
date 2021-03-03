#include <fs/fs.h>
#include <user_copy.h>
#include <fs_poll_pri.h>
#include <osal_mem.h>
#include <osal_sem.h>
#include "hdf_sbuf.h"
#include "hdf_log.h"
#include "hdf_syscall_adapter.h"
#include "hdf_device_node_ext.h"
#include "hdf_vnode_adapter.h"
#define HDF_LOG_TAG hdf_vnode_adapter
#define VOID_DATA_SIZE 4
#define EVENT_QUEUE_MAX 100
#define MAX_RW_SIZE (1024*1204) // 1M
static void DevEventFree(struct HdfDevEvent *event)
{
    if (event == NULL) {
        return;
    }
    if (event->data != NULL) {
        HdfSBufRecycle(event->data);
        event->data = NULL;
    }
    OsalMemFree(event);
}
