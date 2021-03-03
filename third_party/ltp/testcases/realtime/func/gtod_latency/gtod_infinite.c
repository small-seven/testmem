#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sched.h>
#include <librttest.h>
#include <sys/mman.h>
#include <unistd.h>
#include <signal.h>
#define CLOCK_TO_USE CLOCK_MONOTONIC
#define START_MAX	3000
#define REPORT_MIN	1000000
