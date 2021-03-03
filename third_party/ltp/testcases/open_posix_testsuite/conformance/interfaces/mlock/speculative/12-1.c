#define _GNU_SOURCE 1		/* XXX: Read baloney below about CAP_* */
#include <sys/mman.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <pwd.h>
#include <string.h>
#include <sys/resource.h>
#include "posixtest.h"
#define BUFSIZE 8
