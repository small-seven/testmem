#define _GNU_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <pwd.h>
#include "tst_test.h"
#define TEST_FILE	"test_file"
#define TEST_FILE2	"test_file2"
