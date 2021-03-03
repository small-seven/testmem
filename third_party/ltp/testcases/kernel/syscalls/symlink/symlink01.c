#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>		/* open(2) system call */
#include <errno.h>
#include <sys/types.h>
#include <utime.h>		/* utime(2) system call */
#include <sys/param.h>
#include <sys/stat.h>		/* stat(2) and lstat(2) system calls */
#include <stdint.h>
#include <unistd.h>
#include "test.h"
#define S_FILE "symbolic"	/* Name of symbolic link file */
#define O_FILE "object"		/* Name of object file */
#define A_S_FILE "asymbolic"	/* Another name for a symbolic link file */
#define Y_A_S_FILE "/NiCkEr"	/* Yet another symbolic link file */
#define BIG_STRING "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz"
#define DEFAULT_TCID  "symlink01"
#define SYMLINK "symlink01"
#define READLINK "readlink01"
#define STAT "stat04"
#define STAT_64 "stat04_64"
#define LSTAT "lstat01"
#define LSTAT_64 "lstat01_64"
#define MKDIR "mkdir05"
#define RMDIR "rmdir03"
#define CHDIR "chdir01"
#define LINK "link01"
#define UNLINK "unlink01"
#define CHMOD "chmod01"
#define UTIME "utime01"
#define RENAME "rename01"
#define OPEN "open01"
#define cktcsid(s1,s2) (!strcmp(s1,s2))
#define BUFMAX 512
#define MODE 0700
#define MASK 0100777		/* A regular file with r,w,x for all mask */
#ifndef ALL
#endif
#if ALL
#endif
#if DEBUG
#endif
#define creat_symlink(p1, p2) creat_symlink(p1, p2, NULL)
#if DEBUG
#endif
#define creat_object(p1) creat_object(p1, NULL, NULL)
