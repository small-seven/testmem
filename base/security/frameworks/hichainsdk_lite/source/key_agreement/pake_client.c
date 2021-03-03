#include "pake_client.h"
#include "log.h"
#include "mem_stat.h"
#if !(defined(_CUT_PAKE_) || defined(_CUT_PAKE_CLIENT_))
#include <string.h>
#include <securec.h>
#include "huks_adapter.h"
#include "commonutil.h"
#define HICHAIN_SPEKE_BASE_INFO       "hichain_speke_base_info"
#define HICHAIN_RETURN_KEY            "hichain_return_key"
#define HICHAIN_SPEKE_SESSIONKEY_INFO "hichain_speke_sessionkey_info"
void destroy_pake_client(struct pake_client *pake_client)
{
    if (pake_client == NULL) {
        return;
    }

    LOGI("Destroy pake client object %u success", pake_client_sn(pake_client));
    FREE(pake_client);
}
#else /* _CUT_XXX */
void destroy_pake_client(struct pake_client *pake_client)
{
    LOGE("Donot support pake protocol");
    FREE(pake_client);
}
#endif /* _CUT_XXX */
