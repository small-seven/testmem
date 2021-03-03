#undef  FT_COMPONENT
#define FT_COMPONENT  smooth
#ifdef STANDALONE_
#define FT_RENDER_POOL_SIZE  16384L
#define FT_ERR_XCAT( x, y )  x ## y
#define FT_ERR_CAT( x, y )   FT_ERR_XCAT( x, y )
#define FT_BEGIN_STMNT  do {
#define FT_END_STMNT    } while ( 0 )
#define FT_MIN( a, b )  ( (a) < (b) ? (a) : (b) )
#define FT_MAX( a, b )  ( (a) > (b) ? (a) : (b) )
#define FT_ABS( a )     ( (a) < 0 ? -(a) : (a) )
#define FT_HYPOT( x, y )                 \
#ifdef FT_DEBUG_LEVEL_TRACE
#include <stdio.h>
#include <stdarg.h>
#endif
#include <stddef.h>
#include <string.h>
#include <setjmp.h>
#include <limits.h>
#define FT_CHAR_BIT   CHAR_BIT
#define FT_UINT_MAX   UINT_MAX
#define FT_INT_MAX    INT_MAX
#define FT_ULONG_MAX  ULONG_MAX
#define ADD_LONG( a, b )                                    \
#define SUB_LONG( a, b )                                    \
#define MUL_LONG( a, b )                                    \
#define NEG_LONG( a )                                       \
#define ft_memset   memset
#define ft_setjmp   setjmp
#define ft_longjmp  longjmp
#define ft_jmp_buf  jmp_buf
typedef ptrdiff_t  FT_PtrDist;


#define ErrRaster_Invalid_Mode      -2
#define ErrRaster_Invalid_Outline   -1
#define ErrRaster_Invalid_Argument  -3
#define ErrRaster_Memory_Overflow   -4

#define FT_BEGIN_HEADER
#define FT_END_HEADER

#include "ftimage.h"
#include "ftgrays.h"


  /* This macro is used to indicate that a function parameter is unused. */
  /* Its purpose is simply to reduce compiler warnings.  Note also that  */
  /* simply defining it as `(void)x' doesn't avoid warnings with certain */
  /* ANSI compilers (e.g. LCC).                                          */
#define FT_UNUSED( x )  (x) = (x)


  /* we only use level 5 & 7 tracing messages; cf. ftdebug.h */

#ifdef FT_DEBUG_LEVEL_TRACE

  void
  FT_Message( const char*  fmt,
              ... )
  {
    va_list  ap;


    va_start( ap, fmt );
    vfprintf( stderr, fmt, ap );
    va_end( ap );
  }
