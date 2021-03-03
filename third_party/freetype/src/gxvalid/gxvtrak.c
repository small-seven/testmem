#include "gxvalid.h"
#include "gxvcommn.h"
#undef  FT_COMPONENT
#define FT_COMPONENT  gxvtrak
  typedef struct  GXV_trak_DataRec_
  {
    FT_UShort  trackValueOffset_min;
    FT_UShort  trackValueOffset_max;

  } GXV_trak_DataRec, *GXV_trak_Data;
#define GXV_TRAK_DATA( FIELD )  GXV_TABLE_DATA( trak, FIELD )
