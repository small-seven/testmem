#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>         /* for sockaddr_in */
#include <arpa/inet.h>
#include <netinet/sctp.h>
#include "tst_test.h"
#include "tst_net.h"
#ifdef PROT_SOCK
#define SCTP_TESTPORT_1 PROT_SOCK
#else
#define SCTP_TESTPORT_1 1024
#endif
#define SCTP_IP_LOOPBACK  htonl(0x7f000001)
