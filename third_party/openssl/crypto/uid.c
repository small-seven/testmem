#include <openssl/crypto.h>
#include <openssl/opensslconf.h>
#if defined(OPENSSL_SYS_WIN32) || defined(OPENSSL_SYS_VXWORKS) || defined(OPENSSL_SYS_UEFI)
#elif defined(__OpenBSD__) || (defined(__FreeBSD__) && __FreeBSD__ > 2) || defined(__DragonFly__)
# include OPENSSL_UNISTD
#else
# include OPENSSL_UNISTD
# include <sys/types.h>
# if defined(__GLIBC__) && defined(__GLIBC_PREREQ)
#  if __GLIBC_PREREQ(2, 16)
#   include <sys/auxv.h>
#   define OSSL_IMPLEMENT_GETAUXVAL
#  endif
# endif
# ifdef OSSL_IMPLEMENT_GETAUXVAL
# else
# endif
#endif
