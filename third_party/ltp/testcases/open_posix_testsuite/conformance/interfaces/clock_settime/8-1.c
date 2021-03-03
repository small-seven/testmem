#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include "posixtest.h"
#include "helpers.h"
#define SLEEPSEC 5
#define SMALLTIME 2
#define ACCEPTABLEDELTA 1
#define CHILDPASS 1
#define CHILDFAIL 0
