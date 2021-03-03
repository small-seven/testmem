#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include "tst_test.h"
#define FNAME_RWX "accessfile_rwx"
#define FNAME_R   "accessfile_r"
#define FNAME_W   "accessfile_w"
#define FNAME_X   "accessfile_x"
#define DNAME_R   "accessdir_r"
#define DNAME_W   "accessdir_w"
#define DNAME_X   "accessdir_x"
#define DNAME_RW  "accessdir_rw"
#define DNAME_RX  "accessdir_rx"
#define DNAME_WX  "accessdir_wx"
