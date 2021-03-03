#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>
#include "tst_test.h"
#define DIR_MODE    0777
#define NOEXCUTE_MODE 0766
#define TESTDIR     "testdir"
#define TESTDIR2    "testdir/testdir2"
#define TESTDIR3    "testdir3"
#define TESTDIR4    "testdir3/testdir4"
