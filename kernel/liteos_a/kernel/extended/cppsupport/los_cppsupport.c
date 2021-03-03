#include "los_cppsupport.h"
#include "los_printf.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
typedef VOID (*InitFunc)(VOID);

LITE_OS_SEC_TEXT_MINOR INT32 LOS_CppSystemInit(UINTPTR initArrayStart, UINTPTR initArrayEnd, INT32 flag)
{
    UINTPTR *start     = (UINTPTR *)initArrayStart;
    InitFunc initFunc   = NULL;

    for (; start != (UINTPTR *)initArrayEnd; ++start) {
        initFunc = (InitFunc)(*start);
        initFunc();
    }
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
