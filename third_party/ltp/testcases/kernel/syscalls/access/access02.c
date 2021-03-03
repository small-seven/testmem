#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <paths.h>
#include "tst_test.h"
#define FNAME_F	"file_f"
#define FNAME_R	"file_r"
#define FNAME_W	"file_w"
#define FNAME_X	"file_x"
#define SNAME_F	"symlink_f"
#define SNAME_R	"symlink_r"
#define SNAME_W	"symlink_w"
#define SNAME_X	"symlink_x"
