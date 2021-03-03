#include <stdlib.h>
#define CONFIG_HARDCODED_TABLES 0
#include "aac_defines.h"
#if USE_FIXED
#define TYPE_NAME "int32_t"
typedef int32_t INT32FLOAT;
#define ARRAY_RENAME(x) write_int32_t_ ## x
#define ARRAY_URENAME(x) write_uint32_t_ ## x
#include "aacps_fixed_tablegen.h"
#else
#define TYPE_NAME "float"
typedef float INT32FLOAT;
#define ARRAY_RENAME(x) write_float_ ## x
#define ARRAY_URENAME(x) write_float_ ## x
#include "aacps_tablegen.h"
#endif /* USE_FIXED */
#include "tableprint.h"

void ARRAY_RENAME(3d_array) (const void *p, int b, int c, int d)
{
    int i;
    const INT32FLOAT *f = p;
    for (i = 0; i < b; i++) {
        printf("{\n");
        ARRAY_URENAME(2d_array)(f, c, d);
        printf("},\n");
