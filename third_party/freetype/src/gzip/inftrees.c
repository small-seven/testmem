#include "zutil.h"
#include "inftrees.h"
#if !defined(BUILDFIXED) && !defined(STDC)
#  define BUILDFIXED   /* non ANSI compilers may not accept inffixed.h */
#endif
#if 0
#endif
#define exop word.what.Exop
#define bits word.what.Bits
#define BMAX 15         /* maximum bit length of any code */
#define C0 *p++ = 0;
#define C2 C0 C0 C0 C0
#define C4 C2 C2 C2 C2
#if 0
#endif
#ifdef PKZIP_BUG_WORKAROUND
#else
#endif
#ifdef BUILDFIXED
#define FIXEDH 544      /* number of hufts used by fixed tables */
#else
#include "inffixed.h"
#endif
#ifdef BUILDFIXED
#else
#endif
