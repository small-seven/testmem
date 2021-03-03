#include "e_os.h"
#include "crypto/cryptlib.h"
#include <openssl/safestack.h>
#if     defined(__i386)   || defined(__i386__)   || defined(_M_IX86) || \
# if defined(OPENSSL_CPUID_OBJ) && !defined(OPENSSL_NO_ASM) && !defined(I386_ONLY)
#  ifdef _WIN32
typedef WCHAR variant_char;

static variant_char *ossl_getenv(const char *name)
{
    /*
     * Since we pull only one environment variable, it's simpler to
     * to just ignore |name| and use equivalent wide-char L-literal.
     * As well as to ignore excessively long values...
     */
    static WCHAR value[48];
    DWORD len = GetEnvironmentVariableW(L"OPENSSL_ia32cap", value, 48);

    return (len > 0 && len < 48) ? value : NULL;
}
#  else
typedef char variant_char;
#   define ossl_getenv getenv
#  endif

#  include "crypto/ctype.h"

static int todigit(variant_char c)
{
    if (ossl_isdigit(c))
        return c - '0';
    else if (ossl_isxdigit(c))
        return ossl_tolower(c) - 'a' + 10;

    /* return largest base value to make caller terminate the loop */
    return 16;
}
#  define OPENSSL_CPUID_SETUP
typedef uint64_t IA32CAP;

void OPENSSL_cpuid_setup(void)
{
    static int trigger = 0;
    IA32CAP OPENSSL_ia32_cpuid(unsigned int *);
    IA32CAP vec;
    const variant_char *env;

    if (trigger)
        return;

    trigger = 1;
    if ((env = ossl_getenv("OPENSSL_ia32cap")) != NULL) {
        int off = (env[0] == '~') ? 1 : 0;

        vec = ossl_strtouint64(env + off);

        if (off) {
            IA32CAP mask = vec;
            vec = OPENSSL_ia32_cpuid(OPENSSL_ia32cap_P) & ~mask;
            if (mask & (1<<24)) {
                /*
                 * User disables FXSR bit, mask even other capabilities
                 * that operate exclusively on XMM, so we don't have to
                 * double-check all the time. We mask PCLMULQDQ, AMD XOP,
                 * AES-NI and AVX. Formally speaking we don't have to
                 * do it in x86_64 case, but we can safely assume that
                 * x86_64 users won't actually flip this flag.
                 */
                vec &= ~((IA32CAP)(1<<1|1<<11|1<<25|1<<28) << 32);
            }
# else
# endif
#endif
#if !defined(OPENSSL_CPUID_SETUP) && !defined(OPENSSL_CPUID_OBJ)
#endif
#if defined(_WIN32)
# include <tchar.h>
# include <signal.h>
# ifdef __WATCOMC__
#  if defined(_UNICODE) || defined(__UNICODE__)
#   define _vsntprintf _vsnwprintf
#  else
#   define _vsntprintf _vsnprintf
#  endif
# endif
# ifdef _MSC_VER
#  define alloca _alloca
# endif
# if defined(_WIN32_WINNT) && _WIN32_WINNT>=0x0333
#  ifdef OPENSSL_SYS_WIN_CORE
#  else
#   if 1
#   else
#   endif
#  endif
# else
# endif
# ifdef STD_ERROR_HANDLE
# endif
# if defined(_WIN32_WINNT) && _WIN32_WINNT>=0x0333
#  ifdef OPENSSL_SYS_WIN_CORE
#   if !defined(NDEBUG)
#   endif
#  else
#   if !defined(NDEBUG)
#   endif
#  endif
# else
# endif
#else
#ifndef OPENSSL_NO_STDIO
#endif
#endif
#if !defined(_WIN32)
#else
# if !defined(_WIN32_WCE)
# endif
#endif
#if !defined(OPENSSL_CPUID_OBJ)
# undef CRYPTO_memcmp
int CRYPTO_memcmp(const void * in_a, const void * in_b, size_t len)
{
    size_t i;
    const volatile unsigned char *a = in_a;
    const volatile unsigned char *b = in_b;
    unsigned char x = 0;

    for (i = 0; i < len; i++)
        x |= a[i] ^ b[i];

    return x;
}
#endif
