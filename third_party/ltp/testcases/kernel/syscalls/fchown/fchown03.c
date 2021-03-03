#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <grp.h>
#include <pwd.h>
#include "test.h"
#include "safe_macros.h"
#include "compat_16.h"
#define FILE_MODE (mode_t)(S_IFREG | S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
#define NEW_PERMS (mode_t)(S_IFREG | S_IRWXU | S_IRWXG | S_ISUID | S_ISGID)
#define FCHOWN_PERMS	(mode_t)(NEW_PERMS & ~(S_ISUID | S_ISGID))
#define TESTFILE	"testfile"
