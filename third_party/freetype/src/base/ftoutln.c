#include <ft2build.h>
#include FT_OUTLINE_H
#include FT_INTERNAL_OBJECTS_H
#include FT_INTERNAL_CALC_H
#include FT_INTERNAL_DEBUG_H
#include FT_TRIGONOMETRY_H
#undef  FT_COMPONENT
#define FT_COMPONENT  outline
#undef  SCALED
#define SCALED( x )  ( (x) * ( 1L << shift ) - delta )
#if 0
#define FT_OUTLINE_GET_CONTOUR( outline, c, first, last )  \
#endif /* 0 */
