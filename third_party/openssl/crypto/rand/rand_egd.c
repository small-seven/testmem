#include <openssl/opensslconf.h>
#ifdef OPENSSL_NO_EGD
#else
# include <openssl/crypto.h>
# include <openssl/e_os2.h>
# include <openssl/rand.h>
# if defined(OPENSSL_SYS_WIN32) || defined(OPENSSL_SYS_VMS) || defined(OPENSSL_SYS_MSDOS) || defined(OPENSSL_SYS_VXWORKS) || defined(OPENSSL_SYS_VOS) || defined(OPENSSL_SYS_UEFI)
# else
#  include OPENSSL_UNISTD
#  include <stddef.h>
#  include <sys/types.h>
#  include <sys/socket.h>
#  ifndef NO_SYS_UN_H
#   ifdef OPENSSL_SYS_VXWORKS
#    include <streams/un.h>
#   else
#    include <sys/un.h>
#   endif
#  else
#  endif                         /* NO_SYS_UN_H */
#  include <string.h>
#  include <errno.h>
#  ifdef EISCONN
#  endif
#  ifdef EINTR
#  endif
#  ifdef EAGAIN
#  endif
#  ifdef EINPROGRESS
#  endif
#  ifdef EALREADY
#  endif
# endif
#endif
