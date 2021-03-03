#define _GNU_SOURCE
#include <errno.h>
#include <sys/sysmacros.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "tst_test.h"
#define MNTPOINT "mntpoint"
#define T_REG "t_reg"			/* regular file with content */
#define T_REG_EMPTY "t_reg_empty"	/* empty regular file */
#define T_LINK_REG "t_link_reg"		/* hard link to T_REG */
#define T_NEW_REG "t_new_reg"		/* new regular file to be created */
#define T_SYMLINK_REG "t_symlink_reg"	/* symlink to T_REG */
#define T_DIR "t_dir"			/* test dir */
#define T_SYMLINK_DIR "t_symlink_dir"	/* symlink to T_DIR */
#define T_DEV MNTPOINT"/t_dev"		/* test device special file */
#define T_MSG "this is a test string"
