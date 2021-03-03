#include "appspawn_message.h"
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
#include "log.h"
#include "ohos_errno.h"
#include "securec.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cpluscplus */
#endif /* __cpluscplus */
void FreeMessageSt(MessageSt* targetSt)
{
    if (targetSt != NULL) {
        if (targetSt->bundleName != NULL) {
            free(targetSt->bundleName);
            targetSt->bundleName = NULL;
        }

        if (targetSt->sharedLibPaths != NULL) {
            free(targetSt->sharedLibPaths);
            targetSt->sharedLibPaths = NULL;
        }

        targetSt->identityID = 0;
        targetSt->uID = -1;
        targetSt->gID = -1;
    }
}
#ifdef __cplusplus
#if __cplusplus
#endif /* __cpluscplus */
#endif /* __cpluscplus */
