#include "curl_setup.h"
#ifdef HAVE_NETINET_IN_H
#  include <netinet/in.h>
#endif
#ifdef HAVE_ARPA_INET_H
#  include <arpa/inet.h>
#endif
#ifdef HAVE_NET_IF_H
#  include <net/if.h>
#endif
#ifdef HAVE_SYS_IOCTL_H
#  include <sys/ioctl.h>
#endif
#ifdef HAVE_NETDB_H
#  include <netdb.h>
#endif
#ifdef HAVE_SYS_SOCKIO_H
#  include <sys/sockio.h>
#endif
#ifdef HAVE_IFADDRS_H
#  include <ifaddrs.h>
#endif
#ifdef HAVE_STROPTS_H
#  include <stropts.h>
#endif
#ifdef __VMS
#  include <inet.h>
#endif
#include "inet_ntop.h"
#include "strcase.h"
#include "if2ip.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#ifndef ENABLE_IPV6
#else
#endif
#if defined(HAVE_GETIFADDRS)
#ifndef ENABLE_IPV6
#endif
#if !defined(HAVE_SOCKADDR_IN6_SIN6_SCOPE_ID) || \
#endif
#ifdef ENABLE_IPV6
#ifdef HAVE_SOCKADDR_IN6_SIN6_SCOPE_ID
#endif
#ifdef HAVE_SOCKADDR_IN6_SIN6_SCOPE_ID
#endif
#endif
#elif defined(HAVE_IOCTL_SIOCGIFADDR)
#else
#endif
