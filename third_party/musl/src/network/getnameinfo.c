#include <netdb.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <ctype.h>
#include <resolv.h>
#include <unsupported_api.h>
#include "lookup.h"
#include "stdio_impl.h"
#define PTR_MAX (64 + sizeof ".in-addr.arpa")
#define RR_PTR 12
