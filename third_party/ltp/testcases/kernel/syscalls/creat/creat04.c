#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "tst_test.h"
#define DIRNAME "testdir"
#define FILENAME DIRNAME"/file1"
