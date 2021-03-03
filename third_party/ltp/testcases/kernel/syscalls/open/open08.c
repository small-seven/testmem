#define _GNU_SOURCE		/* for O_DIRECTORY */
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <signal.h>
#include <pwd.h>
#include "tst_test.h"
#include "tst_get_bad_addr.h"
