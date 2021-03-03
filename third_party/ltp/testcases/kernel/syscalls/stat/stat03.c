#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include "tst_test.h"
#define TST_EACCES_DIR   "tst_eaccesdir"
#define TST_EACCES_FILE  "tst_eaccesdir/tst"
#define TST_ENOENT       "tst_enoent/tst"
#define TST_ENOTDIR_DIR  "tst_enotdir/tst"
#define TST_ENOTDIR_FILE "tst_enotdir"
#define MODE_RW	        0666
#define DIR_MODE        0755
