#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#define PROGRAM_NAME "plotJittervsFill"
#include "common.h"
#define TRUE  1
#define FALSE 0
#define MIN_JITTER_THRESHOLD 1 /* ms minimum jitter threshold */
#define MAX_SAVE_BUFFER 1000 /* How many values will be picked up while searching for
