#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "posixtest.h"
#define EXPIREDELTA 3
#define LONGTIME 5
#define CHILDPASS 1
