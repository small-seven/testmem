#include <poll.h>
#include <limits.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <securec.h>
#include <osal_thread.h>
#include <osal_time.h>
#include "hdf_log.h"
#include "hdf_base.h"
#include "hdf_sbuf.h"
#include "osal_mem.h"
#include "hdf_syscall_adapter.h"
#define HDF_LOG_TAG hdf_syscall_adapter
#define EPOLL_MAX_EVENT_SIZE 4
#define TASK_EXIT_WAIT_TIME_MS 10
#define HDF_DEFAULT_BWR_READ_SIZE 1024
#define EVENT_READ_BUFF_GROWTH_RATE 2
#define EVENT_READ_BUFF_MAX (20 * 1024) // 20k
#define POLL_WAIT_TIME_MS 100
