#define _GNU_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <pwd.h>
#include <sys/resource.h>
#include "test.h"
#include "safe_macros.h"
#define TEST_FILE1	"testfile"
#define TEST_FILE2	"t_file/testfile"
#define TEST_FILE3	"testfile3"
#define TEST_SYM1	"testsymlink1"
#define TEST_SYM2	"testsymlink2"
#define TEST_DIR1	"testdir"
#define FILE_MODE	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
#define NEW_MODE	S_IRUSR | S_IRGRP | S_IROTH
#define DIR_MODE	S_IRWXU
#define TRUNC_LEN	256
#define MAX_FSIZE	(16*1024*1024)
