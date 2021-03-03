#include "curl_setup.h"
#ifdef HAVE_SYS_IOCTL_H
#include <sys/ioctl.h>
#endif
#ifdef HAVE_FCNTL_H
#include <fcntl.h>
#endif
#if (defined(HAVE_IOCTL_FIONBIO) && defined(NETWARE))
#include <sys/filio.h>
#endif
#ifdef __VMS
#include <in.h>
#include <inet.h>
#endif
#include "nonblock.h"
#if defined(USE_BLOCKING_SOCKETS)
#elif defined(HAVE_FCNTL_O_NONBLOCK)
#elif defined(HAVE_IOCTL_FIONBIO)
#elif defined(HAVE_IOCTLSOCKET_FIONBIO)
#elif defined(HAVE_IOCTLSOCKET_CAMEL_FIONBIO)
#elif defined(HAVE_SETSOCKOPT_SO_NONBLOCK)
#else
#  error "no non-blocking method was found/used/set"
#endif
