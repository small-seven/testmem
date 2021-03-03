#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <mntent.h>
#include "test.h"
#include "safe_macros.h"
#include "lapi/fcntl.h"
#include "openat.h"
#define TEST_APP "openat02_child"
#define TEST_FILE "test_file"
#define SFILE "sfile"
#define LARGE_FILE "large_file"
#define STR "abcdefg"
