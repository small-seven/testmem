#include "time.h"
#include "asm/hal_platform_ints.h"
#include "stdint.h"
#include "stdio.h"
#include "sys/times.h"
#include "time_posix.h"
#include "unistd.h"
#ifdef LOSCFG_SECURITY_CAPABILITY
#include "capability_api.h"
#endif
#include "los_signal.h"
#ifdef LOSCFG_KERNEL_VDSO
#include "los_vdso.h"
#endif
#ifdef LOSCFG_SECURITY_VID
#include "vid_api.h"
#endif
#include "user_copy.h"
#include "los_process_pri.h"
#include "los_swtmr_pri.h"
#include "los_sys_pri.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#define TIME_RETURN(err) do { \
#ifdef LOSCFG_AARCH64
#define timeval64 timeval
#define timespec64 timespec
#endif
#ifdef LOSCFG_SECURITY_CAPABILITY
#endif
#ifndef LOSCFG_AARCH64
#endif
#ifndef LOSCFG_AARCH64
#endif
#ifdef LOSCFG_AARCH64
#else
#endif
#ifdef LOSCFG_SECURITY_CAPABILITY
#endif
typedef struct {
    int sigev_signo;
    UINT32 pid;
    union sigval sigev_value;
} swtmr_proc_arg;
int timer_create(clockid_t clockID, struct sigevent *evp, timer_t *timerID)
{
    UINT32 ret;
    UINT16 swtmrID;
    swtmr_proc_arg *arg = NULL;
    int signo;
#ifdef LOSCFG_SECURITY_VID
    UINT16 vid;
#endif

    if ((clockID != CLOCK_REALTIME) || (timerID == NULL)) {
        errno = EINVAL;
        return -1;
    }

    signo = evp ? evp->sigev_signo : SIGALRM;
    if (signo > SIGRTMAX || signo < 1) {
        errno = EINVAL;
        return -1;
    }
    if (evp && (evp->sigev_notify != SIGEV_SIGNAL && evp->sigev_notify != SIGEV_THREAD_ID)) {
        errno = ENOTSUP;
        return -1;
    }

    arg = (swtmr_proc_arg *)malloc(sizeof(swtmr_proc_arg));
    if (arg == NULL) {
        errno = ENOMEM;
        return -1;
    }
    arg->sigev_signo = signo - 1;
    arg->pid = LOS_GetCurrProcessID();
    arg->sigev_value.sival_ptr = evp ? evp->sigev_value.sival_ptr : NULL;
    ret = LOS_SwtmrCreate(1, LOS_SWTMR_MODE_ONCE, SwtmrProc, &swtmrID, (UINTPTR)arg);
    if (ret != LOS_OK) {
        errno = (ret == LOS_ERRNO_SWTMR_MAXSIZE) ? EAGAIN : EINVAL;
        free(arg);
        return -1;
    }

#ifdef LOSCFG_SECURITY_VID
    vid = AddNodeByRid(swtmrID);
    if (vid == MAX_INVALID_TIMER_VID) {
        free(arg);
        (VOID)LOS_SwtmrDelete(swtmrID);
        return -1;
    }
    swtmrID = vid;
#endif
    *timerID = (timer_t)(UINTPTR)swtmrID;
    return 0;
}
#ifdef LOSCFG_SECURITY_VID
#endif
#ifdef LOSCFG_SECURITY_VID
#endif
#ifdef LOSCFG_SECURITY_VID
#endif
#ifdef LOSCFG_SECURITY_VID
#endif
#ifdef LOSCFG_SECURITY_VID
#endif
#ifdef LOSCFG_KERNEL_VDSO
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
