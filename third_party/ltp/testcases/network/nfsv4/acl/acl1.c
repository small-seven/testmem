#include <sys/param.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include "config.h"
#include "tst_res_flags.h"
#ifdef HAVE_LIBACL
#include <sys/acl.h>
#define OP_READ 0x1
#define OP_WRITE 0x2
#define OP_EXEC 0x4
#else
#endif /* HAVE_LIBACL */
