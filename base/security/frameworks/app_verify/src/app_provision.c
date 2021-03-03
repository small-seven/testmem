#include "app_provision.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "app_common.h"
#include "cJSON.h"
#include "parameter.h"
#include "securec.h"
static void FreeStringAttay(char **array, int num)
{
    if (array == NULL) {
        return;
    }
    for (int i = 0; i < num; i++) {
        if (array[i] != NULL) {
            APPV_FREE(array[i]);
        }
    }
    APPV_FREE(array);
    return;
}
static void FreeProfBundle(ProfBundleInfo *pfval)
{
    FREE_IF_NOT_NULL(pfval->appFeature);
    FREE_IF_NOT_NULL(pfval->bundleName);
    FREE_IF_NOT_NULL(pfval->devCert);
    FREE_IF_NOT_NULL(pfval->developerId);
    FREE_IF_NOT_NULL(pfval->releaseCert);
    return;
}
static void FreeProfPerssion(ProfPermission *pfval)
{
    FreeStringAttay(pfval->permission, pfval->permissionNum);
    pfval->permissionNum = 0;
    pfval->permission = NULL;

    FreeStringAttay(pfval->restricPermission, pfval->restricNum);
    pfval->restricNum = 0;
    pfval->restricPermission = NULL;
    return;
}
static void FreeProfDebuginfo(ProfDebugInfo *pfval)
{
    FREE_IF_NOT_NULL(pfval->devIdType);

    FreeStringAttay(pfval->deviceId, pfval->devidNum);
    pfval->devidNum = 0;
    pfval->deviceId = NULL;

    return;
}
void ProfFreeData(ProfileProf *pf)
{
    if (pf == NULL) {
        return;
    }
    FREE_IF_NOT_NULL(pf->versionName);
    FREE_IF_NOT_NULL(pf->uuid);
    FREE_IF_NOT_NULL(pf->type);
    FREE_IF_NOT_NULL(pf->appDistType);
    FreeProfBundle(&pf->bundleInfo);
    FreeProfPerssion(&pf->permission);
    FreeProfDebuginfo(&pf->debugInfo);
    FREE_IF_NOT_NULL(pf->issuer);
    FREE_IF_NOT_NULL(pf->appid);
    return;
}
