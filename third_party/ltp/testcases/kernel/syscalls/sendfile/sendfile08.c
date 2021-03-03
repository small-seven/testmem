#include <sys/sendfile.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "test.h"
#include "safe_macros.h"
#define TEST_MSG_IN "world"
#define TEST_MSG_OUT "hello"
#define TEST_MSG_ALL (TEST_MSG_OUT TEST_MSG_IN)
