#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <descrip.h>
#include <namdef.h>
#include <rmsdef.h>
#include <libfildef.h>
#include <lib$routines.h>
#include <strdef.h>
#include <str$routines.h>
#include <stsdef.h>
#ifndef LPDIR_H
# include "LPdir.h"
#endif
#include "vms_rms.h"
#ifndef EVMSERR
# define EVMSERR        65535   /* error for non-translatable VMS errors */
#endif
#if __INITIAL_POINTER_SIZE == 64
# pragma pointer_size save
# pragma pointer_size 32
# pragma pointer_size restore
#endif                          /* __INITIAL_POINTER_SIZE == 64 */
#ifdef NAML$C_MAXRSS
#endif
#if __INITIAL_POINTER_SIZE == 64
# define CTX_FILESPEC ctx_filespec_32p
#else                           /* __INITIAL_POINTER_SIZE == 64 */
# define CTX_FILESPEC (*ctx)->filespec
#endif                          /* __INITIAL_POINTER_SIZE == 64 [else] */
