#include "includes.h"
#include "common.h"
#include "wpa_supplicant_i.h"
#ifdef _WIN32_WCE
#define CMDLINE LPWSTR
#else /* _WIN32_WCE */
#define CMDLINE LPSTR
#endif /* _WIN32_WCE */
