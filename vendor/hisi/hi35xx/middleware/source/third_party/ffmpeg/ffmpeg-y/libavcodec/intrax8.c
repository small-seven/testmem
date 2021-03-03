#include "libavutil/avassert.h"
#include "avcodec.h"
#include "get_bits.h"
#include "idctdsp.h"
#include "msmpeg4data.h"
#include "intrax8huf.h"
#include "intrax8.h"
#include "intrax8dsp.h"
#include "mpegutils.h"
#define MAX_TABLE_DEPTH(table_bits, max_bits) \
#define DC_VLC_BITS 9
#define AC_VLC_BITS 9
#define OR_VLC_BITS 7
#define DC_VLC_MTD MAX_TABLE_DEPTH(DC_VLC_BITS, MAX_DC_VLC_BITS)
#define AC_VLC_MTD MAX_TABLE_DEPTH(AC_VLC_BITS, MAX_AC_VLC_BITS)
#define OR_VLC_MTD MAX_TABLE_DEPTH(OR_VLC_BITS, MAX_OR_VLC_BITS)
#define init_ac_vlc(dst, src)                                                 \
#undef init_ac_vlc
#define init_dc_vlc(dst, src)                                                 \
#undef init_dc_vlc
#define init_or_vlc(dst, src)                                                 \
#undef init_or_vlc
#define extra_bits(eb)  (eb)        // 3 bits
#define extra_run       (0xFF << 8) // 1 bit
#define extra_level     (0x00 << 8) // 1 bit
#define run_offset(r)   ((r) << 16) // 6 bits
#define level_offset(l) ((l) << 24) // 5 bits
#undef extra_bits
#undef extra_run
#undef extra_level
#undef run_offset
#undef level_offset
#define B(x,y)  w->block[0][w->idct_permutation[(x) + (y) * 8]]
#define T(x)  ((x) * dc_level + 0x8000) >> 16;
#undef B
#undef T
