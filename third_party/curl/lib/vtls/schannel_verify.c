#include "curl_setup.h"
#ifdef USE_SCHANNEL
#ifndef USE_WINDOWS_SSPI
#  error "Can't compile SCHANNEL support without SSPI."
#endif
#define EXPOSE_SCHANNEL_INTERNAL_STRUCTS
#include "schannel.h"
#ifdef HAS_MANUAL_VERIFY_API
#include "vtls.h"
#include "sendf.h"
#include "strerror.h"
#include "curl_multibyte.h"
#include "curl_printf.h"
#include "hostcheck.h"
#include "system_win32.h"
#include "curl_memory.h"
#include "memdebug.h"
#define BACKEND connssl->backend
#define MAX_CAFILE_SIZE 1048576 /* 1 MiB */
#define BEGIN_CERT "-----BEGIN CERTIFICATE-----"
#define END_CERT "\n-----END CERTIFICATE-----"
typedef struct {
  DWORD cbSize;
  HCERTSTORE hRestrictedRoot;
  HCERTSTORE hRestrictedTrust;
  HCERTSTORE hRestrictedOther;
  DWORD cAdditionalStore;
  HCERTSTORE *rghAdditionalStore;
  DWORD dwFlags;
  DWORD dwUrlRetrievalTimeout;
  DWORD MaximumCachedCertificates;
  DWORD CycleDetectionModulus;
  HCERTSTORE hExclusiveRoot;
  HCERTSTORE hExclusiveTrustedPeople;
} CERT_CHAIN_ENGINE_CONFIG_WIN7, *PCERT_CHAIN_ENGINE_CONFIG_WIN7;
#ifdef CERT_NAME_SEARCH_ALL_NAMES_FLAG
#endif
#endif /* HAS_MANUAL_VERIFY_API */
#endif /* USE_SCHANNEL */
