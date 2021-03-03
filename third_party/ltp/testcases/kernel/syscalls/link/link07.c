#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include "test.h"
#include "safe_macros.h"
#define MODE_TO S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IWGRP|S_IXGRP|S_IXOTH|S_IROTH|S_IWOTH
#define MODE_TE S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH
#define MODE_RWX        S_IRWXU | S_IRWXG | S_IRWXO
#define DIR_TEMP        "testdir_1"
#define TEST_FILE2      "testdir_1/tfile_2"
#define NEW_TEST_FILE2  "testdir_1/new_tfile_2"
