#include <cpu_func.h>
#include "cipher_adapt.h"
#include "spacc_union_define.h"
#include "spacc_body.h"
#include "spacc_reg.h"
#define spacc_point_return_if_null(p) \
#define spacc_value_return_if_max(val, max) \
#if 0
#define SAPCC_SYMC_IN_ENTRY_TOTAL_SIZE \
#define SAPCC_SYMC_OUT_ENTRY_TOTAL_SIZE \
#define SAPCC_SYMC_ENTRY_TOTAL_SIZE \
#define SAPCC_DIGEST_IN_ENTRY_TOTAL_SIZE \
#else
#define SAPCC_SYMC_IN_ENTRY_TOTAL_SIZE      (SPACC_PAGE_SIZE)
#define SAPCC_SYMC_OUT_ENTRY_TOTAL_SIZE     (SPACC_PAGE_SIZE)
#define SAPCC_DIGEST_IN_ENTRY_TOTAL_SIZE    (SPACC_PAGE_SIZE)
#endif
#define spacc_err(fmt, ...)     \
#define spacc_dbg(fmt...)       // HI_PRINT(fmt)
#ifdef SMMU_ENABLE
#ifdef REE_NONSECURE_ENABLE
#else
#endif
#endif // SMMU_ENABLE
#ifdef INT_ENABLE
#endif
#ifndef DISABLE_DEBUG_INFO
#endif
