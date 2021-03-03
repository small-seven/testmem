#include <pthread.h>
#include <pwd.h>
#include <stdio.h>
#include <sys/types.h>
#include "tst_safe_pthread.h"
#include "tst_test.h"
#include "tgkill.h"
#define CHECK_ENOENT(x) ((x) == -1 && errno == ENOENT)
