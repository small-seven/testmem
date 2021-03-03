#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <errno.h>
#include <assert.h>
#include <fs/fs.h>
#include "pipe_common.h"
#include "stdio.h"
#if CONFIG_DEV_PIPE_SIZE > 0
#define MAX_PIPES 32
#ifndef CONFIG_DISABLE_PSEUDOFS_OPERATIONS
#endif
#ifndef CONFIG_DISABLE_PSEUDOFS_OPERATIONS
#endif
static inline int pipe_allocate(void)
{
  int pipeno;
  int ret = -ENFILE;

  for (pipeno = 0; pipeno < MAX_PIPES; pipeno++)
    {
      if ((g_pipeset & (1 << pipeno)) == 0)
        {
          g_pipeset |= (1 << pipeno);
          ret = pipeno;
          break;
        }
    }

  return ret;
}
static inline void pipe_free(int pipeno)
{
  int ret;

  ret = sem_wait(&g_pipesem);
  if (ret == OK)
    {
      g_pipeset &= ~(1 << pipeno);
      (void)sem_post(&g_pipesem);
    }
}
#ifndef CONFIG_DISABLE_PSEUDOFS_OPERATIONS
#endif
#endif /* CONFIG_DEV_PIPE_SIZE > 0 */
