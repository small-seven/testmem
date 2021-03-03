#include <windows.h>
#include <tchar.h>
#include "internal/numbers.h"
#ifndef LPDIR_H
# include "LPdir.h"
#endif
#if defined(LP_SYS_WINCE) && !defined(FindFirstFile)
# define FindFirstFile FindFirstFileW
#endif
#if defined(LP_SYS_WINCE) && !defined(FindNextFile)
# define FindNextFile FindNextFileW
#endif
#ifndef NAME_MAX
# define NAME_MAX 255
#endif
#ifdef CP_UTF8
# define CP_DEFAULT CP_UTF8
#else
# define CP_DEFAULT CP_ACP
#endif
#ifdef LP_MULTIBYTE_AVAILABLE
# ifdef CP_UTF8
# endif
#endif
#ifdef LP_MULTIBYTE_AVAILABLE
#endif
