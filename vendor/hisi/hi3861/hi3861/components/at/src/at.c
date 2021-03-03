#include <hi_stdlib.h>
#include <at.h>
#include <at_cmd.h>
#include <at_parse.h>
#include "hi_config.h"
#include "stdio.h"
#include "string.h"
#include "malloc.h"
#include "stdarg.h"
#include "securec.h"
#ifdef __cplusplus
#if __cplusplus
#endif
#endif
#define AT_SSID_MAX_LEN 32
void *at_malloc(size_t size)
{
    if (size > 4096) {  /* max alloc mem 4096 */
        return NULL;
    }
    void *ptr = malloc(size);
    return ptr;
}
void at_free(char *ptr)
{
    if (ptr) {
        free(ptr);
    }
}
#ifdef __cplusplus
#if __cplusplus
#endif
#endif
