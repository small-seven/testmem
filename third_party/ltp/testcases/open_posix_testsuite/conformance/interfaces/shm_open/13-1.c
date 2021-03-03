#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "posixtest.h"
#define SHM_NAME "posixtest_13-1"
#define BUF_SIZE 8
