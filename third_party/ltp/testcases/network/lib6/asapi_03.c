#include "config.h"
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <libgen.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netinet/ip6.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <net/if.h>
#include <sys/ioctl.h>
#ifdef HAVE_IFADDRS_H
#include <ifaddrs.h>
#endif
#include <arpa/inet.h>
#include "test.h"
#include "safe_macros.h"
#define READ_TIMEOUT	5	/* secs */
#define NH_TEST	0x9f
#ifndef IPV6_RECVPKTINFO
#define IPV6_RECVPKTINFO	-1
#endif
#ifndef IPV6_RECVHOPLIMIT
#define IPV6_RECVHOPLIMIT	-1
#endif
#ifndef IPV6_RECVRTHDR
#define IPV6_RECVRTHDR		-1
#endif
#ifndef IPV6_RECVHOPOPTS
#define IPV6_RECVHOPOPTS	-1
#endif
#ifndef IPV6_RECVDSTOPTS
#define IPV6_RECVDSTOPTS	-1
#endif
#ifndef IPV6_RECVTCLASS
#define IPV6_RECVTCLASS		-1
#endif
#ifndef IPV6_TCLASS
#define IPV6_TCLASS		-1
#endif
#ifndef IPV6_2292PKTINFO
#define	IPV6_2292PKTINFO	-1
#endif
#ifndef IPV6_2292HOPLIMIT
#define	IPV6_2292HOPLIMIT	-1
#endif
#ifndef IPV6_2292RTHDR
#define	IPV6_2292RTHDR		-1
#endif
#ifndef IPV6_2292HOPOPTS
#define	IPV6_2292HOPOPTS	-1
#endif
#ifndef IPV6_2292DSTOPTS
#define	IPV6_2292DSTOPTS	-1
#endif
#define IN6_LOOP	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }
#define IN6_ANY		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
#define SOCOUNT	ARRAY_SIZE(sotab)
#define CMCOUNT	ARRAY_SIZE(cmtab)
