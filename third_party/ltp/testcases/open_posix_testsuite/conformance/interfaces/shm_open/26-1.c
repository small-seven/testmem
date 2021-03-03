#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "posixtest.h"
#define SHM_NAME "posixtest_26-1"
#define CREATION_MODE S_IRUSR|S_IWUSR
#define OPEN_MODE     S_IRGRP
