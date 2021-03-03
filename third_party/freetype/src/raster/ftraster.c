#ifdef STANDALONE_
#define FT_RENDER_POOL_SIZE  16384L
#define FT_CONFIG_STANDARD_LIBRARY_H  <stdlib.h>
#include <string.h>           /* for memset */
#include "ftmisc.h"
#include "ftimage.h"
#else /* !STANDALONE_ */
#include <ft2build.h>
#include "ftraster.h"
#include FT_INTERNAL_CALC_H   /* for FT_MulDiv and FT_MulDiv_No_Round */
#include FT_OUTLINE_H         /* for FT_Outline_Get_CBox              */
#endif /* !STANDALONE_ */
#undef  FT_COMPONENT
#define FT_COMPONENT  raster
#ifdef STANDALONE_
#define FT_ERR_XCAT( x, y )  x ## y
#define FT_ERR_CAT( x, y )   FT_ERR_XCAT( x, y )
#define FT_UNUSED( x )  (x) = (x)
#ifndef FT_ERROR
#define FT_ERROR( x )  do { } while ( 0 )     /* nothing */
#endif
#ifndef FT_TRACE
#define FT_TRACE( x )   do { } while ( 0 )    /* nothing */
#define FT_TRACE1( x )  do { } while ( 0 )    /* nothing */
#define FT_TRACE6( x )  do { } while ( 0 )    /* nothing */
#define FT_TRACE7( x )  do { } while ( 0 )    /* nothing */
#endif
#ifndef FT_THROW
#define FT_THROW( e )  FT_ERR_CAT( Raster_Err_, e )
#endif
#define Raster_Err_None          0
#define Raster_Err_Not_Ini      -1
#define Raster_Err_Overflow     -2
#define Raster_Err_Neg_Height   -3
#define Raster_Err_Invalid      -4
#define Raster_Err_Unsupported  -5
#define ft_memset  memset
#define FT_DEFINE_RASTER_FUNCS( class_, glyph_format_, raster_new_, \
#else /* !STANDALONE_ */
#include FT_INTERNAL_OBJECTS_H
#include FT_INTERNAL_DEBUG_H       /* for FT_TRACE, FT_ERROR, and FT_THROW */
#include "rasterrs.h"
#define Raster_Err_None         FT_Err_Ok
#define Raster_Err_Not_Ini      Raster_Err_Raster_Uninitialized
#define Raster_Err_Overflow     Raster_Err_Raster_Overflow
#define Raster_Err_Neg_Height   Raster_Err_Raster_Negative_Height
#define Raster_Err_Invalid      Raster_Err_Invalid_Outline
#define Raster_Err_Unsupported  Raster_Err_Cannot_Render_Glyph
#endif /* !STANDALONE_ */
#ifndef FT_MEM_SET
#define FT_MEM_SET( d, s, c )  ft_memset( d, s, c )
#endif
#ifndef FT_MEM_ZERO
#define FT_MEM_ZERO( dest, count )  FT_MEM_SET( dest, 0, count )
#endif
#ifndef FT_ZERO
#define FT_ZERO( p )  FT_MEM_ZERO( p, sizeof ( *(p) ) )
#endif
#define FMulDiv( a, b, c )  ( (a) * (b) / (c) )
#define SMulDiv           FT_MulDiv
#define SMulDiv_No_Round  FT_MulDiv_No_Round
#ifndef TRUE
#define TRUE   1
#endif
#ifndef FALSE
#define FALSE  0
#endif
#ifndef NULL
#define NULL  (void*)0
#endif
#ifndef SUCCESS
#define SUCCESS  0
#endif
#ifndef FAILURE
#define FAILURE  1
#endif
#define MaxBezier  32   /* The maximum number of stacked Bezier curves. */
#define Pixel_Bits  6   /* fractional bits of *input* coordinates */
  typedef int             Int;
  typedef unsigned int    UInt;
  typedef short           Short;
  typedef unsigned short  UShort, *PUShort;
  typedef long            Long, *PLong;
  typedef unsigned long   ULong;

  typedef unsigned char   Byte, *PByte;
  typedef char            Bool;


  typedef union  Alignment_
  {
    Long    l;
    void*   p;
    void  (*f)(void);

  } Alignment, *PAlignment;
  typedef struct  TPoint_
  {
    Long  x;
    Long  y;

  } TPoint;
