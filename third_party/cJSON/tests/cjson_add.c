#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unity/examples/unity_config.h"
#include "unity/src/unity.h"
#include "common.h"
static void * CJSON_CDECL failing_malloc(size_t size)
{
    (void)size;
    return NULL;
}
static void CJSON_CDECL normal_free(void *pointer)
{
    free(pointer);
}
