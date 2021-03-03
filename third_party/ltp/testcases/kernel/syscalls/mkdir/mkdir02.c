#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "tst_test.h"
#define TESTDIR1	"testdir1"
#define TESTDIR2	"testdir1/testdir2"
