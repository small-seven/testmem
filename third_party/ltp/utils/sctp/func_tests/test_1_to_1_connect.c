#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <linux/socket.h>
#include <netinet/in.h>         /* for sockaddr_in */
#include <arpa/inet.h>
#include <sys/errno.h>
#include <sys/uio.h>
#include <netinet/sctp.h>
#include "sctputil.h"
#define SK_MAX 10
