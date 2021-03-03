#include "zutil.h"
#include "inftrees.h"
#include "inflate.h"
#include "inffast.h"
#ifdef Z_SOLO
#else
#endif
#ifdef Z_SOLO
#else
#endif
#ifdef BUILDFIXED
#else /* !BUILDFIXED */
#   include "inffixed.h"
#endif /* BUILDFIXED */
#define LOAD() \
#define RESTORE() \
#define INITBITS() \
#define PULL() \
#define PULLBYTE() \
#define NEEDBITS(n) \
#define BITS(n) \
#define DROPBITS(n) \
#define BYTEBITS() \
#define ROOM() \
#ifndef PKZIP_BUG_WORKAROUND
#endif
