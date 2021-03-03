#include <ft2build.h>
#include FT_WINFONTS_H
#include FT_INTERNAL_DEBUG_H
#include FT_INTERNAL_STREAM_H
#include FT_INTERNAL_OBJECTS_H
#include FT_TRUETYPE_IDS_H
#include "winfnt.h"
#include "fnterrs.h"
#include FT_SERVICE_WINFNT_H
#include FT_SERVICE_FONT_FORMAT_H
#undef  FT_COMPONENT
#define FT_COMPONENT  winfnt
#undef  FT_STRUCTURE
#define FT_STRUCTURE  WinMZ_HeaderRec
#undef  FT_STRUCTURE
#define FT_STRUCTURE  WinNE_HeaderRec
#undef  FT_STRUCTURE
#define FT_STRUCTURE  WinPE32_HeaderRec
#undef  FT_STRUCTURE
#define FT_STRUCTURE  WinPE32_SectionRec
#undef  FT_STRUCTURE
#define FT_STRUCTURE  WinPE_RsrcDirRec
#undef  FT_STRUCTURE
#define FT_STRUCTURE  WinPE_RsrcDirEntryRec
#undef  FT_STRUCTURE
#define FT_STRUCTURE  WinPE_RsrcDataEntryRec
#undef  FT_STRUCTURE
#define FT_STRUCTURE  FT_WinFNT_HeaderRec
  typedef struct  FNT_CMapRec_
  {
    FT_CMapRec  cmap;
    FT_UInt32   first;
    FT_UInt32   count;

  } FNT_CMapRec, *FNT_CMap;
