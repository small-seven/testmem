#if !(defined(_CUT_PAKE_) || defined(_CUT_PAKE_SERVER_))
#include <securec.h>
#include "log.h"
#include "mem_stat.h"
#include "jsonutil.h"
#include "pake_server.h"
#include "key_agreement_version.h"
#include "parsedata.h"
void free_pake_request(void *obj)
{
    if (obj != NULL) {
        FREE(obj);
    }
}
#else /* _CUT_XXX_ */
#include "parsedata.h"
#endif /* _CUT_XXX_ */
