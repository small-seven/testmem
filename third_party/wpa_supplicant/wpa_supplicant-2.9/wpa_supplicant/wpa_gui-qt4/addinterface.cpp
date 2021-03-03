#include <cstdio>
#include "common/wpa_ctrl.h"
#include <QMessageBox>
#include "wpagui.h"
#include "addinterface.h"
#ifdef CONFIG_NATIVE_WINDOWS
#include <windows.h>
#ifndef WPA_KEY_ROOT
#define WPA_KEY_ROOT HKEY_LOCAL_MACHINE
#endif
#ifndef WPA_KEY_PREFIX
#define WPA_KEY_PREFIX TEXT("SOFTWARE\\wpa_supplicant")
#endif
#endif /* CONFIG_NATIVE_WINDOWS */
#ifdef CONFIG_CTRL_IFACE_NAMED_PIPE
#endif /* CONFIG_CTRL_IFACE_NAMED_PIPE */
#ifdef CONFIG_NATIVE_WINDOWS
#ifdef UNICODE
#else /* UNICODE */
#endif /* UNICODE */
#ifdef UNICODE
#else /* UNICODE */
#endif /* UNICODE */
#ifdef UNICODE
#else /* UNICODE */
#endif /* UNICODE */
#endif /* CONFIG_NATIVE_WINDOWS */
#ifdef CONFIG_CTRL_IFACE_NAMED_PIPE
#endif /* CONFIG_CTRL_IFACE_NAMED_PIPE */
#ifdef CONFIG_NATIVE_WINDOWS
#endif /* CONFIG_NATIVE_WINDOWS */
