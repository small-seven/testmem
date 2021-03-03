#include <ft2build.h>
#include "sfwoff.h"
#include FT_TRUETYPE_TAGS_H
#include FT_INTERNAL_DEBUG_H
#include FT_INTERNAL_STREAM_H
#include FT_GZIP_H
#undef  FT_COMPONENT
#define FT_COMPONENT  sfwoff
#define WRITE_USHORT( p, v )                \
#define WRITE_ULONG( p, v )                  \
#undef  FT_STRUCTURE
#define FT_STRUCTURE  WOFF_HeaderRec
#ifdef FT_CONFIG_OPTION_USE_ZLIB
#else /* !FT_CONFIG_OPTION_USE_ZLIB */
#endif /* !FT_CONFIG_OPTION_USE_ZLIB */
#undef WRITE_USHORT
#undef WRITE_ULONG
