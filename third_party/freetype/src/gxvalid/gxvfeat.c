#include "gxvalid.h"
#include "gxvcommn.h"
#include "gxvfeat.h"
#undef  FT_COMPONENT
#define FT_COMPONENT  gxvfeat
  typedef struct  GXV_feat_DataRec_
  {
    FT_UInt    reserved_size;
    FT_UShort  feature;
    FT_UShort  setting;

  } GXV_feat_DataRec, *GXV_feat_Data;
#define GXV_FEAT_DATA( field )  GXV_TABLE_DATA( feat, field )
  typedef enum  GXV_FeatureFlagsMask_
  {
    GXV_FEAT_MASK_EXCLUSIVE_SETTINGS = 0x8000U,
    GXV_FEAT_MASK_DYNAMIC_DEFAULT    = 0x4000,
    GXV_FEAT_MASK_UNUSED             = 0x3F00,
    GXV_FEAT_MASK_DEFAULT_SETTING    = 0x00FF

  } GXV_FeatureFlagsMask;
