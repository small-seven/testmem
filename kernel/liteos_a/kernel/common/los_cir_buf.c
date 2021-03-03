#include "los_cir_buf_pri.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
VOID LOS_CirBufDeinit(CirBuf *cirbufCB)
{
    (VOID)memset_s(cirbufCB, sizeof(CirBuf), 0, sizeof(CirBuf));
}
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */