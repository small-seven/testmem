#define _GNU_SOURCE
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <sys/mount.h>
#include "test.h"
#include "safe_macros.h"
#include "lapi/fcntl.h"
#include "mknodat.h"
#define DIR_MODE	(S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP| \
#define MNT_POINT	"mntpoint"
#define FIFOMODE	(S_IFIFO | S_IRUSR | S_IRGRP | S_IROTH)
#define FREGMODE	(S_IFREG | S_IRUSR | S_IRGRP | S_IROTH)
#define SOCKMODE	(S_IFSOCK | S_IRUSR | S_IRGRP | S_IROTH)
#define ELOPFILE	"/test_eloop"
