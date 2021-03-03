#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pwd.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include "posixtest.h"
#define BUF_SIZE 8
#define SHM_NAME "posixtest_26-2"
