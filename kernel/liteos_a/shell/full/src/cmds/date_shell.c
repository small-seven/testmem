#include "shcmd.h"
#include "shell.h"
#include "stdlib.h"
#include "time.h"
#include "los_typedef.h"
#include "los_typedef.h"
#include "sys/stat.h"
#include "securec.h"
#include "inode/inode.h"

#if defined(__LP64__)
#define  timeval64      timeval
#define  settimeofday64 settimeofday
#define  gettimeofday64 gettimeofday
#endif

#define  localtime64    localtime
#define  ctime64        ctime
#define  mktime64       mktime

#define  DATE_ERR_INFO      1
#define  DATE_HELP_INFO     0
#define  DATE_ERR           (-1)
#define  DATE_OK            0
#define  DATE_BASE_YEAR     1900
#define  LEAPYEAR(y) (((y) % 4) == 0 && (((y) % 100) != 0 || ((y) % 400) == 0))

STATIC const INT32 g_monLengths[2][12] = { /* 2: 2 Column,Contains leap year; 12: 12 months */
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
#ifdef  LOSCFG_FS_VFS
#define BUFFER_SIZE 26 /* The buffer size is equal to the size used by the asctime_r interface */
#endif
#ifdef  LOSCFG_FS_VFS
#endif
