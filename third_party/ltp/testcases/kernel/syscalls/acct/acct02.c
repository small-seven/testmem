#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "tst_kconfig.h"
#include "tst_test.h"
#include "lapi/acct.h"
#define COMMAND		"acct02_helper"
#define OUTPUT_FILE	"acct_file"
#define UNPACK(x) ((x & 0x1fff) << (((x >> 13) & 0x7) * 3))
#define ACCT_MEMBER(x) (v3 ? ((struct acct_v3 *)acc)->x : ((struct acct *)acc)->x)
#define ACCT_MEMBER_V3(x) (((struct acct_v3 *)acc)->x)
