#define _GNU_SOURCE
#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <sys/syscall.h>
#include <sys/mount.h>
#include <fcntl.h>
#include "tst_test.h"
#include "lapi/execveat.h"
#include "lapi/fcntl.h"
#include "execveat.h"
#define TEST_APP "execveat_child"
#define TEST_FILE_PATH OVL_MNT"/"TEST_APP
