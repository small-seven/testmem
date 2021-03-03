#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "tst_test.h"
#ifndef IPPROTO_SCTP
# define IPPROTO_SCTP	132
#endif
