#define _GNU_SOURCE
#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "libclone.h"
#include "test.h"
#include "config.h"
#if HAVE_SYS_CAPABILITY_H
#include <sys/capability.h>
#endif
#ifdef HAVE_LIBCAP
#endif
#ifdef HAVE_LIBCAP
#else
#endif
