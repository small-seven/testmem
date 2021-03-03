#include "curl_setup.h"
#if defined(WIN32)
#include <curl/curl.h>
#include "system_win32.h"
#include "curl_sspi.h"
#include "warnless.h"
#include "curl_memory.h"
#include "memdebug.h"
#ifdef USE_WINSOCK
#if defined(ENABLE_IPV6) && (USE_WINSOCK < 2)
#error IPV6_requires_winsock2
#endif
#ifdef USE_WINDOWS_SSPI
#endif
#ifdef USE_WINDOWS_SSPI
#endif
#ifdef USE_WINSOCK
#endif
#if !defined(LOAD_WITH_ALTERED_SEARCH_PATH)
#define LOAD_WITH_ALTERED_SEARCH_PATH  0x00000008
#endif
#if !defined(LOAD_LIBRARY_SEARCH_SYSTEM32)
#define LOAD_LIBRARY_SEARCH_SYSTEM32   0x00000800
#endif
/* We use our own typedef here since some headers might lack these */
typedef HMODULE (APIENTRY *LOADLIBRARYEX_FN)(LPCTSTR, HANDLE, DWORD);

/* See function definitions in winbase.h */
#ifdef UNICODE
#  ifdef _WIN32_WCE
#    define LOADLIBARYEX  L"LoadLibraryExW"
#  else
#    define LOADLIBARYEX  "LoadLibraryExW"
#  endif
#else
#  define LOADLIBARYEX    "LoadLibraryExA"
#endif

/*
 * Curl_verify_windows_version()
 *
 * This is used to verify if we are running on a specific windows version.
 *
 * Parameters:
 *
 * majorVersion [in] - The major version number.
 * minorVersion [in] - The minor version number.
 * platform     [in] - The optional platform identifier.
 * condition    [in] - The test condition used to specifier whether we are
 *                     checking a version less then, equal to or greater than
 *                     what is specified in the major and minor version
 *                     numbers.
 *
 * Returns TRUE if matched; otherwise FALSE.
 */
bool Curl_verify_windows_version(const unsigned int majorVersion,
                                 const unsigned int minorVersion,
                                 const PlatformIdentifier platform,
                                 const VersionCondition condition)
{
  bool matched = FALSE;

#if defined(CURL_WINDOWS_APP)
  /* We have no way to determine the Windows version from Windows apps,
     so let's assume we're running on the target Windows version. */
  const WORD fullVersion = MAKEWORD(minorVersion, majorVersion);
  const WORD targetVersion = (WORD)_WIN32_WINNT;

  switch(condition) {
  case VERSION_LESS_THAN:
    matched = targetVersion < fullVersion;
    break;

  case VERSION_LESS_THAN_EQUAL:
    matched = targetVersion <= fullVersion;
    break;

  case VERSION_EQUAL:
    matched = targetVersion == fullVersion;
    break;

  case VERSION_GREATER_THAN_EQUAL:
    matched = targetVersion >= fullVersion;
    break;

  case VERSION_GREATER_THAN:
    matched = targetVersion > fullVersion;
    break;
  }
#elif !defined(_WIN32_WINNT) || !defined(_WIN32_WINNT_WIN2K) || \
#else
#endif
#ifndef CURL_WINDOWS_APP
#else
#endif
#endif /* WIN32 */
