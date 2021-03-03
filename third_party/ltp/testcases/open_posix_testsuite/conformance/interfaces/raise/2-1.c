#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "posixtest.h"
#define SIGTOTEST SIGABRT
#define BEFOREHANDLER 1
#define INHANDLER 2
#define LEAVINGHANDLER 3
