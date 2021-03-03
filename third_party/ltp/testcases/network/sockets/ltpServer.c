#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#define LOCAL_UDP_SERVER_PORT   10000
#define LOCAL_TCP_SERVER_PORT   10001
#define LOCAL_MULTI_SERVER_PORT 10002
#define MAX_MSG_LEN             256
#define MAX_HOSTNAME_LEN        256
#define ERROR -1
#define END_LINE                0x0A
