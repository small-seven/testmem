#include "gxvalid.h"
#include "gxvcommn.h"
#undef  FT_COMPONENT
#define FT_COMPONENT  gxvopbd
  typedef struct  GXV_opbd_DataRec_
  {
    FT_UShort  format;
    FT_UShort  valueOffset_min;

  } GXV_opbd_DataRec, *GXV_opbd_Data;
#define GXV_OPBD_DATA( FIELD )  GXV_TABLE_DATA( opbd, FIELD )
