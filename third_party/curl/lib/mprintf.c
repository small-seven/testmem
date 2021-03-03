#include "curl_setup.h"
#include <curl/mprintf.h>
#include "curl_memory.h"
#include "memdebug.h"
#ifdef HAVE_LONGLONG
#  define LONG_LONG_TYPE long long
#  define HAVE_LONG_LONG_TYPE
#else
#  if defined(_MSC_VER) && (_MSC_VER >= 900) && (_INTEGRAL_MAX_BITS >= 64)
#    define LONG_LONG_TYPE __int64
#    define HAVE_LONG_LONG_TYPE
#  else
#    undef LONG_LONG_TYPE
#    undef HAVE_LONG_LONG_TYPE
#  endif
#endif
#if (defined(__BORLANDC__) && (__BORLANDC__ >= 0x520)) || \
#  define MP_HAVE_INT_EXTENSIONS
#endif
#ifdef HAVE_LONG_LONG_TYPE
#  define mp_intmax_t LONG_LONG_TYPE
#  define mp_uintmax_t unsigned LONG_LONG_TYPE
#else
#  define mp_intmax_t long
#  define mp_uintmax_t unsigned long
#endif
#define BUFFSIZE 326 /* buffer for long-to-str and float-to-str calcs, should
#define MAX_PARAMETERS 128 /* lame static limit */
#ifdef __AMIGA__
# undef FORMAT_INT
#endif
#define OUTCHAR(x) \
typedef enum {
  FORMAT_UNKNOWN = 0,
  FORMAT_STRING,
  FORMAT_PTR,
  FORMAT_INT,
  FORMAT_INTPTR,
  FORMAT_LONG,
  FORMAT_LONGLONG,
  FORMAT_DOUBLE,
  FORMAT_LONGDOUBLE,
  FORMAT_WIDTH /* For internal use */
} FormatType;
typedef struct {
  FormatType type;
  int flags;
  long width;     /* width OR width parameter number */
  long precision; /* precision OR precision parameter number */
  union {
    char *str;
    void *ptr;
    union {
      mp_intmax_t as_signed;
      mp_uintmax_t as_unsigned;
    } num;
#if defined(MP_HAVE_INT_EXTENSIONS)
#endif
#if defined(MP_HAVE_INT_EXTENSIONS)
#endif
#if defined(MP_HAVE_INT_EXTENSIONS)
#endif
#if defined(MP_HAVE_INT_EXTENSIONS)
#if (SIZEOF_CURL_OFF_T > SIZEOF_LONG)
#else
#endif
#endif
#if (SIZEOF_SIZE_T > SIZEOF_LONG)
#else
#endif
#if (SIZEOF_CURL_OFF_T > SIZEOF_LONG)
#else
#endif
#ifdef HAVE_LONG_LONG_TYPE
#endif
#ifdef HAVE_LONG_LONG_TYPE
#endif
