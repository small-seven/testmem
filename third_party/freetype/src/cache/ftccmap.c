#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_CACHE_H
#include "ftcmanag.h"
#include FT_INTERNAL_MEMORY_H
#include FT_INTERNAL_OBJECTS_H
#include FT_INTERNAL_DEBUG_H
#include "ftccback.h"
#include "ftcerror.h"
#undef  FT_COMPONENT
#define FT_COMPONENT  cache
#define FTC_CMAP_INDICES_MAX  128
#define FTC_CMAP_HASH( faceid, index, charcode )         \
  typedef struct  FTC_CMapQueryRec_
  {
    FTC_FaceID  face_id;
    FT_UInt     cmap_index;
    FT_UInt32   char_code;

  } FTC_CMapQueryRec, *FTC_CMapQuery;
#define FTC_CMAP_QUERY( x )  ((FTC_CMapQuery)(x))
  typedef struct  FTC_CMapNodeRec_
  {
    FTC_NodeRec  node;
    FTC_FaceID   face_id;
    FT_UInt      cmap_index;
    FT_UInt32    first;                         /* first character in node */
    FT_UInt16    indices[FTC_CMAP_INDICES_MAX]; /* array of glyph indices  */

  } FTC_CMapNodeRec, *FTC_CMapNode;
#define FTC_CMAP_NODE( x ) ( (FTC_CMapNode)( x ) )
#define FTC_CMAP_UNKNOWN  (FT_UInt16)~0
#if 1
#else
#endif
