#include <errno.h>
#include <mqueue.h>
#include <pwd.h>
#include "tst_test.h"
#include "tst_safe_file_ops.h"
#include "tst_safe_posix_ipc.h"
#define QUEUE_NAME	"/test_mqueue"
#define QUEUE_INIT	"/init_mqueue"
#define PROC_MAX_QUEUES "/proc/sys/fs/mqueue/queues_max"
