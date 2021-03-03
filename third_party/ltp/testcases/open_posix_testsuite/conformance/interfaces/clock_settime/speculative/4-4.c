#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "posixtest.h"
#include "../helpers.h"
#define TIMERINTERVAL 5
#define ADDITIONALEXPIRES 2
#define ADDITIONALDELTA 1
#define SIGTOTEST SIGALRM
