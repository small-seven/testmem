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
#define DIR_MODE 	S_IRWXU | S_IRWXG | S_IRWXO
#define PERMS		01777	/*
#define TESTDIR		"testdir_4"
