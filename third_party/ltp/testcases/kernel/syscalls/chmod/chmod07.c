#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <grp.h>
#include <pwd.h>
#include "tst_test.h"
#define FILE_MODE	(S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
#define PERMS		01777	/* Permissions with sticky bit set. */
#define TESTFILE	"testfile"
