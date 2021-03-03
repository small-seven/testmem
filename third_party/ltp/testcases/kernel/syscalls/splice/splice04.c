#define _GNU_SOURCE
#include <fcntl.h>
#include <stdlib.h>
#include "tst_test.h"
#include "lapi/splice.h"
#include "splice.h"
#define PIPE_MAX (64*1024)
