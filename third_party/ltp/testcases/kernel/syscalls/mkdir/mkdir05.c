#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include "tst_test.h"
#define PERMS		0777
#define TESTDIR		"testdir"
