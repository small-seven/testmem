#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/utsname.h>
#include <endian.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "test.h"
#include "lapi/sync_file_range.h"
#include "check_sync_file_range.h"
#ifndef SYNC_FILE_RANGE_WAIT_BEFORE
#define SYNC_FILE_RANGE_WAIT_BEFORE 1
#define SYNC_FILE_RANGE_WRITE 2	//DUMMY VALUES
#define SYNC_FILE_RANGE_WAIT_AFTER 4
#endif
#define SYNC_FILE_RANGE_INVALID 8
