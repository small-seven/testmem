#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "tst_test.h"
#include "lapi/splice.h"
#define TEST_FILE "testfile"
#define TEST_FILE2 "testfile2"
#define TEST_FILE3 "testfile3"
#define STR "abcdefghigklmnopqrstuvwxyz"
#define SPLICE_TEST_LEN 10
