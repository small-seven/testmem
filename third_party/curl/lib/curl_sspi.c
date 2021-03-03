#include "curl_setup.h"
#ifdef USE_WINDOWS_SSPI
#include <curl/curl.h>
#include "curl_sspi.h"
#include "curl_multibyte.h"
#include "system_win32.h"
#include "warnless.h"
#include "curl_memory.h"
#include "memdebug.h"
/* We use our own typedef here since some headers might lack these */
typedef PSecurityFunctionTable (APIENTRY *INITSECURITYINTERFACE_FN)(VOID);

/* See definition of SECURITY_ENTRYPOINT in sspi.h */
#ifdef UNICODE
#  ifdef _WIN32_WCE
#    define SECURITYENTRYPOINT L"InitSecurityInterfaceW"
#  else
#    define SECURITYENTRYPOINT "InitSecurityInterfaceW"
#  endif
#else
#  define SECURITYENTRYPOINT "InitSecurityInterfaceA"
#endif

/* Handle of security.dll or secur32.dll, depending on Windows version */
HMODULE s_hSecDll = NULL;

/* Pointer to SSPI dispatch table */
PSecurityFunctionTable s_pSecFn = NULL;

/*
 * Curl_sspi_global_init()
 *
 * This is used to load the Security Service Provider Interface (SSPI)
 * dynamic link library portably across all Windows versions, without
 * the need to directly link libcurl, nor the application using it, at
 * build time.
 *
 * Once this function has been executed, Windows SSPI functions can be
 * called through the Security Service Provider Interface dispatch table.
 *
 * Parameters:
 *
 * None.
 *
 * Returns CURLE_OK on success.
 */
CURLcode Curl_sspi_global_init(void)
{
  INITSECURITYINTERFACE_FN pInitSecurityInterface;

  /* If security interface is not yet initialized try to do this */
  if(!s_hSecDll) {
    /* Security Service Provider Interface (SSPI) functions are located in
     * security.dll on WinNT 4.0 and in secur32.dll on Win9x. Win2K and XP
     * have both these DLLs (security.dll forwards calls to secur32.dll) */

    /* Load SSPI dll into the address space of the calling process */
    if(Curl_verify_windows_version(4, 0, PLATFORM_WINNT, VERSION_EQUAL))
      s_hSecDll = Curl_load_library(TEXT("security.dll"));
    else
      s_hSecDll = Curl_load_library(TEXT("secur32.dll"));
    if(!s_hSecDll)
      return CURLE_FAILED_INIT;

    /* Get address of the InitSecurityInterfaceA function from the SSPI dll */
    pInitSecurityInterface =
      CURLX_FUNCTION_CAST(INITSECURITYINTERFACE_FN,
                          (GetProcAddress(s_hSecDll, SECURITYENTRYPOINT)));
    if(!pInitSecurityInterface)
      return CURLE_FAILED_INIT;

    /* Get pointer to Security Service Provider Interface dispatch table */
    s_pSecFn = pInitSecurityInterface();
    if(!s_pSecFn)
      return CURLE_FAILED_INIT;
  }
#endif /* USE_WINDOWS_SSPI */
