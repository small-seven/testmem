#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_TRUETYPE_TAGS_H
#include FT_INTERNAL_STREAM_H
#include "ftbase.h"
#if defined( __GNUC__ ) || defined( __IBMC__ )
#if !HAVE_ANSI_OS_INLINE
#undef  OS_INLINE
#define OS_INLINE   static __inline__
#endif
#include <CoreServices/CoreServices.h>
#include <ApplicationServices/ApplicationServices.h>
#include <sys/syslimits.h> /* PATH_MAX */
#else
#include <Resources.h>
#include <Fonts.h>
#include <Endian.h>
#include <Errors.h>
#include <Files.h>
#include <TextUtils.h>
#endif
#ifndef PATH_MAX
#define PATH_MAX 1024 /* same with Mac OS X's syslimits.h */
#endif
#if defined( __MWERKS__ ) && !TARGET_RT_MAC_MACHO
#include <FSp_fopen.h>
#endif
#define FT_DEPRECATED_ATTRIBUTE
#include FT_MAC_H
#undef FT_GetFile_From_Mac_Name
#undef FT_GetFile_From_Mac_ATS_Name
#undef FT_New_Face_From_FOND
#undef FT_New_Face_From_FSSpec
#undef FT_New_Face_From_FSRef
#ifndef HAVE_FSSPEC
#if TARGET_API_MAC_OS8 || TARGET_API_MAC_CARBON
#define HAVE_FSSPEC  1
#else
#define HAVE_FSSPEC  0
#endif
#endif
#ifndef HAVE_FSREF
#if TARGET_API_MAC_OSX
#define HAVE_FSREF  1
#else
#define HAVE_FSREF  0
#endif
#endif
#ifndef HAVE_QUICKDRAW_CARBON
#if TARGET_API_MAC_OS8 || TARGET_API_MAC_CARBON
#define HAVE_QUICKDRAW_CARBON  1
#else
#define HAVE_QUICKDRAW_CARBON  0
#endif
#endif
#ifndef HAVE_ATS
#if TARGET_API_MAC_OSX
#define HAVE_ATS  1
#ifndef kATSOptionFlagsUnRestrictedScope /* since Mac OS X 10.1 */
#define kATSOptionFlagsUnRestrictedScope kATSOptionFlagsDefault
#endif
#else
#define HAVE_ATS  0
#endif
#endif
#ifndef HAVE_TYPE_RESOURCE_INDEX
#if !defined( MAC_OS_X_VERSION_10_5 ) || \
#define HAVE_TYPE_RESOURCE_INDEX 0
#else
#define HAVE_TYPE_RESOURCE_INDEX 1
#endif
#endif /* !HAVE_TYPE_RESOURCE_INDEX */
#if ( HAVE_TYPE_RESOURCE_INDEX == 0 )
typedef short ResourceIndex;
#endif

  /* Set PREFER_LWFN to 1 if LWFN (Type 1) is preferred over
     TrueType in case *both* are available (this is not common,
     but it *is* possible). */
#ifndef PREFER_LWFN
#define PREFER_LWFN  1
#endif

#ifdef FT_MACINTOSH

#if !HAVE_QUICKDRAW_CARBON  /* QuickDraw is deprecated since Mac OS X 10.4 */

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
#else
#endif /* HAVE_QUICKDRAW_CARBON */
#if HAVE_ATS
#if !defined( MAC_OS_X_VERSION_10_5 ) || \
#else
#endif
#endif
#if !HAVE_ATS
#else
#endif /* HAVE_ATS */
#if !HAVE_FSSPEC || !HAVE_ATS
#else
#endif
#if defined( __MWERKS__ ) && !TARGET_RT_MAC_MACHO
#define STREAM_FILE( stream )  ( (FT_FILE*)stream->descriptor.pointer )
#endif  /* __MWERKS__ && !TARGET_RT_MAC_MACHO */
#if HAVE_FSSPEC && !HAVE_FSREF
#endif /* HAVE_FSSPEC && !HAVE_FSREF */
#if HAVE_FSREF
#else
#endif /* HAVE_FSREF */
#if HAVE_FSREF
#else
#endif /* HAVE_FSREF */
#if HAVE_FSREF
#else
#endif /* HAVE_FSREF */
#if HAVE_FSREF
#elif HAVE_FSSPEC
#endif /* HAVE_FSREF, HAVE_FSSPEC */
#if !HAVE_FSREF
#else
#endif /* HAVE_FSREF */
#if HAVE_FSREF
#elif HAVE_FSSPEC
#else
#endif /* HAVE_FSREF, HAVE_FSSPEC */
#endif /* FT_MACINTOSH */
