#define _GNU_SOURCE		/* for O_NOFOLLOW */
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "test.h"
#include "safe_macros.h"
