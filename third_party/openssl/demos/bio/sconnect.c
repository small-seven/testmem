#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <openssl/err.h>
#include <openssl/ssl.h>
#define HOSTPORT "localhost:4433"
#define CAFILE "root.pem"
#ifdef WATT32
#endif
