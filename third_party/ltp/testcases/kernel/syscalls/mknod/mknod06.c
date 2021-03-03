#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <sys/mman.h>
#include "test.h"
#define MODE_RWX		S_IFIFO | S_IRWXU | S_IRWXG | S_IRWXO
