#include <errno.h>
#include <pwd.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/types.h>
#include "tst_test.h"
#define NEW_PRIO	-2
#define INVAL_FLAG	-1
#define INVAL_ID	-1
#define INIT_PID	1
