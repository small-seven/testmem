#define SIGTOTEST SIGRTMIN
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <pwd.h>
#include "posixtest.h"
#define MAX_ATTEMPTS	10000
