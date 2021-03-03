#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <grp.h>
#include <pwd.h>
#include "test.h"
#define PASSED 1
#define FAILED 0
#define MODE_RWX        (S_IRWXU | S_IRWXG | S_IRWXO)
#define MODE_SGID       (S_ISGID | S_IRWXU | S_IRWXG | S_IRWXO)
#define DIR_A_TEMP	"open10.testdir.A.%d"
#define DIR_B_TEMP	"open10.testdir.B.%d"
#define SETGID		"setgid"
#define NOSETGID	"nosetgid"
#define ROOT_SETGID	"root_setgid"
#define	MSGSIZE		150
