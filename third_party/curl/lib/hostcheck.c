#include "curl_setup.h"
#if defined(USE_OPENSSL)                                \
#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif
#ifdef HAVE_NETINET_IN6_H
#include <netinet/in6.h>
#endif
#include "hostcheck.h"
#include "strcase.h"
#include "inet_pton.h"
#include "curl_memory.h"
#include "memdebug.h"
#ifdef ENABLE_IPV6
#endif
#ifdef ENABLE_IPV6
#endif
#endif /* OPENSSL, GSKIT or schannel+wince */
