#if !defined (_XOPEN_SOURCE) || _XOPEN_SOURCE < 500
#undef _XOPEN_SOURCE
#define _XOPEN_SOURCE 500
#endif
#ifdef _WIN32
#include <windows.h>
#elif defined (HAVE_TIME_H)
#include <time.h>
#elif defined (HAVE_UNISTD_H)
#include <unistd.h>
#endif /* _WIN32 */
#include "jerryscript-port.h"
#include "jerryscript-port-default.h"
#ifdef _WIN32
#elif defined (HAVE_TIME_H)
#elif defined (HAVE_UNISTD_H)
#else
#endif /* HAVE_TIME_H */
