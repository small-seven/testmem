#define PATH_STRING_LENGTH  1024
#define NAME_LENGTH  8
#define MAX_PATH_STRING_LENGTH  (PATH_STRING_LENGTH - NAME_LENGTH - 40)
#define DIRECTORY_MODE  00777
#define FILE_MODE       00777
#define MKDIR_STRING_LENGTH  (MAX_PATH_STRING_LENGTH + 7)
#define TRUE  1
#define FALSE 0
#define READ  0
#define WRITE 1
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#ifdef LINUX
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#endif
#define MAXCHILD	25
#ifdef LINUX
#endif
#include "test.h"
#define FAILED 0
#define PASSED 1
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
