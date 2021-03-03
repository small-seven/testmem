#include <sys/mman.h>
#include <fcntl.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <pwd.h>
#include "tst_test.h"
#define FNAME "test"
#define STR   "this is not a test\n"
