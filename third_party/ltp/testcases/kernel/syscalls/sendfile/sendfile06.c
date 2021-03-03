#include <inttypes.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/sendfile.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <sys/mman.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include "test.h"
#include "safe_macros.h"
#define IN_FILE		"infile"
#define OUT_FILE	"outfile"
#ifdef UCLINUX
#endif
#ifdef UCLINUX
#else
#endif
#ifdef UCLINUX
#endif
