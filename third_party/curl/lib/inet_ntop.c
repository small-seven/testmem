#include "curl_setup.h"
#ifndef HAVE_INET_NTOP
#ifdef HAVE_SYS_PARAM_H
#include <sys/param.h>
#endif
#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif
#ifdef HAVE_ARPA_INET_H
#include <arpa/inet.h>
#endif
#include "inet_ntop.h"
#include "curl_printf.h"
#define IN6ADDRSZ       16
#define INADDRSZ         4
#define INT16SZ          2
#ifdef ENABLE_IPV6
#endif  /* ENABLE_IPV6 */
#ifdef ENABLE_IPV6
#endif
#endif  /* HAVE_INET_NTOP */
