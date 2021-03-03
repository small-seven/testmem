#define _GNU_SOURCE
#include "test.h"
#include "safe_macros.h"
#include "lapi/fcntl.h"
#include "renameat2.h"
#define TEST_DIR "test_dir/"
#define TEST_DIR2 "test_dir2/"
#define TEST_FILE "test_file"
#define TEST_FILE2 "test_file2"
