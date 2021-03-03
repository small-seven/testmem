#include "test.h"
#include <limits.h>
#ifdef HAVE_LOCALE_H
#  include <locale.h> /* for setlocale() */
#endif
#include "memdebug.h"
#if (SIZEOF_CURL_OFF_T > SIZEOF_LONG)
#  define MPRNT_SUFFIX_CURL_OFF_T  LL
#else
#  define MPRNT_SUFFIX_CURL_OFF_T  L
#endif
#ifdef CURL_ISOCPP
#  define MPRNT_OFF_T_C_HELPER2(Val,Suffix) Val ## Suffix
#else
#  define MPRNT_OFF_T_C_HELPER2(Val,Suffix) Val/**/Suffix
#endif
#define MPRNT_OFF_T_C_HELPER1(Val,Suffix) MPRNT_OFF_T_C_HELPER2(Val,Suffix)
#define MPRNT_OFF_T_C(Val)  MPRNT_OFF_T_C_HELPER1(Val,MPRNT_SUFFIX_CURL_OFF_T)
#define BUFSZ    256
#define USHORT_TESTS_ARRSZ 1 + 100
#define SSHORT_TESTS_ARRSZ 1 + 100
#define UINT_TESTS_ARRSZ   1 + 100
#define SINT_TESTS_ARRSZ   1 + 100
#define ULONG_TESTS_ARRSZ  1 + 100
#define SLONG_TESTS_ARRSZ  1 + 100
#define COFFT_TESTS_ARRSZ  1 + 100
#if (SIZEOF_SHORT == 1)
#elif (SIZEOF_SHORT == 2)
#elif (SIZEOF_SHORT == 4)
#endif
#if (SIZEOF_SHORT == 1)
#elif (SIZEOF_SHORT == 2)
#elif (SIZEOF_SHORT == 4)
#endif
#if (SIZEOF_INT == 2)
#elif (SIZEOF_INT == 4)
#elif (SIZEOF_INT == 8)
#endif
#if (SIZEOF_INT == 2)
#elif (SIZEOF_INT == 4)
#elif (SIZEOF_INT == 8)
#endif
#if (SIZEOF_LONG == 2)
#elif (SIZEOF_LONG == 4)
#elif (SIZEOF_LONG == 8)
#endif
#if (SIZEOF_LONG == 2)
#elif (SIZEOF_LONG == 4)
#elif (SIZEOF_LONG == 8)
#endif
#if (SIZEOF_CURL_OFF_T == 2)
#elif (SIZEOF_CURL_OFF_T == 4)
#elif (SIZEOF_CURL_OFF_T == 8)
#endif
#define string_check(x,y) _string_check(__LINE__, x, y)
#define strlen_check(x,y) _strlen_check(__LINE__, x, y)
#define MAXIMIZE -1.7976931348623157081452E+308
#ifdef HAVE_SETLOCALE
#endif
