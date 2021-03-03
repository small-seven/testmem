#include "includes.h"
#include <windows.h>
#include "common.h"
#include "wpa_supplicant_i.h"
#include "eloop.h"
#ifndef WPASVC_NAME
#define WPASVC_NAME TEXT("wpasvc")
#endif
#ifndef WPASVC_DISPLAY_NAME
#define WPASVC_DISPLAY_NAME TEXT("wpa_supplicant service")
#endif
#ifndef WPASVC_DESCRIPTION
#define WPASVC_DESCRIPTION \
#endif
#ifndef WPA_KEY_ROOT
#define WPA_KEY_ROOT HKEY_LOCAL_MACHINE
#endif
#ifndef WPA_KEY_PREFIX
#define WPA_KEY_PREFIX TEXT("SOFTWARE\\wpa_supplicant")
#endif
#ifdef UNICODE
#define TSTR "%S"
#else /* UNICODE */
#define TSTR "%s"
#endif /* UNICODE */
#define TBUFLEN 255
