#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include "posixtest.h"
#define WRITE(str) write(STDOUT_FILENO, str, sizeof(str) - 1)
