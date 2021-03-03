#include "config.h"
#include "tst_test.h"
#include "tst_taint.h"
#include "tst_fuzzy_sync.h"
#include "tst_safe_macros.h"
#include "tst_safe_pthread.h"
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <sys/uio.h>
#include <sys/ioctl.h>
#include <sound/asound.h>
#define MAX_BUFSIZE 1024
