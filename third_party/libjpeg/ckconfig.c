#define HAVE_STDDEF_H		/* replace 'define' by 'undef' if error here */
#ifdef HAVE_STDDEF_H		/* next line will be skipped if you undef... */
#include <stddef.h>
#endif
#define HAVE_STDLIB_H		/* same thing for stdlib.h */
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif
#include <stdio.h>		/* If you ain't got this, you ain't got C. */
#undef NEED_BSD_STRINGS
#ifdef NEED_BSD_STRINGS
#include <strings.h>
#else
#include <string.h>
#endif
#undef NEED_SYS_TYPES_H		/* start by assuming we don't need it */
#ifdef NEED_SYS_TYPES_H
#include <sys/types.h>
#endif
 * above.  If not, you'll get an error on the "typedef size_t my_size_t;" line.
 * In that case, first try defining NEED_SYS_TYPES_H just above.
 * If that doesn't work, you'll have to search through your system library
 * to figure out which include file defines "size_t".  Look for a line that
 * says "typedef something-or-other size_t;".  Then, change the line below
 * that says "#include <someincludefile.h>" to instead include the file
 * you found size_t in, and define NEED_SPECIAL_INCLUDE.  If you can't find
 * type size_t anywhere, try replacing "#include <someincludefile.h>" with
 * "typedef unsigned int size_t;".
 */

#undef NEED_SPECIAL_INCLUDE	/* assume we DON'T need it, for starters */

#ifdef NEED_SPECIAL_INCLUDE
#include <someincludefile.h>
#endif

typedef size_t my_size_t;	/* The payoff: do we have size_t now? */


/* The next question is whether your compiler supports ANSI-style function
 * prototypes.  You need to know this in order to choose between using
 * makefile.ansi and using makefile.unix.
 * The #define line below is set to assume you have ANSI function prototypes.
 * If you get an error in this group of lines, undefine HAVE_PROTOTYPES.
 */

#define HAVE_PROTOTYPES

#ifdef HAVE_PROTOTYPES
int testfunction (int arg1, int * arg2); /* check prototypes */

struct methods_struct {		/* check method-pointer declarations */
  int (*error_exit) (char *msgtext);
  int (*trace_message) (char *msgtext);
  int (*another_method) (void);
};
#endif
#define HAVE_UNSIGNED_CHAR
#ifdef HAVE_UNSIGNED_CHAR
#endif
#define HAVE_UNSIGNED_SHORT
#ifdef HAVE_UNSIGNED_SHORT
#endif
#define HAVE_VOID
#ifdef HAVE_VOID
typedef void * void_ptr;	/* check void * */
#ifdef HAVE_PROTOTYPES		/* check ptr to function returning void */
typedef void (*void_func) (int a, int b);
#else
typedef void (*void_func) ();
#endif

#ifdef HAVE_PROTOTYPES		/* check void function result */
void test3function (void_ptr arg1, void_func arg2)
#else
void test3function (arg1, arg2)
     void_ptr arg1;
     void_func arg2;
#endif
{
  char * locptr = (char *) arg1; /* check casting to and from void * */
  arg1 = (void *) locptr;
  (*arg2) (1, 2);		/* check call of fcn returning void */
}
#endif
#define HAVE_CONST
#ifdef HAVE_CONST
#ifdef HAVE_PROTOTYPES
#else
#endif
#endif
#undef INCOMPLETE_TYPES_BROKEN
#ifndef INCOMPLETE_TYPES_BROKEN
typedef struct undefined_structure * undef_struct_ptr;
#endif


/* If you get an error about duplicate names,
 * define NEED_SHORT_EXTERNAL_NAMES.
 */

#undef NEED_SHORT_EXTERNAL_NAMES

#ifndef NEED_SHORT_EXTERNAL_NAMES

int possibly_duplicate_function ()
{
  return 0;
}
#endif
#ifdef HAVE_PROTOTYPES
#else
#endif
#ifdef HAVE_PROTOTYPES
#else
#endif
#ifdef HAVE_PROTOTYPES
#else
#endif
#ifdef HAVE_PROTOTYPES
#else
#endif
#ifdef HAVE_UNSIGNED_CHAR
#else
#endif
#ifdef HAVE_UNSIGNED_SHORT
#else
#endif
#ifdef HAVE_VOID
#else
#endif
#ifdef HAVE_CONST
#else
#endif
#ifdef HAVE_STDDEF_H
#else
#endif
#ifdef HAVE_STDLIB_H
#else
#endif
#ifdef NEED_BSD_STRINGS
#else
#endif
#ifdef NEED_SYS_TYPES_H
#else
#endif
#ifdef NEED_SHORT_EXTERNAL_NAMES
#else
#endif
#ifdef INCOMPLETE_TYPES_BROKEN
#else
#endif
#ifdef HAVE_PROTOTYPES
#else
#endif
#ifdef NEED_SPECIAL_INCLUDE
#endif
