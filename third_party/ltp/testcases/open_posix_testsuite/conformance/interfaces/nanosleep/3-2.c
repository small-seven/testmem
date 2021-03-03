#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "posixtest.h"
#define SLEEPSEC 5
#define CHILDPASS 0		//if interrupted, child will return 0
#define CHILDFAIL 1
