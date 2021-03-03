#define _GNU_SOURCE
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <inttypes.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "lookup.h"
#include <unsupported_api.h>
#define ALIGN (sizeof(struct { char a; char *b; }) - sizeof(char *))
