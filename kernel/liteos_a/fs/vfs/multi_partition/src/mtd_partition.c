#include "mtd_partition.h"
#include "stdlib.h"
#include "stdio.h"
#include "pthread.h"
#include "mtd_list.h"
#include "los_config.h"
#include "los_mux.h"
#include "inode/inode.h"
#if defined(LOSCFG_FS_JFFS)
#include "mtd_common.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#define DRIVER_NAME_ADD_SIZE    3
#define RWE_RW_RW 0755
static VOID MtdDeinitSpinorParam(VOID)
{
    if (JffsLockDeinit != NULL) {
        JffsLockDeinit();
    }
}
static INT32 MtdDeinitFsparParam(const CHAR *type)
{
    if (strcmp(type, "spinor") == 0) {
        MtdDeinitSpinorParam();
        g_spinorPartParam = NULL;
    } else {
        return -EINVAL;
    }

    return ENOERR;
}
static INT32 OsResourceRelease(mtd_partition *node, const CHAR *type, partition_param *param)
{
    (VOID)LOS_MuxDestroy(&node->lock);
    LOS_ListDelete(&node->node_info);
    (VOID)memset_s(node, sizeof(mtd_partition), 0, sizeof(mtd_partition));
    free(node);
    (VOID)FreeMtd(param->flash_mtd);
    if (LOS_ListEmpty(&param->partition_head->node_info)) {
        free(param->partition_head);
        param->partition_head = NULL;
        free(param);

        if (MtdDeinitFsparParam(type) != ENOERR) {
            return -EINVAL;
        }
    }
    return ENOERR;
}
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#endif
