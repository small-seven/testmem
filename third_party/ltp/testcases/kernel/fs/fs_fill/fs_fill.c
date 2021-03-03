#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include "tst_safe_pthread.h"
#include "tst_test.h"
#define MNTPOINT "mntpoint"
