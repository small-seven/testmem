#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <librttest.h>
#define TEST_FUNCTION do_test(argc, argv)
#define TIMEOUT 20
