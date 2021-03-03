#include <ft2build.h>
#include FT_INTERNAL_DEBUG_H
#include FT_INTERNAL_OBJECTS_H
#include FT_INTERNAL_STREAM_H
#include "cidparse.h"
#include "ciderrs.h"
#undef  FT_COMPONENT
#define FT_COMPONENT  cidparse
#define STARTDATA      "StartData"
#define STARTDATA_LEN  ( sizeof ( STARTDATA ) - 1 )
#define SFNTS          "/sfnts"
#define SFNTS_LEN      ( sizeof ( SFNTS ) - 1 )
#undef STARTDATA
#undef STARTDATA_LEN
#undef SFNTS
#undef SFNTS_LEN
