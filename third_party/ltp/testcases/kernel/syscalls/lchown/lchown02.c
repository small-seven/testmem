#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <grp.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include "test.h"
#include "safe_macros.h"
#include "compat_16.h"
#define TEST_USER       "nobody"
#define MODE_RWX	S_IRWXU | S_IRWXG | S_IRWXO
#define FILE_MODE	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
#define DIR_TEMP	"testdir_1"
#define TEST_FILE1	"tfile_1"
#define SFILE1		"sfile_1"
#define TEST_FILE2	"testdir_1/tfile_2"
#define SFILE2		"testdir_1/sfile_2"
#define TFILE3          "t_file"
#define SFILE3		"t_file/sfile"
