#include "gxvalid.h"
#include "gxvcommn.h"
#undef  FT_COMPONENT
#define FT_COMPONENT  gxvbsln
#define GXV_BSLN_VALUE_COUNT  32
#define GXV_BSLN_VALUE_EMPTY  0xFFFFU
  typedef struct  GXV_bsln_DataRec_
  {
    FT_Bytes   ctlPoints_p;
    FT_UShort  defaultBaseline;

  } GXV_bsln_DataRec, *GXV_bsln_Data;
#define GXV_BSLN_DATA( field )  GXV_TABLE_DATA( bsln, field )
