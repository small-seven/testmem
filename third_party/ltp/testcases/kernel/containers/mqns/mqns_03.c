#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "mqns.h"
#include "mqns_helper.h"
#define FNAM1 DEV_MQUEUE2 SLASH_MQ1
#define FNAM2 DEV_MQUEUE2 SLASH_MQ2
