#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_INTERNAL_DEBUG_H
#ifdef FT_DEBUG_LEVEL_ERROR
#if 0
#else
#endif
#endif /* FT_DEBUG_LEVEL_ERROR */
#ifdef FT_DEBUG_LEVEL_TRACE
#define FT_TRACE_DEF( x )  #x ,
#include FT_INTERNAL_TRACE_H
#undef FT_TRACE_DEF
#else  /* !FT_DEBUG_LEVEL_TRACE */
#endif /* !FT_DEBUG_LEVEL_TRACE */
