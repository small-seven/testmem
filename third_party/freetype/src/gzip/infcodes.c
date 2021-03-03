#include "zutil.h"
#include "inftrees.h"
#include "infblock.h"
#include "infcodes.h"
#include "infutil.h"
#define exop word.what.Exop
#define bits word.what.Bits
typedef enum {        /* waiting for "i:"=input, "o:"=output, "x:"=nothing */
      START,    /* x: set up for LEN */
      LEN,      /* i: get length/literal/eob next */
      LENEXT,   /* i: getting length extra (have base) */
      DIST,     /* i: get distance next */
      DISTEXT,  /* i: getting distance extra */
      COPY,     /* o: copying bytes in window, waiting for space */
      LIT,      /* o: got literal, waiting for output space */
      WASH,     /* o: got eob, possibly still output waiting */
      END,      /* x: got eob and all data flushed */
      BADCODE}  /* x: got error */
#ifndef SLOW
#endif /* !SLOW */
#ifdef NEED_DUMMY_RETURN
#endif
local void inflate_codes_free( /* c, z) */
inflate_codes_statef *c,
z_streamp z )
{
  ZFREE(z, c);
  Tracev((stderr, "inflate:       codes free\n"));
}
