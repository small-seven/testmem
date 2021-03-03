#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "test.h"
#include "lapi/abisize.h"
#ifdef TST_ABI32
#else /* no 64-bit */
#endif
