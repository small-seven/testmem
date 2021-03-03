#include <stdio.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include "posixtest.h"
#define NAMESIZE 50
#define MSGSTR "01234567890123456789"
#define MSGSIZE 10		// < strlen(MSGSTR)
