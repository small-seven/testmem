#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <setjmp.h>
#include "test.h"
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#define NCHILD		3
#define MODE_RWX	07770
#define DIR_NAME	"./X.%d"