#define Flow_Up           0x08U
#define Overshoot_Top     0x10U
#define Overshoot_Bottom  0x20U
  typedef enum  TStates_
  {
    Unknown_State,
    Ascending_State,
    Descending_State,
    Flat_State

  } TStates;
  typedef struct TProfile_  TProfile;
  typedef TProfile*         PProfile;

  struct  TProfile_
  {
    FT_F26Dot6  X;           /* current coordinate during sweep          */
    PProfile    link;        /* link to next profile (various purposes)  */
    PLong       offset;      /* start of profile's data in render pool   */
    UShort      flags;       /* Bit 0-2: drop-out mode                   */
                             /* Bit 3: profile orientation (up/down)     */
                             /* Bit 4: is top profile?                   */
                             /* Bit 5: is bottom profile?                */
    Long        height;      /* profile's height in scanlines            */
    Long        start;       /* profile's starting scanline              */

    Int         countL;      /* number of lines to step before this      */
                             /* profile becomes drawable                 */

    PProfile    next;        /* next profile in same contour, used       */
                             /* during drop-out control                  */
  };
  typedef PProfile   TProfileList;
  typedef PProfile*  PProfileList;


  /* Simple record used to implement a stack of bands, required */
  /* by the sub-banding mechanism                               */
  typedef struct  black_TBand_
  {
    Short  y_min;   /* band's minimum */
    Short  y_max;   /* band's maximum */

  } black_TBand;
#define AlignProfileSize \
#undef RAS_ARG
#undef RAS_ARGS
#undef RAS_VAR
#undef RAS_VARS
#ifdef FT_STATIC_RASTER
#define RAS_ARGS       /* void */
#define RAS_ARG        void
#define RAS_VARS       /* void */
#define RAS_VAR        /* void */
#define FT_UNUSED_RASTER  do { } while ( 0 )
#else /* !FT_STATIC_RASTER */
#define RAS_ARGS       black_PWorker  worker,
#define RAS_ARG        black_PWorker  worker
#define RAS_VARS       worker,
#define RAS_VAR        worker
#define FT_UNUSED_RASTER  FT_UNUSED( worker )
#endif /* !FT_STATIC_RASTER */
  typedef struct black_TWorker_  black_TWorker, *black_PWorker;


  /* prototypes used for sweep function dispatch */
  typedef void
  Function_Sweep_Init( RAS_ARGS Short*  min,
                                Short*  max );

  typedef void
  Function_Sweep_Span( RAS_ARGS Short       y,
                                FT_F26Dot6  x1,
                                FT_F26Dot6  x2,
                                PProfile    left,
                                PProfile    right );

  typedef void
  Function_Sweep_Step( RAS_ARG );


  /* NOTE: These operations are only valid on 2's complement processors */
#undef FLOOR
#undef CEILING
#undef TRUNC
#undef SCALED

#define FLOOR( x )    ( (x) & -ras.precision )
#define CEILING( x )  ( ( (x) + ras.precision - 1 ) & -ras.precision )
#define TRUNC( x )    ( (Long)(x) >> ras.precision_bits )
#define FRAC( x )     ( (x) & ( ras.precision - 1 ) )

  /* scale and shift grid to pixel centers */
#define SCALED( x )   ( (x) * ras.precision_scale - ras.precision_half )

#define IS_BOTTOM_OVERSHOOT( x ) \
          (Bool)( CEILING( x ) - x >= ras.precision_half )
#define IS_TOP_OVERSHOOT( x )    \
          (Bool)( x - FLOOR( x ) >= ras.precision_half )

