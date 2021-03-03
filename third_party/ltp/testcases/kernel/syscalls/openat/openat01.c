#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include "test.h"
#include "safe_macros.h"
#include "lapi/fcntl.h"
#include "openat.h"
#define TEST_FILE "test_file"
#define TEST_DIR "test_dir/"
