#include "hievent_driver.h"
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <errno.h>
#include <assert.h>
#include <fs/fs.h>
#include <sys/types.h>
#include <linux/list.h>
#include <linux/wait.h>
#include "poll.h"
#include "hievent_driver.h"
#include "los_memory.h"
#include "los_task_pri.h"
#include "los_process_pri.h"
#include "los_task_pri.h"
#include "los_mux.h"
#include "los_mp.h"
#include "los_vm_map.h"
#include "user_copy.h"
#include "los_vm_lock.h"
#define HIEVENT_LOG_BUFFER 1024
#define DRIVER_MODE 0666