#if FT_RENDER_POOL_SIZE > 2048
#define FT_MAX_BLACK_POOL  ( FT_RENDER_POOL_SIZE / sizeof ( Long ) )
#else
#define FT_MAX_BLACK_POOL  ( 2048 / sizeof ( Long ) )
#endif

  /* The most used variables are positioned at the top of the structure. */
  /* Thus, their offset can be coded with less opcodes, resulting in a   */
  /* smaller executable.                                                 */

  struct  black_TWorker_
  {
    Int         precision_bits;     /* precision related variables         */
    Int         precision;
    Int         precision_half;
    Int         precision_scale;
    Int         precision_step;
    Int         precision_jitter;

    PLong       buff;               /* The profiles buffer                 */
    PLong       sizeBuff;           /* Render pool size                    */
    PLong       maxBuff;            /* Profiles buffer size                */
    PLong       top;                /* Current cursor in buffer            */

    FT_Error    error;

    Int         numTurns;           /* number of Y-turns in outline        */

    TPoint*     arc;                /* current Bezier arc pointer          */

    UShort      bWidth;             /* target bitmap width                 */
    PByte       bOrigin;            /* target bitmap bottom-left origin    */

    Long        lastX, lastY;
    Long        minY, maxY;

    UShort      num_Profs;          /* current number of profiles          */

    Bool        fresh;              /* signals a fresh new profile which   */
                                    /* `start' field must be completed     */
    Bool        joint;              /* signals that the last arc ended     */
                                    /* exactly on a scanline.  Allows      */
                                    /* removal of doublets                 */
    PProfile    cProfile;           /* current profile                     */
    PProfile    fProfile;           /* head of linked list of profiles     */
    PProfile    gProfile;           /* contour's first profile in case     */
                                    /* of impact                           */

    TStates     state;              /* rendering state                     */

    FT_Bitmap   target;             /* description of target bit/pixmap    */
    FT_Outline  outline;

    Long        traceOfs;           /* current offset in target bitmap     */
    Short       traceIncr;          /* sweep's increment in target bitmap  */

    /* dispatch variables */

    Function_Sweep_Init*  Proc_Sweep_Init;
    Function_Sweep_Span*  Proc_Sweep_Span;
    Function_Sweep_Span*  Proc_Sweep_Drop;
    Function_Sweep_Step*  Proc_Sweep_Step;

    Byte        dropOutControl;     /* current drop_out control method     */

    Bool        second_pass;        /* indicates whether a horizontal pass */
                                    /* should be performed to control      */
                                    /* drop-out accurately when calling    */
                                    /* Render_Glyph.                       */

    TPoint      arcs[3 * MaxBezier + 1]; /* The Bezier stack               */

    black_TBand  band_stack[16];    /* band stack used for sub-banding     */
    Int          band_top;          /* band stack top                      */

  };
  typedef struct  black_TRaster_
  {
    void*          memory;

  } black_TRaster, *black_PRaster;
#ifdef FT_STATIC_RASTER
#else /* !FT_STATIC_RASTER */
#define ras  (*worker)
#endif /* !FT_STATIC_RASTER */
  typedef void  (*TSplitter)( TPoint*  base );


  /**************************************************************************
   *
   * @Function:
   *   Bezier_Up
   *
   * @Description:
   *   Compute the x-coordinates of an ascending Bezier arc and store
   *   them in the render pool.
   *
   * @Input:
   *   degree ::
   *     The degree of the Bezier arc (either 2 or 3).
   *
   *   splitter ::
   *     The function to split Bezier arcs.
   *
   *   miny ::
   *     A lower vertical clipping bound value.
   *
   *   maxy ::
   *     An upper vertical clipping bound value.
   *
   * @Return:
   *   SUCCESS on success, FAILURE on render pool overflow.
   */
  static Bool
  Bezier_Up( RAS_ARGS Int        degree,
                      TSplitter  splitter,
                      Long       miny,
                      Long       maxy )
  {
    Long   y1, y2, e, e2, e0;
    Short  f1;

    TPoint*  arc;
    TPoint*  start_arc;

    PLong top;


    arc = ras.arc;
    y1  = arc[degree].y;
    y2  = arc[0].y;
    top = ras.top;

    if ( y2 < miny || y1 > maxy )
      goto Fin;

    e2 = FLOOR( y2 );

    if ( e2 > maxy )
      e2 = maxy;

    e0 = miny;

    if ( y1 < miny )
      e = miny;
    else
    {
      e  = CEILING( y1 );
      f1 = (Short)( FRAC( y1 ) );
      e0 = e;

      if ( f1 == 0 )
      {
        if ( ras.joint )
        {
          top--;
          ras.joint = FALSE;
        }
#undef  SWAP_
#define SWAP_( x, y )  do                \
#if 0
#endif
#ifdef STANDALONE_
#endif /* STANDALONE_ */
#ifdef DEBUG_RASTER
#endif
#ifdef STANDALONE_
#else /* !STANDALONE_ */
#endif /* !STANDALONE_ */
#ifndef FT_STATIC_RASTER
#endif
