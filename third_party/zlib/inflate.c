 * - Changed inflateBack() argument and in_func typedef to swap the length
 *   and buffer address return values for the input function
 * - Check next_in and next_out for Z_NULL on entry to inflate()
 *
 * The history for versions after 1.2.0 are in ChangeLog in zlib distribution.
 */

#include "zutil.h"
#include "inftrees.h"
#include "inflate.h"
#include "inffast.h"

#ifdef MAKEFIXED
#  ifndef BUILDFIXED
#    define BUILDFIXED
#  endif
#endif

/* function prototypes */
local int inflateStateCheck OF((z_streamp strm));
local void fixedtables OF((struct inflate_state FAR *state));
local int updatewindow OF((z_streamp strm, const unsigned char FAR *end,
                           unsigned copy));
#ifdef BUILDFIXED
   void makefixed OF((void));
#endif
local unsigned syncsearch OF((unsigned FAR *have, const unsigned char FAR *buf,
                              unsigned len));

local int inflateStateCheck(strm)
z_streamp strm;
{
    struct inflate_state FAR *state;
    if (strm == Z_NULL ||
        strm->zalloc == (alloc_func)0 || strm->zfree == (free_func)0)
        return 1;
    state = (struct inflate_state FAR *)strm->state;
    if (state == Z_NULL || state->strm != strm ||
        state->mode < HEAD || state->mode > SYNC)
        return 1;
    return 0;
}
#ifdef GUNZIP
#endif
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
#ifdef MAKEFIXED
#include <stdio.h>
#endif /* MAKEFIXED */
#ifdef GUNZIP
#  define UPDATE(check, buf, len) \
#else
#  define UPDATE(check, buf, len) adler32(check, buf, len)
#endif
#ifdef GUNZIP
#  define CRC2(check, word) \
#  define CRC4(check, word) \
#endif
#define LOAD() \
#define RESTORE() \
#define INITBITS() \
#define PULLBYTE() \
#define NEEDBITS(n) \
#define BITS(n) \
#define DROPBITS(n) \
#define BYTEBITS() \
#ifdef GUNZIP
#endif
#ifdef GUNZIP
#else
#endif
#ifdef GUNZIP
#endif
#ifndef PKZIP_BUG_WORKAROUND
#endif
#ifdef INFLATE_STRICT
#endif
#ifdef INFLATE_ALLOW_INVALID_DISTANCE_TOOFAR_ARRR
#endif
#ifdef GUNZIP
#endif
#ifdef GUNZIP
#endif
#ifdef INFLATE_ALLOW_INVALID_DISTANCE_TOOFAR_ARRR
#else
#endif
