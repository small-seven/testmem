#include <ft2build.h>
#include FT_INTERNAL_DEBUG_H
#include FT_BBOX_H
#include FT_IMAGE_H
#include FT_OUTLINE_H
#include FT_INTERNAL_CALC_H
#include FT_INTERNAL_OBJECTS_H
  typedef struct  TBBox_Rec_
  {
    FT_Vector  last;
    FT_BBox    bbox;

  } TBBox_Rec;
#define FT_UPDATE_BBOX( p, bbox ) \
#define CHECK_X( p, bbox )                         \
#define CHECK_Y( p, bbox )                         \