#ifndef FT_TRACE5
#define FT_TRACE5( varformat )  FT_Message varformat
#endif
#ifndef FT_TRACE7
#define FT_TRACE7( varformat )  FT_Message varformat
#endif
#ifndef FT_ERROR
#define FT_ERROR( varformat )   FT_Message varformat
#endif
#define FT_THROW( e )                               \
#else /* !FT_DEBUG_LEVEL_TRACE */
#define FT_TRACE5( x )  do { } while ( 0 )     /* nothing */
#define FT_TRACE7( x )  do { } while ( 0 )     /* nothing */
#define FT_ERROR( x )   do { } while ( 0 )     /* nothing */
#define FT_THROW( e )   FT_ERR_CAT( ErrRaster_, e )
#endif /* !FT_DEBUG_LEVEL_TRACE */
#define FT_DEFINE_OUTLINE_FUNCS( class_,               \
#define FT_DEFINE_RASTER_FUNCS( class_, glyph_format_,            \
#else /* !STANDALONE_ */
#include <ft2build.h>
#include "ftgrays.h"
#include FT_INTERNAL_OBJECTS_H
#include FT_INTERNAL_DEBUG_H
#include FT_INTERNAL_CALC_H
#include FT_OUTLINE_H
#include "ftsmerrs.h"
#define Smooth_Err_Invalid_Mode     Smooth_Err_Cannot_Render_Glyph
#define Smooth_Err_Memory_Overflow  Smooth_Err_Out_Of_Memory
#define ErrRaster_Memory_Overflow   Smooth_Err_Out_Of_Memory
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
#undef RAS_ARG
#undef RAS_ARG_
#undef RAS_VAR
#undef RAS_VAR_
#ifndef FT_STATIC_RASTER
#define RAS_ARG   gray_PWorker  worker
#define RAS_ARG_  gray_PWorker  worker,
#define RAS_VAR   worker
#define RAS_VAR_  worker,
#else /* FT_STATIC_RASTER */
#define RAS_ARG   void
#define RAS_ARG_  /* empty */
#define RAS_VAR   /* empty */
#define RAS_VAR_  /* empty */
#endif /* FT_STATIC_RASTER */
#define PIXEL_BITS  8
#define ONE_PIXEL       ( 1 << PIXEL_BITS )
#define TRUNC( x )      (TCoord)( (x) >> PIXEL_BITS )
#define FRACT( x )      (TCoord)( (x) & ( ONE_PIXEL - 1 ) )
#if PIXEL_BITS >= 6
#define UPSCALE( x )    ( (x) * ( ONE_PIXEL >> 6 ) )
#define DOWNSCALE( x )  ( (x) >> ( PIXEL_BITS - 6 ) )
#else
#define UPSCALE( x )    ( (x) >> ( 6 - PIXEL_BITS ) )
#define DOWNSCALE( x )  ( (x) * ( 64 >> PIXEL_BITS ) )
#endif
#define FT_DIV_MOD( type, dividend, divisor, quotient, remainder ) \
#ifdef  __arm__
#undef FT_DIV_MOD
#define FT_DIV_MOD( type, dividend, divisor, quotient, remainder ) \
#endif /* __arm__ */
#define FT_UDIVPREP( c, b )                                        \
#define FT_UDIV( a, b )                                                \
  typedef long  TPos;     /* subpixel coordinate               */
  typedef int   TCoord;   /* integer scanline/pixel coordinate */
  typedef int   TArea;    /* cell areas, coordinate products   */


  typedef struct TCell_*  PCell;

  typedef struct  TCell_
  {
    TCoord  x;     /* same with gray_TWorker.ex    */
    TCoord  cover; /* same with gray_TWorker.cover */
    TArea   area;
    PCell   next;

  } TCell;
  typedef struct TPixmap_
  {
    unsigned char*  origin;  /* pixmap origin at the bottom-left */
    int             pitch;   /* pitch to go down one row */

  } TPixmap;
#if FT_RENDER_POOL_SIZE > 2048
#define FT_MAX_GRAY_POOL  ( FT_RENDER_POOL_SIZE / sizeof ( TCell ) )
#else
#define FT_MAX_GRAY_POOL  ( 2048 / sizeof ( TCell ) )
#endif
#define FT_MAX_GRAY_SPANS  10
#if defined( _MSC_VER )      /* Visual C++ (and Intel C++) */
#pragma warning( push )
#pragma warning( disable : 4324 )
#endif /* _MSC_VER */
  typedef struct  gray_TWorker_
  {
    ft_jmp_buf  jump_buffer;

    TCoord  ex, ey;
    TCoord  min_ex, max_ex;
    TCoord  min_ey, max_ey;

    TArea   area;
    TCoord  cover;
    int     invalid;

    PCell*      ycells;
    PCell       cells;
    FT_PtrDist  max_cells;
    FT_PtrDist  num_cells;

    TPos    x,  y;

    FT_Outline  outline;
    TPixmap     target;

    FT_Raster_Span_Func  render_span;
    void*                render_span_data;
    FT_Span              spans[FT_MAX_GRAY_SPANS];
    int                  num_spans;

  } gray_TWorker, *gray_PWorker;
#if defined( _MSC_VER )
#pragma warning( pop )
#endif
#ifndef FT_STATIC_RASTER
#define ras  (*worker)
#else
#endif
  typedef struct gray_TRaster_
  {
    void*         memory;

  } gray_TRaster, *gray_PRaster;
#ifdef FT_DEBUG_LEVEL_TRACE
#endif /* FT_DEBUG_LEVEL_TRACE */
#ifndef FT_LONG64
#else
#endif
#ifdef STANDALONE_
#undef SCALED
#define SCALED( x )  ( (x) * ( 1L << shift ) - delta )
#endif /* STANDALONE_ */
#ifndef FT_STATIC_RASTER
#endif
#ifdef STANDALONE_
#else /* !STANDALONE_ */
#endif /* !STANDALONE_ */
