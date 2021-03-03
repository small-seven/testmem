#define _GNU_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mount.h>
#include <unistd.h>
#include <mntent.h>
#include <errno.h>
#include "test.h"
#include "safe_macros.h"
#include "lapi/fcntl.h"
#include "lapi/mount.h"
#define MNTPOINT	"mntpoint"
#define TEST_FILE	MNTPOINT"/test_file"
#define LARGE_FILE	"large_file"
#define DIR_MODE 0755
