#include <errno.h>
#include "tst_test.h"
#include "tst_timer.h"
#include "tst_safe_macros.h"
#define MIN_TIME_LIMIT	5
#define OP_OPEN_RDONLY	0
#define OP_OPEN_WRONLY	1
#define OP_OPEN_RDWR	2
#define OP_TRUNCATE	3
#define FILE_MODE	(S_IRWXU | S_IRWXG | S_IRWXO | S_ISUID | S_ISGID)
#define PATH_LS_BRK_T	"/proc/sys/fs/lease-break-time"
