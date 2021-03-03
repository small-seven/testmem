#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/signal.h>
#include <sys/uio.h>
#include <sys/un.h>
#include <sys/file.h>
#include <netinet/in.h>
#include "test.h"
#include "safe_macros.h"
#ifdef UCLINUX
#endif
#ifdef UCLINUX
#endif
#ifdef UCLINUX
#else
#endif
#define TM	"from recvmsg01 server"
