#include "los_cppsupport.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
typedef VOID (*InitFunc)(VOID);

INT32 LOS_CppSystemInit(UINTPTR initArrayStart, UINTPTR initArrayEnd)
{
    UINTPTR *start;
    InitFunc initFunc = NULL;

    for (start = (UINTPTR *)initArrayStart; start < (UINTPTR *)initArrayEnd; start++){
        initFunc = (InitFunc)(*start);
        initFunc();
    }
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
