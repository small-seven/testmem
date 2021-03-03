#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/uio.h>
#include <netinet/in.h>
#include <sys/errno.h>
#include <errno.h>
#include <netinet/sctp.h>
#include <sctputil.h>
#define SMALL_RCVBUF 3000
#define SMALL_MAXSEG 500
#define RWND_SLOP 100
#if TEST_V6
#else
#endif /* TEST_V6 */
#if 0
#endif
