#include "vfs_config.h"
#include <fs/file.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fs/fs.h>
#ifndef CONFIG_LIB_SENDFILE_BUFSIZE
#  define CONFIG_LIB_SENDFILE_BUFSIZE 512
#endif
