#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include "test.h"
#include "safe_macros.h"
#define OLDPATH "oldpath"
#define NEWPATH "newpath"