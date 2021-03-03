#include "curl_setup.h"
#if defined(__INTEL_COMPILER) && defined(__unix__)
#ifdef HAVE_NETINET_IN_H
#  include <netinet/in.h>
#endif
#ifdef HAVE_ARPA_INET_H
#  include <arpa/inet.h>
#endif
#endif /* __INTEL_COMPILER && __unix__ */
#define BUILDING_WARNLESS_C 1
#include "warnless.h"
#define CURL_MASK_SCHAR  0x7F
#define CURL_MASK_UCHAR  0xFF
#if (SIZEOF_SHORT == 2)
#  define CURL_MASK_SSHORT  0x7FFF
#  define CURL_MASK_USHORT  0xFFFF
#elif (SIZEOF_SHORT == 4)
#  define CURL_MASK_SSHORT  0x7FFFFFFF
#  define CURL_MASK_USHORT  0xFFFFFFFF
#elif (SIZEOF_SHORT == 8)
#  define CURL_MASK_SSHORT  0x7FFFFFFFFFFFFFFF
#  define CURL_MASK_USHORT  0xFFFFFFFFFFFFFFFF
#else
#  error "SIZEOF_SHORT not defined"
#endif
#if (SIZEOF_INT == 2)
#  define CURL_MASK_SINT  0x7FFF
#  define CURL_MASK_UINT  0xFFFF
#elif (SIZEOF_INT == 4)
#  define CURL_MASK_SINT  0x7FFFFFFF
#  define CURL_MASK_UINT  0xFFFFFFFF
#elif (SIZEOF_INT == 8)
#  define CURL_MASK_SINT  0x7FFFFFFFFFFFFFFF
#  define CURL_MASK_UINT  0xFFFFFFFFFFFFFFFF
#elif (SIZEOF_INT == 16)
#  define CURL_MASK_SINT  0x7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
#  define CURL_MASK_UINT  0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
#else
#  error "SIZEOF_INT not defined"
#endif
#if (SIZEOF_LONG == 2)
#  define CURL_MASK_SLONG  0x7FFFL
#  define CURL_MASK_ULONG  0xFFFFUL
#elif (SIZEOF_LONG == 4)
#  define CURL_MASK_SLONG  0x7FFFFFFFL
#  define CURL_MASK_ULONG  0xFFFFFFFFUL
#elif (SIZEOF_LONG == 8)
#  define CURL_MASK_SLONG  0x7FFFFFFFFFFFFFFFL
#  define CURL_MASK_ULONG  0xFFFFFFFFFFFFFFFFUL
#elif (SIZEOF_LONG == 16)
#  define CURL_MASK_SLONG  0x7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFL
#  define CURL_MASK_ULONG  0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFUL
#else
#  error "SIZEOF_LONG not defined"
#endif
#if (SIZEOF_CURL_OFF_T == 2)
#  define CURL_MASK_SCOFFT  CURL_OFF_T_C(0x7FFF)
#  define CURL_MASK_UCOFFT  CURL_OFF_TU_C(0xFFFF)
#elif (SIZEOF_CURL_OFF_T == 4)
#  define CURL_MASK_SCOFFT  CURL_OFF_T_C(0x7FFFFFFF)
#  define CURL_MASK_UCOFFT  CURL_OFF_TU_C(0xFFFFFFFF)
#elif (SIZEOF_CURL_OFF_T == 8)
#  define CURL_MASK_SCOFFT  CURL_OFF_T_C(0x7FFFFFFFFFFFFFFF)
#  define CURL_MASK_UCOFFT  CURL_OFF_TU_C(0xFFFFFFFFFFFFFFFF)
#elif (SIZEOF_CURL_OFF_T == 16)
#  define CURL_MASK_SCOFFT  CURL_OFF_T_C(0x7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF)
#  define CURL_MASK_UCOFFT  CURL_OFF_TU_C(0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF)
#else
#  error "SIZEOF_CURL_OFF_T not defined"
#endif
#if (SIZEOF_SIZE_T == SIZEOF_SHORT)
#  define CURL_MASK_SSIZE_T  CURL_MASK_SSHORT
#  define CURL_MASK_USIZE_T  CURL_MASK_USHORT
#elif (SIZEOF_SIZE_T == SIZEOF_INT)
#  define CURL_MASK_SSIZE_T  CURL_MASK_SINT
#  define CURL_MASK_USIZE_T  CURL_MASK_UINT
#elif (SIZEOF_SIZE_T == SIZEOF_LONG)
#  define CURL_MASK_SSIZE_T  CURL_MASK_SLONG
#  define CURL_MASK_USIZE_T  CURL_MASK_ULONG
#elif (SIZEOF_SIZE_T == SIZEOF_CURL_OFF_T)
#  define CURL_MASK_SSIZE_T  CURL_MASK_SCOFFT
#  define CURL_MASK_USIZE_T  CURL_MASK_UCOFFT
#else
#  error "SIZEOF_SIZE_T not defined"
#endif
#ifdef __INTEL_COMPILER
#  pragma warning(push)
#  pragma warning(disable:810) /* conversion may lose significant bits */
#endif
#ifdef __INTEL_COMPILER
#  pragma warning(pop)
#endif
#ifdef __INTEL_COMPILER
#  pragma warning(push)
#  pragma warning(disable:810) /* conversion may lose significant bits */
#endif
#ifdef __INTEL_COMPILER
#  pragma warning(pop)
#endif
#ifdef __INTEL_COMPILER
#  pragma warning(push)
#  pragma warning(disable:810) /* conversion may lose significant bits */
#endif
#ifdef __INTEL_COMPILER
#  pragma warning(pop)
#endif
#ifdef __INTEL_COMPILER
#  pragma warning(push)
#  pragma warning(disable:810) /* conversion may lose significant bits */
#elif defined(_MSC_VER)
#  pragma warning(push)
#  pragma warning(disable:4310) /* cast truncates constant value */
#endif
#if defined(__INTEL_COMPILER) || defined(_MSC_VER)
#  pragma warning(pop)
#endif
#ifdef __INTEL_COMPILER
#  pragma warning(push)
#  pragma warning(disable:810) /* conversion may lose significant bits */
#endif
#ifdef __INTEL_COMPILER
#  pragma warning(pop)
#endif
#ifdef __INTEL_COMPILER
# pragma warning(push)
# pragma warning(disable:810) /* conversion may lose significant bits */
#endif
#if (SIZEOF_LONG < SIZEOF_SIZE_T)
#endif
#ifdef __INTEL_COMPILER
# pragma warning(pop)
#endif
#ifdef __INTEL_COMPILER
# pragma warning(push)
# pragma warning(disable:810) /* conversion may lose significant bits */
#endif
#if (SIZEOF_INT < SIZEOF_SIZE_T)
#endif
#ifdef __INTEL_COMPILER
# pragma warning(pop)
#endif
#ifdef __INTEL_COMPILER
#  pragma warning(push)
#  pragma warning(disable:810) /* conversion may lose significant bits */
#endif
#if (SIZEOF_INT < SIZEOF_LONG)
#endif
#ifdef __INTEL_COMPILER
#  pragma warning(pop)
#endif
#ifdef __INTEL_COMPILER
#  pragma warning(push)
#  pragma warning(disable:810) /* conversion may lose significant bits */
#endif
#if (SIZEOF_INT < SIZEOF_LONG)
#endif
#ifdef __INTEL_COMPILER
#  pragma warning(pop)
#endif
#ifdef __INTEL_COMPILER
#  pragma warning(push)
#  pragma warning(disable:810) /* conversion may lose significant bits */
#endif
#ifdef __INTEL_COMPILER
#  pragma warning(pop)
#endif
#ifdef __INTEL_COMPILER
#  pragma warning(push)
#  pragma warning(disable:810) /* conversion may lose significant bits */
#endif
#ifdef __INTEL_COMPILER
#  pragma warning(pop)
#endif
#ifdef __INTEL_COMPILER
#  pragma warning(push)
#  pragma warning(disable:810) /* conversion may lose significant bits */
#endif
#ifdef __INTEL_COMPILER
#  pragma warning(pop)
#endif
#ifdef __INTEL_COMPILER
#  pragma warning(push)
#  pragma warning(disable:810) /* conversion may lose significant bits */
#endif
#if (SIZEOF_INT < SIZEOF_SIZE_T)
#endif
#ifdef __INTEL_COMPILER
#  pragma warning(pop)
#endif
#ifdef __INTEL_COMPILER
#  pragma warning(push)
#  pragma warning(disable:810) /* conversion may lose significant bits */
#endif
#ifdef __INTEL_COMPILER
#  pragma warning(pop)
#endif
#ifdef __INTEL_COMPILER
#  pragma warning(push)
#  pragma warning(disable:810) /* conversion may lose significant bits */
#endif
#ifdef __INTEL_COMPILER
#  pragma warning(pop)
#endif
#ifdef USE_WINSOCK
#endif /* USE_WINSOCK */
#if defined(WIN32) || defined(_WIN32)
#endif /* WIN32 || _WIN32 */
#if defined(__INTEL_COMPILER) && defined(__unix__)
#if (__INTEL_COMPILER == 910) && defined(__i386__)
#else
#endif
#if (__INTEL_COMPILER == 910) && defined(__i386__)
#else
#endif
#endif /* __INTEL_COMPILER && __unix__ */
