#include "stdio.h"
#include <stdarg.h>
#include <securec.h>
#include "fcntl.h"
#include "unistd.h"
#include <log.h>
typedef int SecInt32;
typedef unsigned int SecUnsignedInt32;
typedef long long SecInt64;
typedef unsigned long long SecUnsignedInt64;

#define SECUREC_BUFFER_SIZE 256

#define SECUREC_MAX_PRECISION SECUREC_BUFFER_SIZE
/* max. # bytes in multibyte char  ,see MB_LEN_MAX */
#define SECUREC_MB_LEN 16

/* state definitions */
#define SECUREC_FLAG_SIGN 0x00001U
#define SECUREC_FLAG_SIGN_SPACE 0x00002U
#define SECUREC_FLAG_LEFT 0x00004U
#define SECUREC_FLAG_LEADZERO 0x00008U
#define SECUREC_FLAG_LONG 0x00010U
#define SECUREC_FLAG_SHORT 0x00020U
#define SECUREC_FLAG_SIGNED 0x00040U
#define SECUREC_FLAG_ALTERNATE 0x00080U
#define SECUREC_FLAG_NEGATIVE 0x00100U
#define SECUREC_FLAG_FORCE_OCTAL 0x00200U
#define SECUREC_FLAG_LONG_DOUBLE 0x00400U
#define SECUREC_FLAG_WIDECHAR 0x00800U
#define SECUREC_FLAG_LONGLONG 0x01000U
#define SECUREC_FLAG_CHAR 0x02000U
#define SECUREC_FLAG_POINTER 0x04000U
#define SECUREC_FLAG_I64 0x08000U
#define SECUREC_FLAG_PTRDIFF 0x10000U
#define SECUREC_FLAG_SIZE 0x20000U
#ifdef SECUREC_COMPATIBLE_LINUX_FORMAT
#define SECUREC_FLAG_INTMAX 0x40000U
#endif


typedef enum {
    STAT_NORMAL,
    STAT_PERCENT,
    STAT_FLAG,
    STAT_WIDTH,
    STAT_DOT,
    STAT_PRECIS,
    STAT_SIZE,
    STAT_TYPE,
    STAT_INVALID
} SecFmtState;
#define SECUREC_PRINTF_TRUNCATE (-2)
typedef struct {
    int count;
    char *cur;
} SecPrintfStream;
#define SECUREC_ERROR_INVALID_PARAMTER(msg) printf("%s invalid argument\n", msg)
#define SECUREC_ERROR_INVALID_RANGE(msg) printf("%s invalid dest buffer size\n", msg)
#define SECUREC_ERROR_BUFFER_OVERLAP(msg) printf("%s buffer overlap\n", msg)
#define LOG_BUF_SIZE (1024)
#define MAX_DOMAIN_TAG_SIZE 64
#define IOV_SIZE (3)
#define HILOG_IOV_SIZE 4
#define HITRACE_BUF_SIZE 128
#define MAX_INIT_RETRIES (500)
#define DOMAIN_MIN 0x0D000000
#define DOMAIN_MAX 0x0E000000
#define SECUREC_FLOAT_BUFSIZE (309 + 40)     /* max float point value */
#define SECUREC_FLOAT_BUFSIZE_LB (4932 + 40) /* max long double value */
#define SECUREC_INT_MAX 2147483647
#define SECUREC_MUL10(x) ((((x) << 2) + (x)) << 1)
#define SECUREC_INT_MAX_DIV_TEN 21474836
#define SECUREC_MUL10_ADD_BEYOND_MAX(val) (((val) > SECUREC_INT_MAX_DIV_TEN))
#ifdef SECUREC_STACK_SIZE_LESS_THAN_1K
#define SECUREC_FMT_STR_LEN (8)
#else
#define SECUREC_FMT_STR_LEN (16)
#endif
#ifndef SECUREC_PUTC
#define SECUREC_PUTC(_c, _stream) ((--(_stream)->count >= 0) ? (*(_stream)->cur++ = (char)(_c)) : EOF)
#endif
#ifndef SECUREC_PUTC_ZERO
#define SECUREC_PUTC_ZERO(_stream) ((--(_stream)->count >= 0) ? ((*(_stream)->cur++ = (char)('\0'))) : EOF)
#endif
#ifndef SECUREC_MALLOC
#define SECUREC_MALLOC(x) malloc((size_t)(x))
#endif
#ifndef SECUREC_FREE
#define SECUREC_FREE(x) free((void *)(x))
#endif
typedef char SecChar;
#define SECUREC_CHAR(x) x
/* put a char to output */
#define SECUREC_PUTC(_c, _stream) ((--(_stream)->count >= 0) ? (*(_stream)->cur++ = (char)(_c)) : EOF)
/* to clear e835 */

#define SECUREC_PUTC_ZERO(_stream) ((--(_stream)->count >= 0) ? ((*(_stream)->cur++ = (char)('\0'))) : EOF)

