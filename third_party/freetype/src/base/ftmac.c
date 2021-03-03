#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_TRUETYPE_TAGS_H
#include FT_INTERNAL_STREAM_H
#include "ftbase.h"
#ifdef FT_MACINTOSH
#if !HAVE_ANSI_OS_INLINE
#undef  OS_INLINE
#define OS_INLINE  static __inline__
#endif
#ifndef HAVE_TYPE_RESOURCE_INDEX
#if !defined( MAC_OS_X_VERSION_10_5 ) || \
#define HAVE_TYPE_RESOURCE_INDEX 0
#else
#define HAVE_TYPE_RESOURCE_INDEX 1
#endif
#endif /* !HAVE_TYPE_RESOURCE_INDEX */
#if ( HAVE_TYPE_RESOURCE_INDEX == 0 )
  typedef short  ResourceIndex;
#endif

#include <CoreServices/CoreServices.h>
#include <ApplicationServices/ApplicationServices.h>
#include <sys/syslimits.h> /* PATH_MAX */

  /* Don't want warnings about our own use of deprecated functions. */
#define FT_DEPRECATED_ATTRIBUTE

#include FT_MAC_H

#ifndef kATSOptionFlagsUnRestrictedScope /* since Mac OS X 10.1 */
#define kATSOptionFlagsUnRestrictedScope kATSOptionFlagsDefault
#endif


  /* Set PREFER_LWFN to 1 if LWFN (Type 1) is preferred over
     TrueType in case *both* are available (this is not common,
     but it *is* possible). */
#ifndef PREFER_LWFN
#define PREFER_LWFN  1
#endif


  /* This function is deprecated because FSSpec is deprecated in Mac OS X  */
  FT_EXPORT_DEF( FT_Error )
  FT_GetFile_From_Mac_Name( const char*  fontName,
                            FSSpec*      pathSpec,
                            FT_Long*     face_index )
  {
    FT_UNUSED( fontName );
    FT_UNUSED( pathSpec );
    FT_UNUSED( face_index );

    return FT_THROW( Unimplemented_Feature );
  }
#if defined( MAC_OS_X_VERSION_10_5 ) && \
#elif __LP64__ /* No 64bit Carbon API on legacy platforms */
#else /* 32bit Carbon API on legacy platforms */
#endif
#if ( __LP64__ ) || ( defined( MAC_OS_X_VERSION_10_5 ) && \
#else
#endif
#if ( __LP64__ ) || ( defined( MAC_OS_X_VERSION_10_5 ) && \
#else
#endif
#else /* !FT_MACINTOSH */
