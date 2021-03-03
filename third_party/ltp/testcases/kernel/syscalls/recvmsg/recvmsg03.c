#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "tst_safe_net.h"
#include "tst_test.h"
#ifndef AF_RDS
# define AF_RDS 21
#endif
