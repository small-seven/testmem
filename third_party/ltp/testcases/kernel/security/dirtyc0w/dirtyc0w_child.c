#include <sys/mman.h>
#include <fcntl.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <pwd.h>
#include "tst_safe_pthread.h"
#define TST_NO_DEFAULT_MAIN
#include "tst_test.h"
#define FNAME "test"
#define STR   "this is not a test\n"
