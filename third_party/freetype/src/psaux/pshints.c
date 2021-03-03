#include "psft.h"
#include FT_INTERNAL_DEBUG_H
#include "psglue.h"
#include "psfont.h"
#include "pshints.h"
#include "psintrp.h"
#undef  FT_COMPONENT
#define FT_COMPONENT  cf2hints
  typedef struct  CF2_HintMoveRec_
  {
    size_t     j;          /* index of upper hint map edge   */
    CF2_Fixed  moveUp;     /* adjustment to optimum position */

  } CF2_HintMoveRec, *CF2_HintMove;
#ifdef FT_DEBUG_LEVEL_TRACE
#else
#endif
#if 0
#endif
#if 0
#endif
#define cf2_perp( a, b )                                    \
#define CF2_CS_SCALE( x )         \
