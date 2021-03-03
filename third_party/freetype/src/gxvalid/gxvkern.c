#include "gxvalid.h"
#include "gxvcommn.h"
#include FT_SFNT_NAMES_H
#include FT_SERVICE_GX_VALIDATE_H
#undef  FT_COMPONENT
#define FT_COMPONENT  gxvkern
  typedef enum  GXV_kern_Version_
  {
    KERN_VERSION_CLASSIC = 0x0000,
    KERN_VERSION_NEW     = 0x0001

  } GXV_kern_Version;
  typedef enum GXV_kern_Dialect_
  {
    KERN_DIALECT_UNKNOWN = 0,
    KERN_DIALECT_MS      = FT_VALIDATE_MS,
    KERN_DIALECT_APPLE   = FT_VALIDATE_APPLE,
    KERN_DIALECT_ANY     = FT_VALIDATE_CKERN

  } GXV_kern_Dialect;
  typedef struct  GXV_kern_DataRec_
  {
    GXV_kern_Version  version;
    void             *subtable_data;
    GXV_kern_Dialect  dialect_request;

  } GXV_kern_DataRec, *GXV_kern_Data;
#define GXV_KERN_DATA( field )  GXV_TABLE_DATA( kern, field )
#define KERN_IS_CLASSIC( gxvalid )                               \
#define KERN_IS_NEW( gxvalid )                                   \
#define KERN_DIALECT( gxvalid )              \
#define KERN_ALLOWS_MS( gxvalid )                       \
#define KERN_ALLOWS_APPLE( gxvalid )                       \
#define GXV_KERN_HEADER_SIZE           ( KERN_IS_NEW( gxvalid ) ? 8 : 4 )
#define GXV_KERN_SUBTABLE_HEADER_SIZE  ( KERN_IS_NEW( gxvalid ) ? 8 : 6 )
#ifdef GXV_LOAD_UNUSED_VARS
#endif
#ifdef GXV_LOAD_UNUSED_VARS
#else
#endif
  typedef struct  GXV_kern_fmt1_StateOptRec_
  {
    FT_UShort  valueTable;
    FT_UShort  valueTable_length;

  } GXV_kern_fmt1_StateOptRec, *GXV_kern_fmt1_StateOptRecData;
#ifdef GXV_LOAD_UNUSED_VARS
#endif
#ifdef GXV_LOAD_UNUSED_VARS
#endif
#ifdef GXV_LOAD_UNUSED_VARS
#endif
#ifdef GXV_LOAD_UNUSED_VARS
#endif
  typedef enum  GXV_kern_ClassSpec_
  {
    GXV_KERN_CLS_L = 0,
    GXV_KERN_CLS_R

  } GXV_kern_ClassSpec;
  typedef struct  GXV_kern_subtable_fmt2_DataRec_
  {
    FT_UShort         rowWidth;
    FT_UShort         array;
    FT_UShort         offset_min[2];
    FT_UShort         offset_max[2];
    const FT_String*  class_tag[2];
    GXV_odtect_Range  odtect;

  } GXV_kern_subtable_fmt2_DataRec, *GXV_kern_subtable_fmt2_Data;
#define GXV_KERN_FMT2_DATA( field )                         \
#ifdef GXV_LOAD_TRACE_VARS
#endif
#ifdef GXV_LOAD_TRACE_VARS
#endif
#ifdef GXV_LOAD_TRACE_VARS
#endif
#ifdef GXV_LOAD_TRACE_VARS
#endif
#ifdef GXV_LOAD_TRACE_VARS
#endif
#ifdef GXV_LOAD_TRACE_VARS
#endif
#ifdef GXV_LOAD_TRACE_VARS
#endif
#ifdef GXV_LOAD_TRACE_VARS
#endif
#ifdef GXV_LOAD_TRACE_VARS
#endif
#ifdef GXV_LOAD_TRACE_VARS
#endif
#ifdef GXV_LOAD_TRACE_VARS
#endif
#ifdef GXV_LOAD_TRACE_VARS
#endif
#ifdef GXV_LOAD_TRACE_VARS
#else
#endif
