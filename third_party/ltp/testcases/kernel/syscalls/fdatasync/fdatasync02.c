#include <errno.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "test.h"
#include "safe_macros.h"
#define EXP_RET_VAL	-1
#define SPL_FILE	"/dev/null"
