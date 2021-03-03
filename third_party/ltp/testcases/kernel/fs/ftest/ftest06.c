#define _LARGEFILE64_SOURCE 1
#include <stdio.h>
#include <sys/types.h>
#include <sys/param.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mount.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include "test.h"
#include "libftest.h"
#define PASSED 1
#define FAILED 0
#define MAXCHILD	25
#define K_1		1024
#define K_2		2048
#define K_4		4096
#define M       (1024*1024)
#define	warn(val,m1,m2)	if ((val) < 0) dowarn(me,m1,m2)
#define	THING(p)	{p, "p"}
#define	NTHING	ARRAY_SIZE(ino_thing)
