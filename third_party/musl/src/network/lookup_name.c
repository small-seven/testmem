#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <resolv.h>
#include "lookup.h"
#include "stdio_impl.h"
#include "syscall.h"
#define RR_A 1
#define RR_CNAME 5
#define RR_AAAA 28
#if 0
#endif
#define DAS_USABLE              0x40000000
#define DAS_MATCHINGSCOPE       0x20000000
#define DAS_MATCHINGLABEL       0x10000000
#define DAS_PREC_SHIFT          20
#define DAS_SCOPE_SHIFT         16
#define DAS_PREFIX_SHIFT        8
#define DAS_ORDER_SHIFT         0
