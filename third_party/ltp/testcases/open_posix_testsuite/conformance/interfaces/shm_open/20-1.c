#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "posixtest.h"
#define BUF_SIZE 8
#define SHM_NAME "posixtest_20-1"
