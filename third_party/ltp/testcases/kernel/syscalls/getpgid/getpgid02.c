#define _GNU_SOURCE 1
#include <errno.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "test.h"
#define BADPID -99
