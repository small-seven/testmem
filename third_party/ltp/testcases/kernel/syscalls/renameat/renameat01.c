#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <sys/mount.h>
#include "test.h"
#include "safe_macros.h"
#include "lapi/fcntl.h"
#include "lapi/renameat.h"
#define MNTPOINT "mntpoint"
#define TESTDIR "testdir"
#define NEW_TESTDIR "new_testdir"
#define TESTDIR2 "/loopdir"
#define NEW_TESTDIR2 "newloopdir"
#define TESTDIR3 "emlinkdir"
#define NEW_TESTDIR3 "testemlinkdir/new_emlinkdir"
#define TESTFILE "testfile"
#define NEW_TESTFILE "new_testfile"
#define TESTFILE2 "testfile2"
#define NEW_TESTFILE2 "new_testfile2"
#define TESTFILE3 "testdir/testfile"
#define TESTFILE4 "testfile4"
#define TESTFILE5 "mntpoint/rofile"
#define NEW_TESTFILE5 "mntpoint/newrofile"
#define DIRMODE (S_IRWXU | S_IRWXG | S_IRWXO)
#define FILEMODE (S_IRWXU | S_IRWXG | S_IRWXO)
