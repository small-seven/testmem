#include "los_crc32.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#define COUNT1    val = crc32_tab[(val ^ (*src++)) & 0xff] ^ (val >> 8)
#define COUNT2    COUNT1; COUNT1
#define COUNT4    COUNT2; COUNT2
#define COUNT8    COUNT4; COUNT4
#define ACCRATIO    8
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
