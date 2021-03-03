#include "param_adaptor.h"
#include <ctype.h>
#include <fcntl.h>
#include <limits.h>
#include <securec.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "ohos_errno.h"
#define DATA_PATH          "/storage/data/system/param/"
#define MAX_KEY_PATH       128
#define SYS_UID_INDEX      1000
