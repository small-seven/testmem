#include "user_copy.h"
#include "arm_user_copy.h"
#include "securec.h"
#include "los_memory.h"
#include "los_vm_map.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
INT32 LOS_UserMemClear(unsigned char *buf, UINT32 len)
{
    INT32 ret = 0;
    if (!LOS_IsUserAddressRange((vaddr_t)(UINTPTR)buf, len)) {
        (VOID)memset_s(buf, len, 0, len);
    } else {
        unsigned char *tmp = (unsigned char *)LOS_MemAlloc(OS_SYS_MEM_ADDR, len);
        if (tmp == NULL) {
            return -ENOMEM;
        }
        (VOID)memset_s(tmp, len, 0, len);
        if (_arm_user_copy(buf, tmp, len) != 0) {
            ret = -EFAULT;
        }
        LOS_MemFree(OS_SYS_MEM_ADDR, tmp);
    }
    return ret;
}
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
