#include <stdio.h>
#include <fcntl.h>
#include "syscall.h"
#if defined(SYS_rename)
#elif defined(SYS_renameat)
#else
#endif
