#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include "ns-mcast.h"
#include "ns-traffic.h"
#define ADDR_STR_MAXSIZE    80
#define OPEN_SOCK_MIN	    6