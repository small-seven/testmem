#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "tst_test.h"
#define TCP_PRIVILEGED_PORT 463
#define TEST_USERNAME "nobody"
