#define _GNU_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/mman.h>
#include "test.h"
#include "safe_macros.h"
#include "lapi/syscalls.h"
#include "lapi/readdir.h"
#define TEST_DIR	"test_dir"
#define TEST_DIR4	"test_dir4"
#define TEST_FILE	"test_file"
#define DIR_MODE	(S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP| \
#if !defined(UCLINUX)
#endif
#if !defined(UCLINUX)
#endif
