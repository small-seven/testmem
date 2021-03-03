#include <ft2build.h>
#include FT_CACHE_H
#include "ftcsbits.h"
#include FT_INTERNAL_OBJECTS_H
#include FT_INTERNAL_DEBUG_H
#include FT_ERRORS_H
#include "ftccback.h"
#include "ftcerror.h"
#undef  FT_COMPONENT
#define FT_COMPONENT  cache
#define CHECK_CHAR( d )  ( temp = (FT_Char)d, (FT_Int) temp == (FT_Int) d )
#define CHECK_BYTE( d )  ( temp = (FT_Byte)d, (FT_UInt)temp == (FT_UInt)d )
#if 0
#endif /* 0 */
#ifdef FTC_INLINE
#endif
