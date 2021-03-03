#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "test.h"
#include "safe_macros.h"
#define MAX_FILES_CREATED	4
#define MAX_PATH		128
#define MAX_CMD_LEN		64
#define MAX_USER_NAME		16
#define BASE_DIR_NUM		(USERS_NUM + 1)
#define MAX_ENTITIES		(MAX_FILES_CREATED * BASE_DIR_NUM)
