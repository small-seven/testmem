#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include "libubi.h"
#define PROGRAM_NAME "mkvol_paral"
#include "common.h"
#include "helpers.h"
#define THREADS_NUM 4
#define ITERATIONS  500
