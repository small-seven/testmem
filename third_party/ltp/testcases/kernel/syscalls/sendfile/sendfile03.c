#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/sendfile.h>
#include "test.h"
#define FAILED 1
#ifndef OFF_T
#define OFF_T off_t
#endif /* Not def: OFF_T */
