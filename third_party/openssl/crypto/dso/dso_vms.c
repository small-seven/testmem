#include "dso_local.h"
#ifdef OPENSSL_SYS_VMS
# pragma message disable DOLLARID
# include <errno.h>
# include <rms.h>
# include <lib$routines.h>
# include <libfisdef.h>
# include <stsdef.h>
# include <descrip.h>
# include <starlet.h>
# include "../vms_rms.h"
# if __INITIAL_POINTER_SIZE && defined _ANSI_C_SOURCE
#  if __INITIAL_POINTER_SIZE == 64
#   pragma pointer_size save
#   pragma pointer_size 32
#   pragma pointer_size restore
#  endif                        /* __INITIAL_POINTER_SIZE == 64 */
# endif                         /* __INITIAL_POINTER_SIZE && defined
# pragma message disable DOLLARID
typedef struct dso_internal_st {
    /*
     * This should contain the name only, no directory, no extension, nothing
     * but a name.
     */
    struct dsc$descriptor_s filename_dsc;
    char filename[NAMX_MAXRSS + 1];
    /*
     * This contains whatever is not in filename, if needed. Normally not
     * defined.
     */
    struct dsc$descriptor_s imagename_dsc;
    char imagename[NAMX_MAXRSS + 1];
} DSO_VMS_INTERNAL;
# if __INITIAL_POINTER_SIZE == 64
#  define DSO_MALLOC _malloc32
#  pragma pointer_size save
#  pragma pointer_size 32
# else                          /* __INITIAL_POINTER_SIZE == 64 */
#  define DSO_MALLOC OPENSSL_malloc
# endif                         /* __INITIAL_POINTER_SIZE == 64 [else] */
# if __INITIAL_POINTER_SIZE == 64
#  pragma pointer_size restore
# endif                         /* __INITIAL_POINTER_SIZE == 64 */
# ifndef LIB$M_FIS_MIXEDCASE
#  define LIB$M_FIS_MIXEDCASE (1 << 4);
# endif
# if __INITIAL_POINTER_SIZE == 64
#  define SYMNAME symname_32p
#  pragma pointer_size save
#  pragma pointer_size 32
#  pragma pointer_size restore
# else                          /* __INITIAL_POINTER_SIZE == 64 */
#  define SYMNAME ((char *) symname)
# endif                         /* __INITIAL_POINTER_SIZE == 64 [else] */
# if __INITIAL_POINTER_SIZE == 64
# endif                         /* __INITIAL_POINTER_SIZE == 64 [else] */
# if __INITIAL_POINTER_SIZE == 64
#  define FILESPEC1 filespec1_32p;
#  define FILESPEC2 filespec2_32p;
#  pragma pointer_size save
#  pragma pointer_size 32
#  pragma pointer_size restore
# else                          /* __INITIAL_POINTER_SIZE == 64 */
#  define FILESPEC1 ((char *) filespec1)
#  define FILESPEC2 ((char *) filespec2)
# endif                         /* __INITIAL_POINTER_SIZE == 64 [else] */
# if __INITIAL_POINTER_SIZE == 64
# endif                         /* __INITIAL_POINTER_SIZE == 64 [else] */
#endif                          /* OPENSSL_SYS_VMS */
