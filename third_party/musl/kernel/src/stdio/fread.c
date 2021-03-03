#include "stdio_impl.h"
#include <string.h>
#include "menuconfig.h"
#ifdef LOSCFG_LLTSER
#include "gcov_ser.h"
#endif
#include "fs/fs.h"
#include "fs/file.h"
#define MIN(a,b) ((a)<(b) ? (a) : (b))
#ifdef LOSCFG_LLTSER
#endif
