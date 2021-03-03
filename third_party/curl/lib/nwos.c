#include "curl_setup.h"
#ifdef NETWARE /* Novell NetWare */
#ifdef __NOVELL_LIBC__
#else /* __NOVELL_LIBC__ */
#include <nwnspace.h>
#include <nwthread.h>
#include <nwadv.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#endif /* __NOVELL_LIBC__ */
#endif /* NETWARE */
