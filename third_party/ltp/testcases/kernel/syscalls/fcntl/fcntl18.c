#include <signal.h>
#include <errno.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <fcntl.h>
#include <unistd.h>
#include "test.h"
#define INVAL_FLAG	-1
#define INVAL_MIN	(-2147483647L-1L)
#ifndef UCLINUX
#else
#endif
#ifndef UCLINUX
#else
#endif
