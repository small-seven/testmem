#include "string.h"
#include "securec.h"
#include "los_swtmr_pri.h"
#include "los_base_pri.h"
#include "los_sys.h"
#include "los_membox_pri.h"
#include "los_memory_pri.h"
#include "los_queue_pri.h"
#include "los_task_pri.h"
#include "los_hwi.h"
#if (LOSCFG_PLATFORM_EXC == YES)
#include "los_exc.h"
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#if (LOSCFG_BASE_CORE_SWTMR == YES)
#if (LOSCFG_BASE_CORE_SWTMR_ALIGN == YES)
typedef struct SwtmrAlignDataStr {
    UINT32 times : 24;
    UINT32 : 5;
    UINT32 canMultiple : 1;
    UINT32 canAlign : 1;
    UINT32 isAligned : 1;
} SwtmrAlignData;
#endif
#define SWTMR_MAX_RUNNING_TICKS     2
#if (LOSCFG_BASE_CORE_SWTMR_ALIGN == YES)
#endif
#if (LOSCFG_BASE_CORE_SWTMR_ALIGN == YES)
#endif
#if (LOSCFG_BASE_CORE_SWTMR_ALIGN == YES)
#endif
#if (LOSCFG_BASE_CORE_SWTMR_ALIGN == YES)
#endif
#if (LOSCFG_BASE_CORE_SWTMR_ALIGN == YES)
#endif
#if (LOSCFG_BASE_CORE_SWTMR_ALIGN == YES)
#else
#endif
#if (LOSCFG_BASE_CORE_SWTMR_ALIGN == YES)
#endif
#if (LOSCFG_BASE_CORE_SWTMR_ALIGN == YES)
#else
#endif
#if (LOSCFG_BASE_CORE_SWTMR_ALIGN == YES)
#else
#endif
#if (LOSCFG_BASE_CORE_SWTMR_ALIGN == YES)
#endif
#if (LOSCFG_BASE_CORE_SWTMR_ALIGN == YES)
#endif
#if (LOSCFG_BASE_CORE_SWTMR_ALIGN == YES)
#endif
#if (LOSCFG_BASE_CORE_SWTMR_ALIGN == YES)
#endif
#endif /* (LOSCFG_BASE_CORE_SWTMR == YES) */
#ifdef __cplusplus
#if __cplusplus
#endif
#endif
