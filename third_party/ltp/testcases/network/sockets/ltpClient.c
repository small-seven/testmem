#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <resolv.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#define LOCAL_UDP_SERVER_PORT   10000
#define LOCAL_TCP_SERVER_PORT   10001
#define LOCAL_MCAST_SERVER_PORT 10002
#define MAX_MSG_LEN             256
#define TIMETOLIVE              10
#define PACKETSIZE	            64
#define NET_ERROR               -1
#define PACKET_LEN              1024	/* 1K should be plenty */
#define TRUE                    1
#define FALSE                   0
