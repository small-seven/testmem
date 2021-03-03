#include <securec.h>
#include "log.h"
#include "mem_stat.h"
#include "jsonutil.h"
#include "base.h"
#include "parsedata.h"
#include "key_agreement_version.h"
void free_inform_message(void *obj)
{
    if (obj != NULL) {
        FREE(obj);
    }
}
