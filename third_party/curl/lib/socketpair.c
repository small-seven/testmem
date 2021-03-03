#include "curl_setup.h"
#include "socketpair.h"
#ifndef HAVE_SOCKETPAIR
#ifdef WIN32
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <io.h>
#else
#ifdef HAVE_NETDB_H
#include <netdb.h>
#endif
#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h> /* IPPROTO_TCP */
#endif
#ifdef HAVE_ARPA_INET_H
#include <arpa/inet.h>
#endif
#ifndef INADDR_LOOPBACK
#define INADDR_LOOPBACK 0x7f000001
#endif /* !INADDR_LOOPBACK */
#endif /* !WIN32 */
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#endif /* ! HAVE_SOCKETPAIR */
