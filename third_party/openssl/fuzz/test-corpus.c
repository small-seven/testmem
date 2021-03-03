#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <openssl/crypto.h>
#include "fuzzer.h"
#include "internal/o_dir.h"
#if defined(_WIN32) && defined(_MAX_PATH)
# define PATH_MAX _MAX_PATH
#endif
#ifndef PATH_MAX
# define PATH_MAX 4096
#endif
# if !defined(S_ISREG)
#   define S_ISREG(m) ((m) & S_IFREG)
# endif
#ifdef __VMS
#endif
