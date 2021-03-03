#define _GNU_SOURCE
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/wait.h>
#include "tst_test.h"
#define STACK_LIMIT (512 * 1024)
