 * Semaphores are represented by the type "sys_sem_t" which is typedef'd
 * in the sys_arch.h file. Mailboxes are equivalently represented by the
 * type "sys_mbox_t". Mutexes are represented by the type "sys_mutex_t".
 * lwIP does not place any restrictions on how these types are represented
 * internally.
 *
 * @defgroup sys_mutex Mutexes
 * @ingroup sys_os
 * Mutexes are recommended to correctly handle priority inversion,
 * especially if you use LWIP_CORE_LOCKING .
 *
 * @defgroup sys_mbox Mailboxes
 * @ingroup sys_os
 * Mailboxes should be implemented as a queue which allows multiple messages
 * to be posted (implementing as a rendez-vous point where only one message can be
 * posted at a time can have a highly negative impact on performance). A message
 * in a mailbox is just a pointer, nothing more. 
 *
 * @defgroup sys_time Time
 * @ingroup sys_layer
 *
 * @defgroup sys_prot Critical sections
 * @ingroup sys_layer
 * Used to protect short regions of code against concurrent access.
 * - Your system is a bare-metal system (probably with an RTOS)
 *   and interrupts are under your control:
 *   Implement this as LockInterrupts() / UnlockInterrupts()
 * - Your system uses an RTOS with deferred interrupt handling from a
 *   worker thread: Implement as a global mutex or lock/unlock scheduler
 * - Your system uses a high-level OS with e.g. POSIX signals:
 *   Implement as a global mutex
 *
 * @defgroup sys_misc Misc
 * @ingroup sys_os
 */

#include "lwip/opt.h"

#include "lwip/sys.h"

/* Most of the functions defined in sys.h must be implemented in the
 * architecture-dependent file sys_arch.c */

#if !NO_SYS

#ifndef sys_msleep
/**
 * Sleep for some ms. Timeouts are NOT processed while sleeping.
 *
 * @param ms number of milliseconds to sleep
 */
void
sys_msleep(u32_t ms)
{
  if (ms > 0) {
    sys_sem_t delaysem;
    err_t err = sys_sem_new(&delaysem, 0);
    if (err == ERR_OK) {
      sys_arch_sem_wait(&delaysem, ms);
      sys_sem_free(&delaysem);
    }
#endif /* sys_msleep */
#endif /* !NO_SYS */
