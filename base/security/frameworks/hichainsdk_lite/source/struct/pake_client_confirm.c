#if !(defined(_CUT_PAKE_) || defined(_CUT_PAKE_SERVER_))
#include <log.h>
#include <securec.h>
#include "mem_stat.h"
#include "jsonutil.h"
#include "commonutil.h"
#include "pake_server.h"
#include "parsedata.h"
#include "key_agreement_version.h"
void free_pake_client_confirm(void *obj)
{
    if (obj != NULL) {
        FREE(obj);
    }
}
#else /* _CUT_XXX_ */
#include "parsedata.h"
#endif /* _CUT_XXX_ */
