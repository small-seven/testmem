#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include "posixtest.h"
#define SLEEPSEC 30
#define CHILDPASS 1
#define CHILDFAIL 0
