#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include "tst_test.h"
#include "lapi/syscalls.h"
#define MNT_POINT "mntpoint"
#define TESTFILE1 "testfile1"
#define TESTFILE2 "testfile2"
#define TESTFILE3 "mntpoint/file"
#define FILE_MODE (S_IRWXU | S_IRGRP | S_IXGRP | \
#define DIR_MODE (S_IRWXU | S_IRWXG | S_IRWXO)
