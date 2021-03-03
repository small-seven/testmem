#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "tst_test.h"
#include "tst_safe_macros.h"
#define TESTFILE        "test_file"
#define FILE_SIZE       1024
#define FILE_MODE	0644
