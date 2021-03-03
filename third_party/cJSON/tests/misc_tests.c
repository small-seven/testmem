#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unity/examples/unity_config.h"
#include "unity/src/unity.h"
#include "common.h"
static void * CJSON_CDECL failing_realloc(void *pointer, size_t size)
{
    (void)size;
    (void)pointer;
    return NULL;
}
static void ensure_should_fail_on_failed_realloc(void)
{
    printbuffer buffer = {NULL, 10, 0, 0, false, false, {&malloc, &free, &failing_realloc}};
    buffer.buffer = (unsigned char*)malloc(100);
    TEST_ASSERT_NOT_NULL(buffer.buffer);

    TEST_ASSERT_NULL_MESSAGE(ensure(&buffer, 200), "Ensure didn't fail with failing realloc.");
}
