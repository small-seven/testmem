#include "e_os.h"
#include <errno.h>
#define LP_DIR_CTX OPENSSL_DIR_CTX
#define LP_dir_context_st OPENSSL_dir_context_st
#define LP_find_file OPENSSL_DIR_read
#define LP_find_file_end OPENSSL_DIR_end
#include "internal/o_dir.h"
#define LPDIR_H
#if defined OPENSSL_SYS_UNIX || defined DJGPP \
# include "LPdir_unix.c"
#elif defined OPENSSL_SYS_VMS
# include "LPdir_vms.c"
#elif defined OPENSSL_SYS_WIN32
# include "LPdir_win32.c"
#elif defined OPENSSL_SYS_WINCE
# include "LPdir_wince.c"
#else
# include "LPdir_nyi.c"
#endif
