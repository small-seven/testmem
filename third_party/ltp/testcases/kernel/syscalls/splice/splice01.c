#define _GNU_SOURCE
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <fcntl.h>
#include "tst_test.h"
#include "lapi/splice.h"
#define TEST_BLOCK_SIZE 1024
#define TESTFILE1 "splice_testfile_1"
#define TESTFILE2 "splice_testfile_2"
