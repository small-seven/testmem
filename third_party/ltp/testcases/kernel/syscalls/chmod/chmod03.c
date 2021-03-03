#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <pwd.h>
#include "test.h"
#include "safe_macros.h"
#define FILE_MODE       S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
#define PERMS		01777	/*
#define TESTFILE	"testfile"
