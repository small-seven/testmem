#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <grp.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <pwd.h>
#include "test.h"
#include "compat_16.h"
#define TESTUSER "root"
