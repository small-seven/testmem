#include "los_signal.h"
#include "pthread.h"
#include "los_process_pri.h"
#include "los_hw_pri.h"
#include "user_copy.h"
#ifdef LOSCFG_SECURITY_CAPABILITY
#include "capability_api.h"
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#define GETUNMASKSET(procmask, pendFlag) ((~(procmask)) & (sigset_t)(pendFlag))
#define UINT64_BIT_SIZE 64
#ifdef LOSCFG_SECURITY_CAPABILITY
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
