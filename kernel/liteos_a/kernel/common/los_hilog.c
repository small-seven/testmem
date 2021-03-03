#include "los_hilog.h"
#include "los_mp.h"
#include "los_mux.h"
#include "los_process_pri.h"
#include "los_task_pri.h"
#include "fs/fs.h"
#include "los_vm_map.h"
#include "los_vm_lock.h"
#include "user_copy.h"
#define HILOG_BUFFER 1024
#define DRIVER_MODE 0666
#define HILOG_DRIVER "/dev/hilog"
#ifndef CONFIG_DISABLE_POLL
#endif
