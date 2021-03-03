#include "includes.h"
#ifndef CONFIG_NATIVE_WINDOWS
#include <dlfcn.h>
#endif /* CONFIG_NATIVE_WINDOWS */
#include "common.h"
#include "base64.h"
#include "common/tnc.h"
#include "tncc.h"
#include "eap_common/eap_tlv_common.h"
#include "eap_common/eap_defs.h"
#ifdef UNICODE
#define TSTR "%S"
#else /* UNICODE */
#define TSTR "%s"
#endif /* UNICODE */
#ifndef TNC_CONFIG_FILE
#define TNC_CONFIG_FILE "/etc/tnc_config"
#endif /* TNC_CONFIG_FILE */
#define TNC_WINREG_PATH TEXT("SOFTWARE\\Trusted Computing Group\\TNC\\IMCs")
#define IF_TNCCS_START \
#define IF_TNCCS_END "\n</TNCCS-Batch>"
#define TNC_MAX_IMC_ID 10
#ifdef CONFIG_NATIVE_WINDOWS
#ifdef _WIN32_WCE
#else /* _WIN32_WCE */
#endif /* _WIN32_WCE */
#else /* CONFIG_NATIVE_WINDOWS */
#endif /* CONFIG_NATIVE_WINDOWS */
#ifdef CONFIG_NATIVE_WINDOWS
#ifdef UNICODE
#else /* UNICODE */
#endif /* UNICODE */
#else /* CONFIG_NATIVE_WINDOWS */
#endif /* CONFIG_NATIVE_WINDOWS */
#ifdef CONFIG_NATIVE_WINDOWS
#else /* CONFIG_NATIVE_WINDOWS */
#endif /* CONFIG_NATIVE_WINDOWS */
#ifdef CONFIG_NATIVE_WINDOWS
#else /* CONFIG_NATIVE_WINDOWS */
#endif /* CONFIG_NATIVE_WINDOWS */
