#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include "test.h"
#include "safe_macros.h"
#define	K_1	1024
#define MODES   S_IRWXU
