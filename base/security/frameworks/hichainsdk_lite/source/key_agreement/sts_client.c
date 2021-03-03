#include "sts_client.h"
#if !(defined(_CUT_STS_) || defined(_CUT_STS_CLIENT_))
#include <string.h>
#include <securec.h>
#include "huks_adapter.h"
#include "log.h"
#include "commonutil.h"
#include "distribution.h"
void destroy_sts_client(struct sts_client *handle)
{
    if (handle == NULL) {
        DBG_OUT("Destroy sts client object failed");
        return;
    }

    FREE(handle);
    DBG_OUT("FREE sts client object success");
}
#if (defined(_SUPPORT_SEC_CLONE_) || defined(_SUPPORT_SEC_CLONE_SERVER_))
#else
#endif
#else /* _CUT_XXX_ */
void destroy_sts_client(struct sts_client *handle)
{
    (void)handle;
    return;
}
#endif /* _CUT_XXX_ */
