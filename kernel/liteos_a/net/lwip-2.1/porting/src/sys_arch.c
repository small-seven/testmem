#include <arch/sys_arch.h>
#include <lwip/sys.h>
#include <lwip/debug.h>
#include <los_task.h>
#include <los_sys_pri.h>
#include <los_tick.h>
#include <los_queue.h>
#include <los_sem.h>
#include <los_mux.h>
#include <los_spinlock.h>
#if (LOSCFG_KERNEL_SMP == YES)
#endif /* LOSCFG_KERNEL_SMP == YES */
#if (LOSCFG_KERNEL_SMP == YES)
#else
#endif /* LOSCFG_KERNEL_SMP == YES */
#if (LOSCFG_KERNEL_SMP == YES)
#else
#endif /* LOSCFG_KERNEL_SMP == YES */
void sys_mbox_free(sys_mbox_t *mbox)
{
    (void)LOS_QueueDelete(*mbox);
}
void sys_sem_free(sys_sem_t *sem)
{
    (void)LOS_SemDelete(*sem);
}
void sys_mutex_free(sys_mutex_t *mutex)
{
    (void)LOS_MuxDestroy(mutex);
}
