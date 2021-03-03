#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <pwd.h>
#include <string.h>
#include "posixtest.h"
#define SHM_NAME "posixtest_9-1"
#define BUF_SIZE 8
