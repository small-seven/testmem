#if !(defined(_CUT_STS_) || defined(_CUT_STS_SERVER_))
#include <securec.h>
#include "log.h"
#include "mem_stat.h"
#include "jsonutil.h"
#include "commonutil.h"
#include "parsedata.h"
#include "key_agreement_version.h"
#include "add_auth_info.h"
void free_auth_start_response(void *obj)
{
    if (obj != NULL) {
        FREE(obj);
    }
}
#else /* _CUT_XXX_ */
#include "parsedata.h"
#endif /* _CUT_XXX_ */
