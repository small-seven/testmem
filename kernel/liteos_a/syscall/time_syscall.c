#include "errno.h"
#include "unistd.h"
#include "limits.h"
#include "utime.h"
#include "time.h"
#include "user_copy.h"
#include "sys/times.h"
#include "los_memory.h"
#include "los_strncpy_from_user.h"
#ifdef LOSCFG_FS_VFS
#endif
int SysTimerCreate(clockid_t clockID, struct sigevent *evp, timer_t *timerID)
{
    int ret;
    timer_t stimerID;
    struct sigevent sevp;

    if (timerID == NULL) {
        errno = EINVAL;
        return -EINVAL;
    }

    if (evp && LOS_ArchCopyFromUser(&sevp, evp, sizeof(struct sigevent))) {
        errno = EFAULT;
        return -EFAULT;
    }

    ret = timer_create(clockID, evp ? &sevp : NULL, &stimerID);
    if (ret < 0) {
        return -get_errno();
    }

    if (LOS_ArchCopyToUser(timerID, &stimerID, sizeof(timer_t))) {
        errno = EFAULT;
        return -EFAULT;
    }

    return ret;
}
