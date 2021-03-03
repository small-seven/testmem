#include <ft2build.h>
#include FT_INTERNAL_DEBUG_H
#include FT_CONFIG_CONFIG_H
#include FT_INTERNAL_CALC_H
#include FT_INTERNAL_STREAM_H
#include FT_INTERNAL_SFNT_H
#include FT_TRUETYPE_TAGS_H
#include FT_OUTLINE_H
#include FT_DRIVER_H
#include FT_LIST_H
#include "ttgload.h"
#include "ttpload.h"
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
#include "ttgxvar.h"
#endif
#include "tterrors.h"
#include "ttsubpix.h"
#undef  FT_COMPONENT
#define FT_COMPONENT  ttgload
#define ON_CURVE_POINT  0x01  /* same value as FT_CURVE_TAG_ON            */
#define X_SHORT_VECTOR  0x02
#define Y_SHORT_VECTOR  0x04
#define REPEAT_FLAG     0x08
#define X_POSITIVE      0x10  /* two meanings depending on X_SHORT_VECTOR */
#define SAME_X          0x10
#define Y_POSITIVE      0x20  /* two meanings depending on Y_SHORT_VECTOR */
#define SAME_Y          0x20
#define OVERLAP_SIMPLE  0x40  /* we ignore this value                     */
#define ARGS_ARE_WORDS             0x0001
#define ARGS_ARE_XY_VALUES         0x0002
#define ROUND_XY_TO_GRID           0x0004
#define WE_HAVE_A_SCALE            0x0008
#define MORE_COMPONENTS            0x0020
#define WE_HAVE_AN_XY_SCALE        0x0040
#define WE_HAVE_A_2X2              0x0080
#define WE_HAVE_INSTR              0x0100
#define USE_MY_METRICS             0x0200
#define OVERLAP_COMPOUND           0x0400  /* we ignore this value */
#define SCALED_COMPONENT_OFFSET    0x0800
#define UNSCALED_COMPONENT_OFFSET  0x1000
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
#define IS_DEFAULT_INSTANCE( _face )             \
#else
#define IS_DEFAULT_INSTANCE( _face )  1
#endif
#ifdef TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY
#endif
#ifdef TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY
#endif /* TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY */
#ifdef FT_CONFIG_OPTION_INCREMENTAL
#if 0
#endif /* 0 */
#endif /* FT_CONFIG_OPTION_INCREMENTAL */
#ifdef TT_USE_BYTECODE_INTERPRETER
#endif /* TT_USE_BYTECODE_INTERPRETER */
#ifdef FT_DEBUG_LEVEL_TRACE
#endif /* FT_DEBUG_LEVEL_TRACE */
#ifdef TT_USE_BYTECODE_INTERPRETER
#endif
#if defined TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY || \
#endif
#ifdef TT_USE_BYTECODE_INTERPRETER
#else
#endif
#ifdef TT_USE_BYTECODE_INTERPRETER
#endif
#ifdef TT_USE_BYTECODE_INTERPRETER
#endif
#ifdef TT_SUPPORT_SUBPIXEL_HINTING_MINIMAL
#endif
#ifdef TT_SUPPORT_SUBPIXEL_HINTING_MINIMAL
#endif
#ifdef TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY
#endif /* TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY */
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
#endif
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
#endif /* TT_CONFIG_OPTION_GX_VAR_SUPPORT */
#ifdef TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY
#endif
#ifdef TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
#endif
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
#endif
#endif /* TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY */
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
#endif /* TT_CONFIG_OPTION_GX_VAR_SUPPORT */
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
#endif
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
#endif
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
#endif
#ifdef TT_CONFIG_OPTION_COMPONENT_OFFSET_SCALED
#else
#endif
#if 0
#else /* 1 */
#endif /* 1 */
#ifdef TT_USE_BYTECODE_INTERPRETER
#endif
#ifdef TT_CONFIG_OPTION_SUBPIXEL_HINTING
#endif
#ifdef TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY
#endif
#ifdef TT_SUPPORT_SUBPIXEL_HINTING_MINIMAL
#endif
#ifdef FT_CONFIG_OPTION_INCREMENTAL
#endif
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
#ifndef FT_CONFIG_OPTION_INCREMENTAL
#endif
#ifdef FT_CONFIG_OPTION_INCREMENTAL
#endif /* FT_CONFIG_OPTION_INCREMENTAL */
#ifdef FT_CONFIG_OPTION_INCREMENTAL
#else
#endif /* FT_CONFIG_OPTION_INCREMENTAL */
#ifdef FT_CONFIG_OPTION_INCREMENTAL
#endif
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
#endif /* TT_CONFIG_OPTION_GX_VAR_SUPPORT */
#ifdef FT_CONFIG_OPTION_INCREMENTAL
#endif
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
#endif /* TT_CONFIG_OPTION_GX_VAR_SUPPORT */
#ifdef TT_USE_BYTECODE_INTERPRETER
#endif
#ifdef FT_CONFIG_OPTION_INCREMENTAL
#endif
#if defined TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY || \
#endif
#ifdef TT_SUPPORT_SUBPIXEL_HINTING_MINIMAL
#endif
#ifdef TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY
#endif /* TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY */
#ifdef FT_CONFIG_OPTION_INCREMENTAL
#endif /* FT_CONFIG_OPTION_INCREMENTAL */
#ifdef TT_CONFIG_OPTION_EMBEDDED_BITMAPS
#endif /* TT_CONFIG_OPTION_EMBEDDED_BITMAPS */
#ifdef TT_USE_BYTECODE_INTERPRETER
#if defined TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY || \
#endif
#endif
#ifdef TT_USE_BYTECODE_INTERPRETER
#ifdef TT_SUPPORT_SUBPIXEL_HINTING_MINIMAL
#endif
#ifdef TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY
#if 0
#endif
#endif /* TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY */
#ifdef TT_SUPPORT_SUBPIXEL_HINTING_MINIMAL
#endif
#ifdef TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY
#if 1
#else /* 0 */
#endif /* 0 */
#endif /* TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY */
#ifdef TT_SUPPORT_SUBPIXEL_HINTING_MINIMAL
#endif
#ifdef TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY
#endif /* TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY */
#ifdef TT_SUPPORT_SUBPIXEL_HINTING_MINIMAL
#endif
#ifdef TT_SUPPORT_SUBPIXEL_HINTING_INFINALITY
#endif
#endif /* TT_USE_BYTECODE_INTERPRETER */
#ifdef TT_CONFIG_OPTION_EMBEDDED_BITMAPS
#endif /* TT_CONFIG_OPTION_EMBEDDED_BITMAPS */
#ifdef TT_USE_BYTECODE_INTERPRETER
#endif /* TT_USE_BYTECODE_INTERPRETER */
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
