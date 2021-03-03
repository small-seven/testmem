#include "linux/wakelock.h"
#include "los_spinlock.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#define SET_BIT(bitmap, pos) ((bitmap) |= (1u << (pos)))
#define CLEAR_BIT(bitmap, pos) ((bitmap) &= ~(1u << (pos)))
#define CHECK_BIT(bitmap, pos) (((bitmap) & (1u << (pos))) ? 1 : 0)
#define WAKELOCK_BITMAP_CNT 32
typedef struct {
    UINT32 lock; /* Indicate which bit is locked */
    UINT32 used; /* Indicate used bit */
} WakeLockBitmap;
void linux_wake_lock_destroy(struct wake_lock *lock)
{
    UINT32 intSave;
    if (lock == NULL) {
        return;
    }
    LOS_SpinLockSave(&g_wakeLockSpin, &intSave);
    CLEAR_BIT(g_wlBitmap.used, lock->bitmap_pos);
    CLEAR_BIT(g_wlBitmap.lock, lock->bitmap_pos);
    LOS_SpinUnlockRestore(&g_wakeLockSpin, intSave);
}
#ifdef __cplusplus
#if __cplusplus
#endif
#endif
