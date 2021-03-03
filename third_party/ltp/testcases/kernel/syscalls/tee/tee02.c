#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "tst_test.h"
#include "lapi/tee.h"
#define TEST_FILE "testfile"
#define STR "abcdefghigklmnopqrstuvwxyz"
#define TEE_TEST_LEN 10
