#include "global_utils.h"
#include <fcntl.h>
#include <limits.h>
#include <securec.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX_ID_ITEM_NUM    0x7F
#define MAX_RES_CONFIG_NUM 0x10
#define MAX_ITEM_LENGTH    0xFF
static void FreeKeyParams(Key *keys, int32_t count)
{
    if (keys == NULL) {
        return;
    }
    for (int32_t i = 0; i < count; i++) {
        if (keys[i].keysCount != 0) {
            free(keys[i].keyParams);
            keys[i].keyParams = NULL;
            keys[i].keysCount = 0;
        }
    }
}
#if (defined(_WIN32) || defined(_WIN64))
#else
#endif
