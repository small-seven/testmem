#include "includes.h"
#include <fcntl.h>
#include "common.h"
#include "eloop.h"
#include "httpread.h"
#include "http_server.h"
#define HTTP_SERVER_TIMEOUT 30
#define HTTP_SERVER_MAX_REQ_LEN 8000
#define HTTP_SERVER_MAX_CONNECTIONS 10
