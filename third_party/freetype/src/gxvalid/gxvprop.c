#include "gxvalid.h"
#include "gxvcommn.h"
#undef  FT_COMPONENT
#define FT_COMPONENT  gxvprop
#define GXV_PROP_HEADER_SIZE  ( 4 + 2 + 2 )
#define GXV_PROP_SIZE_MIN     GXV_PROP_HEADER_SIZE
  typedef struct  GXV_prop_DataRec_
  {
    FT_Fixed  version;

  } GXV_prop_DataRec, *GXV_prop_Data;
#define GXV_PROP_DATA( field )  GXV_TABLE_DATA( prop, field )
#define GXV_PROP_FLOATER                      0x8000U
#define GXV_PROP_USE_COMPLEMENTARY_BRACKET    0x1000U
#define GXV_PROP_COMPLEMENTARY_BRACKET_OFFSET 0x0F00U
#define GXV_PROP_ATTACHING_TO_RIGHT           0x0080U
#define GXV_PROP_RESERVED                     0x0060U
#define GXV_PROP_DIRECTIONALITY_CLASS         0x001FU
