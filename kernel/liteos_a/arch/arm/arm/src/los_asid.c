#include "los_typedef.h"
#include "los_typedef.h"
#include "los_asid.h"
#include "los_spinlock.h"
#include "los_mmu_descriptor_v6.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

STATIC SPIN_LOCK_INIT(g_cpuAsidLock);
STATIC UINTPTR g_asidPool[BITMAP_NUM_WORDS(1UL << MMU_ARM_ASID_BITS)];

/* allocate and free asid */
status_t OsAllocAsid(UINT32 *asid)
{
    UINT32 flags;
    LOS_SpinLockSave(&g_cpuAsidLock, &flags);
    UINT32 firstZeroBit = LOS_BitmapFfz(g_asidPool, 1UL << MMU_ARM_ASID_BITS);
    if (firstZeroBit >= 0 && firstZeroBit < (1UL << MMU_ARM_ASID_BITS)) {
        LOS_BitmapSetNBits(g_asidPool, firstZeroBit, 1);
        *asid = firstZeroBit;
        LOS_SpinUnlockRestore(&g_cpuAsidLock, flags);
        return LOS_OK;
    }
VOID OsFreeAsid(UINT32 asid)
{
    UINT32 flags;
    LOS_SpinLockSave(&g_cpuAsidLock, &flags);
    LOS_BitmapClrNBits(g_asidPool, asid, 1);
    LOS_SpinUnlockRestore(&g_cpuAsidLock, flags);
}
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
