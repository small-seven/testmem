#include <ft2build.h>
#include FT_INTERNAL_DEBUG_H
#include FT_INTERNAL_STREAM_H
#include FT_TRUETYPE_TAGS_H
#include FT_BITMAP_H
#ifdef TT_CONFIG_OPTION_EMBEDDED_BITMAPS
#include "ttsbit.h"
#include "sferrors.h"
#include "ttmtx.h"
#include "pngshim.h"
#undef  FT_COMPONENT
#define FT_COMPONENT  ttsbit
#if 0
#endif
  typedef struct  TT_SBitDecoderRec_
  {
    TT_Face          face;
    FT_Stream        stream;
    FT_Bitmap*       bitmap;
    TT_SBit_Metrics  metrics;
    FT_Bool          metrics_loaded;
    FT_Bool          bitmap_allocated;
    FT_Byte          bit_depth;

    FT_ULong         ebdt_start;
    FT_ULong         ebdt_size;

    FT_ULong         strike_index_array;
    FT_ULong         strike_index_count;
    FT_Byte*         eblc_base;
    FT_Byte*         eblc_limit;

  } TT_SBitDecoderRec, *TT_SBitDecoder;
  typedef FT_Error  (*TT_SBitDecoder_LoadFunc)(
                      TT_SBitDecoder  decoder,
                      FT_Byte*        p,
                      FT_Byte*        plimit,
                      FT_Int          x_pos,
                      FT_Int          y_pos,
                      FT_UInt         recurse_count );


  static FT_Error
  tt_sbit_decoder_load_byte_aligned( TT_SBitDecoder  decoder,
                                     FT_Byte*        p,
                                     FT_Byte*        limit,
                                     FT_Int          x_pos,
                                     FT_Int          y_pos,
                                     FT_UInt         recurse_count )
  {
    FT_Error    error = FT_Err_Ok;
    FT_Byte*    line;
    FT_Int      pitch, width, height, line_bits, h;
    FT_UInt     bit_height, bit_width;
    FT_Bitmap*  bitmap;

    FT_UNUSED( recurse_count );


    /* check that we can write the glyph into the bitmap */
    bitmap     = decoder->bitmap;
    bit_width  = bitmap->width;
    bit_height = bitmap->rows;
    pitch      = bitmap->pitch;
    line       = bitmap->buffer;

    width  = decoder->metrics->width;
    height = decoder->metrics->height;

    line_bits = width * decoder->bit_depth;

    if ( x_pos < 0 || (FT_UInt)( x_pos + width ) > bit_width   ||
         y_pos < 0 || (FT_UInt)( y_pos + height ) > bit_height )
    {
      FT_TRACE1(( "tt_sbit_decoder_load_byte_aligned:"
                  " invalid bitmap dimensions\n" ));
      error = FT_THROW( Invalid_File_Format );
      goto Exit;
    }
#ifdef FT_CONFIG_OPTION_USE_PNG
#endif /* FT_CONFIG_OPTION_USE_PNG */
#ifdef FT_CONFIG_OPTION_USE_PNG
#else
#endif /* FT_CONFIG_OPTION_USE_PNG */
#ifndef FT_CONFIG_OPTION_USE_PNG
#endif
#ifdef FT_CONFIG_OPTION_USE_PNG
#else
#endif
#else /* !TT_CONFIG_OPTION_EMBEDDED_BITMAPS */
