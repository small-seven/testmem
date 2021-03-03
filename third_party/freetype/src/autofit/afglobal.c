#include "afglobal.h"
#include "afranges.h"
#include "afshaper.h"
#include FT_INTERNAL_DEBUG_H
#undef  FT_COMPONENT
#define FT_COMPONENT  afglobal
#undef  WRITING_SYSTEM
#define WRITING_SYSTEM( ws, WS )  /* empty */
#include "afwrtsys.h"
#include "aferrors.h"
#undef  SCRIPT
#define SCRIPT( s, S, d, h, H, ss )         \
#include "afscript.h"
#undef  STYLE
#define STYLE( s, S, d, ws, sc, ss, c )  \
#include "afstyles.h"
#undef  WRITING_SYSTEM
#define WRITING_SYSTEM( ws, WS )               \
#include "afwrtsys.h"
#undef  SCRIPT
#define SCRIPT( s, S, d, h, H, ss )   \
#include "afscript.h"
#undef  STYLE
#define STYLE( s, S, d, ws, sc, ss, c ) \
#include "afstyles.h"
#ifdef FT_DEBUG_LEVEL_TRACE
#undef  STYLE
#define STYLE( s, S, d, ws, sc, ss, c )  #s,
#include "afstyles.h"
#endif /* FT_DEBUG_LEVEL_TRACE */
#ifdef FT_DEBUG_LEVEL_TRACE
#endif /* FT_DEBUG_LEVEL_TRACE */
#ifdef FT_CONFIG_OPTION_USE_HARFBUZZ
#endif
#ifdef FT_CONFIG_OPTION_USE_HARFBUZZ
#endif
