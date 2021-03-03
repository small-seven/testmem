#include "tzdst.h"
#include "tzdst_pri.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "los_typedef.h"
#include "los_typedef.h"
#include "los_printf.h"
#include "securec.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/* 2: leap year or normal year */
STATIC const INT32 g_monLengths[2][MONSPERYEAR] = {
    { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
#define IS_NUM(x) (((x) >= '0') && ((x) <= '9'))
#define OPERATE_OFF     3
#define HOUR_HIGH_OFF   4
#define HOUR_LOW_OFF    5
#define MIN_HIGH_OFF    7
#define MIN_LOW_OFF     8
#define SEC_HIGH_OFF    10
#define SEC_LOW_OFF     11
#define STANDARD_TZ_LEN 15
#define MIN_BUF_LEN     (OPERATE_OFF + 1)
#define DST_STR_LEN_FORMAT_MDAY 15 /* for example "Feb-03 03:00:00" */
#define DST_STR_LEN_FORMAT_WDAY 20 /* for example "Oct-1st-Fri 02:59:59" */
#define DST_SET_LENGTH_MAX (DST_STR_LEN_FORMAT_WDAY + 1)
#define MONTH_NAME_LEN 3
#define FIRST_DAY 4   /* the first day of 1970.1.1 is Thursday. */
#ifdef __cplusplus
#if __cplusplus
#endif
#endif
