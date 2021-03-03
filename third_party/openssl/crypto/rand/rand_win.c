#include "internal/cryptlib.h"
#include <openssl/rand.h>
#include "rand_local.h"
#include "crypto/rand.h"
#if defined(OPENSSL_SYS_WINDOWS) || defined(OPENSSL_SYS_WIN32)
# ifndef OPENSSL_RAND_SEED_OS
#  error "Unsupported seeding method configured; must be os"
# endif
# include <windows.h>
# if defined(_MSC_VER) && _MSC_VER > 1500 /* 1500 = Visual Studio 2008 */ \
#  define USE_BCRYPTGENRANDOM
# endif
# ifdef USE_BCRYPTGENRANDOM
#  include <bcrypt.h>
#  pragma comment(lib, "bcrypt.lib")
#  ifndef STATUS_SUCCESS
#   define STATUS_SUCCESS ((NTSTATUS)0x00000000L)
#  endif
# else
#  include <wincrypt.h>
#  define PROV_INTEL_SEC 22
#  define INTEL_DEF_PROV L"Intel Hardware Cryptographic Service Provider"
# endif
# ifndef USE_BCRYPTGENRANDOM
# endif
# ifdef OPENSSL_RAND_SEED_RDTSC
# endif
# ifdef OPENSSL_RAND_SEED_RDCPU
# endif
# ifdef USE_BCRYPTGENRANDOM
# else
# endif
# if OPENSSL_API_COMPAT < 0x10100000L
# endif
#endif
