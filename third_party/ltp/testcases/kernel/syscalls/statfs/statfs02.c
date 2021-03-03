#include <sys/types.h>
#include <sys/statfs.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/vfs.h>
#include <sys/mman.h>
#include <errno.h>
#include "test.h"
#include "safe_macros.h"
#define TEST_FILE		"statfs_file"
#define TEST_FILE1		TEST_FILE"/statfs_file1"
#define TEST_NOEXIST		"statfs_noexist"
#define TEST_SYMLINK		"statfs_symlink"
#ifndef UCLINUX
#endif
#if !defined(UCLINUX)
#endif
