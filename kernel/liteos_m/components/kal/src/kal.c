#include "securec.h"
#include "hi_mem.h"
#include "los_task.h"
#include "los_swtmr.h"
#include "los_swtmr_pri.h"
#include "los_hwi.h"
#include "kal.h"
#ifdef __cplusplus
#define NULL 0L
#else
#ifndef NULL
#define NULL ((void *)0)
#endif
#endif
#define MS_PER_SECOND 1000
#if (LOSCFG_BASE_CORE_SWTMR_ALIGN == YES)
#else
#endif
