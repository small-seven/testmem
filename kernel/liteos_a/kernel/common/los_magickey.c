#include "los_magickey.h"
#include "los_task_pri.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#ifdef LOSCFG_ENABLE_MAGICKEY
#define MAGIC_KEY_NUM 5
STATIC VOID OsMagicMemCheck(VOID)
{
    if (LOS_MemIntegrityCheck(m_aucSysMem1) == LOS_OK) {
        PRINTK("system memcheck over, all passed!\n");
    }
    return;
}
#endif
#ifdef LOSCFG_ENABLE_MAGICKEY
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
