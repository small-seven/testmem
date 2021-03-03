#if !(defined(_CUT_PAKE_) || defined(_CUT_PAKE_SERVER_) || defined(_CUT_EXCHANGE_) || defined(_CUT_EXCHANGE_SERVER_))
#include <securec.h>
#include "log.h"
#include "mem_stat.h"
#include "jsonutil.h"
#include "commonutil.h"
#include "parsedata.h"
#include "exchange_auth_info.h"
#include "key_agreement_version.h"
void free_exchange_data(void *obj)
{
    if (obj != NULL) {
        FREE(obj);
    }
}
#else /* _CUT_XXX_ */
#include "parsedata.h"
#endif /* _CUT_XXX_ */
