#define FEATREG_MAX_SETTING  12
#include <stdio.h>
#include <string.h>
#define APPLE_RESERVED         "Apple Reserved"
#define APPLE_RESERVED_LENGTH  14
  typedef struct  GX_Feature_RegistryRec_
  {
    const char*  feat_name;
    char         exclusive;
    char*        setting_name[FEATREG_MAX_SETTING];

  } GX_Feature_RegistryRec;
#define EMPTYFEAT {0, 0, {NULL}}
