#include <sys/stat.h>
#include <sys/mount.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "test.h"
#include "safe_macros.h"
#define MAX_SUBSYS		16
#define MAX_OPTIONS_LEN		256
#define MAX_DIR_NAME		64
#define DEFAULT_VALUE_SIZE	8
#define MAX_OPEN_DIR		32
