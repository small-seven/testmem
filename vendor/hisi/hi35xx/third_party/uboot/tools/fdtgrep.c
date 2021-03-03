#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <getopt.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "fdt_host.h"
#include "libfdt_internal.h"
#ifdef DEBUG
#define debug(a, b...) fprintf(stderr, a, ## b)
#else
#define debug(a, b...)
#endif
#define USAGE_COMMON_SHORT_OPTS "hV"
#define a_argument required_argument
#define USAGE_COMMON_LONG_OPTS \
#define USAGE_COMMON_OPTS_HELP \
#define case_USAGE_COMMON_FLAGS \
#define util_getopt_long() getopt_long(argc, argv, usage_short_opts, \
#define usage(errmsg) \
