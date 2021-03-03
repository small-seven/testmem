#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/param.h>
#include <signal.h>
#include <errno.h>
#include "test.h"
#include "safe_macros.h"
#define	KIDEXIT	42
#define MAX_LINE_LENGTH 256
#define OUTPUT_FILE  "env.out"
#define ENV_NOT_SET  "getenv() does not find variable set"
#define NUMBER_OF_ENVIRON (sizeof(environ_list)/sizeof(char *))
