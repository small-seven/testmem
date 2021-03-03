#define _GNU_SOURCE
#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "userns_helper.h"
#include "test.h"
#define CHILD1UID 0
#define CHILD1GID 0
#define CHILD2UID 200
#define CHILD2GID 200
#define UID_MAP 0
#define GID_MAP 1
