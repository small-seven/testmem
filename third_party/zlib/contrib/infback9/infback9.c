#include "zutil.h"
#include "infback9.h"
#include "inftree9.h"
#include "inflate9.h"
#define WSIZE 65536UL
#ifdef MAKEFIXED
#include <stdio.h>
#endif /* MAKEFIXED */
#define INITBITS() \
#define PULL() \
#define PULLBYTE() \
#define NEEDBITS(n) \
#define BITS(n) \
#define DROPBITS(n) \
#define BYTEBITS() \
#define ROOM() \
#include "inffix9.h"
