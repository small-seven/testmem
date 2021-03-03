#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "posixtest.h"
#define SLEEPSEC 5
#define CHILDPASS 1
#define CHILDFAIL 0
#ifdef DEBUG
#endif
