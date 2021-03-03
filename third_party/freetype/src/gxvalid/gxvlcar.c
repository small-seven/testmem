#include "gxvalid.h"
#include "gxvcommn.h"
#undef  FT_COMPONENT
#define FT_COMPONENT  gxvlcar
  typedef struct  GXV_lcar_DataRec_
  {
    FT_UShort  format;

  } GXV_lcar_DataRec, *GXV_lcar_Data;
#define GXV_LCAR_DATA( FIELD )  GXV_TABLE_DATA( lcar, FIELD )
