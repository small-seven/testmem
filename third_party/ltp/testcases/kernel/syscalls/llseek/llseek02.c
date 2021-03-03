#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <stdio.h>
#include "tst_test.h"
#define TEMP_FILE1 "tmp_file1"
#define TEMP_FILE2 "tmp_file2"
#define FILE_MODE S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
#define SEEK_TOP 10
