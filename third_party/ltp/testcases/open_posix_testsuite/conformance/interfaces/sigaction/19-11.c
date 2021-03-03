#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include "posixtest.h"
#define WRITE(str) write(STDOUT_FILENO, str, sizeof(str) - 1)
