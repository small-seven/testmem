#include "global.h"
#include <fcntl.h>
#include <limits.h>
#include <securec.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "global_utils.h"
#define MAX_LOCALE_LENGTH 13
#define UI_LOCALE_ELEMENT_NUM 2
static void FreeIdItem(IdItem *idItem)
{
    if (idItem == NULL) {
        return;
    }
    free(idItem->value);
    free(idItem->name);
    idItem->value = NULL;
    idItem->name = NULL;
}
static void FreeValue(char **value)
{
    if (*value != NULL) {
        free(*value);
        *value = NULL;
    }
}
