#include "zutil.h"
#ifndef STDC
#endif
#ifndef HAVE_MEMCPY
#endif
#if defined( MSDOS ) && defined( __TURBOC__ ) && !defined( MY_ZCALLOC )
#if (defined( __BORLANDC__) || !defined(SMALL_MEDIUM)) && !defined(__32BIT__)
#  define MY_ZCALLOC
#define MAX_PTR 10
typedef struct ptr_table_s {
    voidpf org_ptr;
    voidpf new_ptr;
} ptr_table;
#endif
#endif /* MSDOS && __TURBOC__ */
#if defined(M_I86) && !defined(__32BIT__) && !defined( MY_ZCALLOC )
#  define MY_ZCALLOC
#if (!defined(_MSC_VER) || (_MSC_VER <= 600))
#  define _halloc  halloc
#  define _hfree   hfree
#endif
#endif /* MSC */
#ifndef MY_ZCALLOC /* Any system without a special alloc function */
#ifndef STDC
#endif
#endif /* MY_ZCALLOC */
