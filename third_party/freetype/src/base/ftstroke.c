#include <ft2build.h>
#include FT_STROKER_H
#include FT_TRIGONOMETRY_H
#include FT_OUTLINE_H
#include FT_INTERNAL_MEMORY_H
#include FT_INTERNAL_DEBUG_H
#include FT_INTERNAL_OBJECTS_H
#define FT_SMALL_CONIC_THRESHOLD  ( FT_ANGLE_PI / 6 )
#define FT_SMALL_CUBIC_THRESHOLD  ( FT_ANGLE_PI / 8 )
#define FT_EPSILON  2
#define FT_IS_SMALL( x )  ( (x) > -FT_EPSILON && (x) < FT_EPSILON )
  typedef enum  FT_StrokeTags_
  {
    FT_STROKE_TAG_ON    = 1,   /* on-curve point  */
    FT_STROKE_TAG_CUBIC = 2,   /* cubic off-point */
    FT_STROKE_TAG_BEGIN = 4,   /* sub-path start  */
    FT_STROKE_TAG_END   = 8    /* sub-path end    */

  } FT_StrokeTags;
#define  FT_STROKE_TAG_BEGIN_END  ( FT_STROKE_TAG_BEGIN | FT_STROKE_TAG_END )
  typedef struct  FT_StrokeBorderRec_
  {
    FT_UInt     num_points;
    FT_UInt     max_points;
    FT_Vector*  points;
    FT_Byte*    tags;
    FT_Bool     movable;  /* TRUE for ends of lineto borders */
    FT_Int      start;    /* index of current sub-path start point */
    FT_Memory   memory;
    FT_Bool     valid;

  } FT_StrokeBorderRec, *FT_StrokeBorder;
#define FT_ARC_CUBIC_ANGLE  ( FT_ANGLE_PI / 2 )
#define FT_SIDE_TO_ROTATE( s )   ( FT_ANGLE_PI2 - (s) * FT_ANGLE_PI )
  typedef struct  FT_StrokerRec_
  {
    FT_Angle             angle_in;             /* direction into curr join */
    FT_Angle             angle_out;            /* direction out of join  */
    FT_Vector            center;               /* current position */
    FT_Fixed             line_length;          /* length of last lineto */
    FT_Bool              first_point;          /* is this the start? */
    FT_Bool              subpath_open;         /* is the subpath open? */
    FT_Angle             subpath_angle;        /* subpath start direction */
    FT_Vector            subpath_start;        /* subpath start position */
    FT_Fixed             subpath_line_length;  /* subpath start lineto len */
    FT_Bool              handle_wide_strokes;  /* use wide strokes logic? */

    FT_Stroker_LineCap   line_cap;
    FT_Stroker_LineJoin  line_join;
    FT_Stroker_LineJoin  line_join_saved;
    FT_Fixed             miter_limit;
    FT_Fixed             radius;

    FT_StrokeBorderRec   borders[2];
    FT_Library           library;

  } FT_StrokerRec;
