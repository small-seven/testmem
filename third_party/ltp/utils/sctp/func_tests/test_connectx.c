#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/uio.h>
#include <netinet/in.h>
#include <errno.h>
#include <netinet/sctp.h>
#include <sctputil.h>
#define NUMADDR 6
#define SCTP_IP_LOOPBACK_I(I)  htonl(0x7f000001 + I)
#define NIPQUAD(addr) \
