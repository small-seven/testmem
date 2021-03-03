#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sched.h>
#include <semaphore.h>
#include <fcntl.h>
#include <errno.h>
#include <debug.h>
#include <poll.h>
#include "linux/wait.h"
#include "fs/fs.h"
#include "fs_poll_pri.h"
#include <assert.h>
#ifdef CONFIG_DEBUG_FEATURES
#  include <nuttx/arch.h>
#endif
#include <semaphore.h>
#include <fs/fs.h>
#include "pipe_common.h"
#include "los_printf.h"
#include "user_copy.h"
#ifdef LOSCFG_KERNEL_PIPE
#ifdef CONFIG_DEV_PIPEDUMP
#  define pipe_dumpbuffer(m,a,n) lib_dumpbuffer(m,a,n)
#else
#  define pipe_dumpbuffer(m,a,n)
#endif
FAR struct pipe_dev_s *pipecommon_allocdev(size_t bufsize, const char *name)
{
  FAR struct pipe_dev_s *dev;
  int ret;

  if (bufsize > CONFIG_DEV_PIPE_MAXSIZE)
    {
      return NULL;
    }

  /* Allocate a private structure to manage the pipe */

  dev = (FAR struct pipe_dev_s *)malloc(sizeof(struct pipe_dev_s));
  if (dev)
    {
      /* Initialize the private structure */

      (void)memset_s(dev, sizeof(struct pipe_dev_s), 0, sizeof(struct pipe_dev_s));
      ret = strcpy_s(dev->name, sizeof(dev->name), name);
      if (ret < 0)
        {
          free(dev);
          return NULL;
        }
      sem_init(&dev->d_bfsem, 0, 1);
      sem_init(&dev->d_rdsem, 0, 0);
      sem_init(&dev->d_wrsem, 0, 0);
      LOS_ListInit(&dev->wq.poll_queue);
     /* The read/write wait semaphores are used for signaling and, hence,
      * should not have priority inheritance enabled.
      */

      dev->d_bufsize = bufsize;
    }

  return dev;
}
void pipecommon_freedev(FAR struct pipe_dev_s *dev)
{
  sem_destroy(&dev->d_bfsem);
  sem_destroy(&dev->d_rdsem);
  sem_destroy(&dev->d_wrsem);
  free(dev);
}
#ifndef CONFIG_DISABLE_PSEUDOFS_OPERATIONS
#endif
#endif /* LOSCFG_KERNEL_PIPE */
