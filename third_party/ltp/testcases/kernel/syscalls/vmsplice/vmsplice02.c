#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <limits.h>
#include "tst_test.h"
#include "lapi/syscalls.h"
#include "lapi/fcntl.h"
#include "lapi/vmsplice.h"
#define TESTFILE "testfile"
#define TEST_BLOCK_SIZE 128
