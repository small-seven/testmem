#if !(defined(_CUT_PAKE_) || defined(_CUT_PAKE_SERVER_) || defined(_CUT_EXCHANGE_) || defined(_CUT_EXCHANGE_SERVER_))
#include <securec.h>
#include "log.h"
#include "mem_stat.h"
#include "jsonutil.h"
#include "commonutil.h"
#include "parsedata.h"
#include "exchange_auth_info.h"
#include "key_agreement_version.h"
void free_exchange_request(void *obj)
{
    if (obj != NULL) {
        exchange_request_data *data = obj;
        if (data->cipher.val != NULL) {
            FREE(data->cipher.val);
        }
        FREE(data);
    }
}
#else /* _CUT_XXX_ */
#include "parsedata.h"
#endif /* _CUT_XXX_ */
