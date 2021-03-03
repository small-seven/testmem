#include "los_typedef.h"
#include "los_typedef.h"
#include "los_vm_syscall.h"
#include "los_vm_common.h"
#include "los_rbtree.h"
#include "los_vm_map.h"
#include "los_vm_dump.h"
#include "los_vm_lock.h"
#include "los_vm_filemap.h"
#include "los_process_pri.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

STATUS_T OsCheckMMapParams(VADDR_T vaddr, unsigned prot, unsigned long flags, size_t len, unsigned long pgoff)
{
    if ((vaddr != 0) && !LOS_IsUserAddressRange(vaddr, len)) {
        return -EINVAL;
    }
#ifdef LOSCFG_VM_OVERLAP_CHECK
#endif
#ifdef LOSCFG_VM_OVERLAP_CHECK
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
