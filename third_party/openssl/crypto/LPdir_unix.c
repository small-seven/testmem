#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#ifndef LPDIR_H
# include "LPdir.h"
#endif
#ifdef __VMS
# include <ctype.h>
#endif
#if defined(PATH_MAX)
# define LP_ENTRY_SIZE PATH_MAX
#elif defined(NAME_MAX)
# define LP_ENTRY_SIZE NAME_MAX
#endif
#if !defined(LP_ENTRY_SIZE) || LP_ENTRY_SIZE<255
# undef LP_ENTRY_SIZE
# define LP_ENTRY_SIZE 255
#endif
#ifdef __VMS
#endif
#ifdef __VMS
#endif
#ifdef __VMS
#endif
#ifdef __VMS
#endif
