#include <ft2build.h>
#include FT_CACHE_H
#include "ftcmanag.h"
#include FT_INTERNAL_OBJECTS_H
#include FT_INTERNAL_DEBUG_H
#include FT_SIZES_H
#include "ftccback.h"
#include "ftcerror.h"
#undef  FT_COMPONENT
#define FT_COMPONENT  cache
  typedef struct  FTC_SizeNodeRec_
  {
    FTC_MruNodeRec  node;
    FT_Size         size;
    FTC_ScalerRec   scaler;

  } FTC_SizeNodeRec, *FTC_SizeNode;
#define FTC_SIZE_NODE( x ) ( (FTC_SizeNode)( x ) )
#ifdef FTC_INLINE
#else
#endif
  typedef struct  FTC_FaceNodeRec_
  {
    FTC_MruNodeRec  node;
    FTC_FaceID      face_id;
    FT_Face         face;

  } FTC_FaceNodeRec, *FTC_FaceNode;
#define FTC_FACE_NODE( x ) ( ( FTC_FaceNode )( x ) )
#ifdef FTC_INLINE
#else
#endif
#ifdef FT_DEBUG_ERROR
#endif /* FT_DEBUG_ERROR */
#ifdef FT_DEBUG_ERROR
#endif
