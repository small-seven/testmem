#if (defined(_WIN64) || defined(_WIN32_WCE)) && !defined(UNICODE)
# define UNICODE
#endif
#if defined(UNICODE) && !defined(_UNICODE)
# define _UNICODE
#endif
#if defined(_UNICODE) && !defined(UNICODE)
# define UNICODE
#endif
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include "uplink.h"
#if defined(_MSC_VER) && defined(_M_IX86)
# define LAZY(i)         \
# if APPLINK_MAX>25
#  error "Add more stubs..."
# endif
#endif
#ifdef SELFTEST
#endif
