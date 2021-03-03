#include "kvstore_common.h"
#include <ctype.h>
#include <securec.h>
#include <stdlib.h>
#include "ohos_errno.h"
#ifdef FEATURE_KV_CACHE
#endif
#ifdef FEATURE_KV_CACHE
static void FreeItem(KvItem* item)
{
    if (item == NULL) {
        return;
    }
    if (item->key != NULL) {
        free(item->key);
        item->key = NULL;
    }
    if (item->value != NULL) {
        free(item->value);
        item->value = NULL;
    }
    free(item);
    item = NULL;
}
#endif