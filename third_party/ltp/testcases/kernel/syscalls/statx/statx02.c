#define _GNU_SOURCE
#include <stdio.h>
#include <inttypes.h>
#include "tst_test.h"
#include "tst_safe_macros.h"
#include "lapi/stat.h"
#define TESTFILE "test_temp"
#define LINK_FILE "test_temp_ln"
#define MODE 0644
#define SIZE 14
