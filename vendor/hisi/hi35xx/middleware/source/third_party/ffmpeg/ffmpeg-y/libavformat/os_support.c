#define _DEFAULT_SOURCE
#define _SVID_SOURCE
#include "config.h"
#include "avformat.h"
#include "os_support.h"
#if CONFIG_NETWORK
#include <fcntl.h>
#if !HAVE_POLL_H
#if HAVE_SYS_TIME_H
#include <sys/time.h>
#endif /* HAVE_SYS_TIME_H */
#if HAVE_WINSOCK2_H
#include <winsock2.h>
#elif HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif /* HAVE_WINSOCK2_H */
#endif /* !HAVE_POLL_H */
#include "network.h"
#if !HAVE_GETADDRINFO
#if !HAVE_INET_ATON
#include <stdlib.h>
#endif /* !HAVE_INET_ATON */
#endif /* !HAVE_GETADDRINFO */
#if !HAVE_GETADDRINFO || HAVE_WINSOCK2_H
#if EAI_NODATA != EAI_NONAME
#endif /* EAI_NODATA != EAI_NONAME */
#endif /* !HAVE_GETADDRINFO || HAVE_WINSOCK2_H */
#if HAVE_WINSOCK2_H
#else
#endif /* HAVE_WINSOCK2_H */
#if !HAVE_POLL_H
#if HAVE_WINSOCK2_H
#endif /* HAVE_WINSOCK2_H */
#if !HAVE_WINSOCK2_H
#endif /* !HAVE_WINSOCK2_H */
#endif /* !HAVE_POLL_H */
#endif /* CONFIG_NETWORK */
