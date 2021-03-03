#include <stdio.h>
#include <errno.h>
#include <sys/resource.h>
#include "test.h"
#define RLIMIT_TOO_HIGH 1000
#ifndef UCLINUX
#endif
