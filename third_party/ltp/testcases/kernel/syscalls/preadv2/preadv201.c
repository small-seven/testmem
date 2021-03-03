#define _GNU_SOURCE
#include <string.h>
#include <sys/uio.h>
#include "tst_test.h"
#include "lapi/preadv2.h"
#define CHUNK           64
