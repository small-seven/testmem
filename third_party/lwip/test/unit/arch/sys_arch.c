#include <lwip/opt.h>
#include <lwip/arch.h>
#if !NO_SYS
#include "sys_arch.h"
#endif
#include <lwip/stats.h>
#include <lwip/debug.h>
#include <lwip/sys.h>
#include <string.h>
#if !NO_SYS
sys_sem_free(sys_sem_t *sem)
{
  LWIP_ASSERT("sem != NULL", sem != NULL);
  *sem = 0;
}
sys_mutex_free(sys_mutex_t *mutex)
{
  /* parameter check */
  LWIP_ASSERT("mutex != NULL", mutex != NULL);
  LWIP_ASSERT("*mutex >= 1", *mutex >= 1);
  *mutex = 0;
}
sys_mbox_free(sys_mbox_t *mbox)
{
  /* parameter check */
  LWIP_ASSERT("mbox != NULL", mbox != NULL);
  LWIP_ASSERT("mbox->sem != NULL", mbox->sem != NULL);
  LWIP_ASSERT("mbox->sem == mbox", mbox->sem == mbox);
  LWIP_ASSERT("mbox->q_mem != NULL", mbox->q_mem != NULL);
  mbox->sem = NULL;
  free(mbox->q_mem);
  mbox->q_mem = NULL;
}
#if LWIP_NETCONN_SEM_PER_THREAD
#error LWIP_NETCONN_SEM_PER_THREAD==1 not supported
#endif /* LWIP_NETCONN_SEM_PER_THREAD */
#endif /* !NO_SYS */
