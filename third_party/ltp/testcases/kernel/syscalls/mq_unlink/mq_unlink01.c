#include <errno.h>
#include <pwd.h>
#include <mqueue.h>
#include "tst_test.h"
#include "tst_safe_posix_ipc.h"
#define QUEUE_NAME	"/test_mqueue"
