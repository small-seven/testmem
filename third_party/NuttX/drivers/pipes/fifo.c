#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <errno.h>
#include <fs/fs.h>
#include "pipe_common.h"
#if CONFIG_DEV_FIFO_SIZE > 0
#ifndef CONFIG_DISABLE_PSEUDOFS_OPERATIONS
#endif
#endif /* CONFIG_DEV_FIFO_SIZE > 0 */
