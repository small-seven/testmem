#include "sts_server.h"
#include "log.h"
#if !(defined(_CUT_STS_) || defined(_CUT_STS_SERVER_))
#include <securec.h>
#include "commonutil.h"
#include "distribution.h"
#include "mem_stat.h"
#include "huks_adapter.h"
#ifdef DESC
#undef DESC
#endif
#define DESC(...) 1
#define HC_STS_REQUEST_LEN  256
#define HC_STS_RESPONSE_LEN 256
void destroy_sts_server(struct sts_server *handle)
{
    if (handle == NULL) {
        DBG_OUT("Destroy sts server object failed");
        return;
    }

    FREE(handle);
    LOGI("FREE sts server object success");
}
#if (defined(_SUPPORT_SEC_CLONE_) || defined(_SUPPORT_SEC_CLONE_SERVER_))
#else
#endif
#else /* _CUT_XXX_ */
#include "mem_stat.h"
void destroy_sts_server(struct sts_server *handle)
{
    LOGE("Donot support sts protocol");
    FREE(handle);
}
#endif /* _CUT_XXX_ */
