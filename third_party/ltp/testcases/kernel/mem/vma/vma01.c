#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"
#include "safe_macros.h"
#define MAPS_FILE "/proc/self/maps"
