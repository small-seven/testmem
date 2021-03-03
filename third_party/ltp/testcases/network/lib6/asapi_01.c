#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <libgen.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "test.h"
#include "safe_macros.h"
#define PTCOUNT		ARRAY_SIZE(ptab)
#define READ_TIMEOUT	5
#ifndef IN6_ARE_ADDR_EQUAL
#else /* IN6_ARE_ADDR_EQUAL */
#endif /* IN6_ARE_ADDR_EQUAL */
#define	NH_TEST	0x9f
#define CSCOUNT	ARRAY_SIZE(cstab)
