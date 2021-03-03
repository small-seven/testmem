#include "stdio_impl.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include "menuconfig.h"
#ifdef LOSCFG_LLTSER
#include "gcov_ser.h"
#endif
#include "fs/fs.h"
#include "fs/file.h"
#ifdef LOSCFG_LLTSER
#endif
#if !defined(__LP64__)
#endif
