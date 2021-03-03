#include "server_setup.h"
#ifdef HAVE_SIGNAL_H
#include <signal.h>
#endif
#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif
#ifdef _XOPEN_SOURCE_EXTENDED
#include <arpa/inet.h>
#endif
#ifdef HAVE_NETDB_H
#include <netdb.h>
#endif
#define ENABLE_CURLX_PRINTF
#include "curlx.h" /* from the private lib dir */
#include "util.h"
#include "memdebug.h"
#if defined(CURLRES_IPV6)
#else
#endif
#if defined(CURLRES_IPV6)
#endif
#ifdef WIN32
#endif
#if defined(CURLRES_IPV6)
#else
#endif