int SecPutWcharStrEndingZero(SecPrintfStream *str, int zeroNum)
{
    int succeed = 0;
    int i;

    for (i = 0; i < zeroNum && (SECUREC_PUTC_ZERO(str) != EOF); ++i) {
    }
#define SECUREC_WRITE_MULTI_CHAR SecWriteMultiChar
#define SECUREC_WRITE_STRING SecWriteString
typedef struct {
    unsigned int flags;
    int fldWidth;
    int precision;
    int bufferIsWide; /* flag for buffer contains wide chars */
    int dynWidth;     /* %*   1 width from variable parameter ;0 not */
    int dynPrecision; /* %.*  1 precision from variable parameter ;0 not */
} SecFormatAttr;
typedef union {
    char *str; /* not a null terminated  string */
    wchar_t *wStr;
} SecFormatBuf;
typedef union {
    char str[SECUREC_BUFFER_SIZE + 1];
#ifdef SECUREC_FOR_WCHAR
    wchar_t wStr[SECUREC_BUFFER_SIZE + 1];
#endif
} SecBuffer;
#ifdef SECUREC_COMPATIBLE_LINUX_FORMAT
#endif
#define SECUREC_WHILE_ZERO while (0)
#define SECUREC_SPECIAL(_val, Base) case Base:                                      \
#define SECUREC_SAFE_WRITE_PREFIX(src, txtLen, _stream, outChars) \
#define MOBILE_NUMBER_LENGTH 12
#define SECUREC_SAFE_WRITE_STR(src, txtLen, _stream, outChars)                                    \
#define SECUREC_SAFE_WRITE_CHAR(_ch, _stream, outChars) do {                                                     \
#define SECUREC_SAFE_PADDING(padChar, padLen, _stream, outChars)     \
#define SECUREC_IS_REST_BUF_ENOUGH(needLen) ((int)(stream->count - (int)needLen * (int)(sizeof(SecChar))) >= 0)
#define SECUREC_FMT_STATE_OFFSET 256
#ifdef SECUREC_FOR_WCHAR
#define SECUREC_FMT_TYPE(c, fmtTable) \
#define SECUREC_DECODE_STATE(c, fmtTable, laststate)                                               \
#else
#define SECUREC_DECODE_STATE(c, fmtTable, laststate)                                             \
#endif
#ifdef SECUREC_COMPATIBLE_LINUX_FORMAT
#endif
#ifdef SECUREC_COMPATIBLE_LINUX_FORMAT
#endif
#ifdef SECUREC_ON_64BITS
#endif
#if (defined(SECUREC_COMPATIBLE_LINUX_FORMAT)) && !(defined(__hpux)) && !(defined(SECUREC_ON_SOLARIS))
#endif
#ifdef SECUREC_FOR_WCHAR
#else
#endif
#if (defined(SECUREC_COMPATIBLE_LINUX_FORMAT)) && (!defined(SECUREC_ON_UNIX))
#endif
#ifdef SECUREC_FOR_WCHAR
#if defined(SECUREC_COMPATIBLE_LINUX_FORMAT)
#endif
#else /* SECUREC_FOR_WCHAR */
#endif /* SECUREC_FOR_WCHAR */
#define PUBLIC_FLAG_LEN (8)
#define PRIVATE_FLAG_LEN (9)
#define PUBLIC_FLAG "{public}"
#define PRIVATE_FLAG "{private}"
#define bool _Bool
#ifdef SECUREC_FOR_WCHAR
#else
#endif
#ifdef SECUREC_FOR_WCHAR
#else
#endif
#ifndef SECUREC_FOR_WCHAR
#else
#endif
#ifdef SECUREC_COMPATIBLE_LINUX_FORMAT
#endif
#if defined(SECUREC_COMPATIBLE_WIN_FORMAT)
#else
#endif
#ifdef SECUREC_ON_64BITS
#else
#endif
#if (defined(SECUREC_COMPATIBLE_LINUX_FORMAT) || defined(SECUREC_VXWORKS_PLATFORM)) && (!defined(SECUREC_ON_UNIX))
#if defined(SECUREC_VXWORKS_PLATFORM)
#else
#endif
#else
#if defined(_AIX) || defined(SECUREC_ON_SOLARIS)
#else
#endif
#endif
#if defined(SECUREC_ON_UNIX)
#endif
#if (defined(SECUREC_COMPATIBLE_LINUX_FORMAT) || defined(SECUREC_VXWORKS_PLATFORM))
#endif
#if defined(_AIX) || defined(SECUREC_ON_SOLARIS)
#else
#endif
#if defined(SECUREC_VXWORKS_VERSION_5_4) && !defined(SECUREC_ON_64BITS)
#endif
#ifdef SECUREC_ON_64BITS
#endif /* SECUREC_ON_64BITS */
#ifdef SECUREC_COMPATIBLE_LINUX_FORMAT
#endif
#ifdef SECUREC_COMPATIBLE_LINUX_FORMAT
#endif
#ifdef SECUREC_ON_64BITS
#if !defined(SECUREC_COMPATIBLE_WIN_FORMAT) /* on window 64 system sizeof long is 32bit */
#endif
#endif
#if defined(SECUREC_COMPATIBLE_WIN_FORMAT)
#else
#endif
#if !(defined(SECUREC_VXWORKS_PLATFORM) || defined(__hpux))
#else
#endif
#ifdef SECUREC_ON_64BITS
#else /* for 32 bits system */
#ifdef _AIX
#else
#endif
#if defined(SECUREC_VXWORKS_VERSION_5_4)
#else
#endif
#endif
#if defined(SECUREC_COMPATIBLE_LINUX_FORMAT) && (!defined(SECUREC_ON_UNIX))
#endif
#ifndef SECUREC_FOR_WCHAR
#else /* SECUREC_FOR_WCHAR */
#endif /* SECUREC_FOR_WCHAR */
#ifdef SECUREC_COMPATIBLE_WIN_FORMAT
#endif
#define HILOG_DRIVER "/dev/hilog"
#ifdef LOSCFG_BASE_CORE_HILOG
#else
#endif
#ifdef OHOS_RELEASE
#endif
#ifdef LOSCFG_BASE_CORE_HILOG
#else
#endif
