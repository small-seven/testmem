#include "deflate.h"
#include <u-boot/crc.h>
typedef enum {
    need_more,      /* block not completed, need more input or more output */
    block_done,     /* block flush performed */
    finish_started, /* finish started, need only more output at next deflate */
    finish_done     /* finish done, accept no more input or output */
} block_state;
typedef block_state (*compress_func) OF((deflate_state *s, int flush));
/* Compression function. Returns the block state after the call. */

local void fill_window    OF((deflate_state *s));
local block_state deflate_stored OF((deflate_state *s, int flush));
local block_state deflate_fast   OF((deflate_state *s, int flush));
#ifndef FASTEST
local block_state deflate_slow   OF((deflate_state *s, int flush));
#endif
local block_state deflate_rle    OF((deflate_state *s, int flush));
local block_state deflate_huff   OF((deflate_state *s, int flush));
local void lm_init        OF((deflate_state *s));
local void putShortMSB    OF((deflate_state *s, uInt b));
local void flush_pending  OF((z_streamp strm));
local int read_buf        OF((z_streamp strm, Bytef *buf, unsigned size));
#ifdef ASMV
      void match_init OF((void)); /* asm code initialization */
      uInt longest_match  OF((deflate_state *s, IPos cur_match));
#else
local uInt longest_match  OF((deflate_state *s, IPos cur_match));
#endif

#ifdef DEBUG
local  void check_match OF((deflate_state *s, IPos start, IPos match,
                            int length));
#endif

/* ===========================================================================
 * Local data
 */

#define NIL 0
/* Tail of hash chains */

#ifndef TOO_FAR
#  define TOO_FAR 4096
#endif
/* Matches of length 3 are discarded if their distance exceeds TOO_FAR */

/* Values for max_lazy_match, good_match and max_chain_length, depending on
 * the desired pack level (0..9). The values given below have been tuned to
 * exclude worst case performance for pathological files. Better values may be
 * found for specific files.
 */
typedef struct config_s {
   ush good_length; /* reduce lazy search above this match length */
   ush max_lazy;    /* do not perform lazy search above this match length */
   ush nice_length; /* quit search above this match length */
   ush max_chain;
   compress_func func;
} config;
#ifdef FASTEST
#else
#endif
#define EQUAL 0
#ifndef NO_DUMMY_DECL
#endif
#define UPDATE_HASH(s,h,c) (h = (((h)<<s->hash_shift) ^ (c)) & s->hash_mask)
#ifdef FASTEST
#define INSERT_STRING(s, str, match_head) \
#else
#define INSERT_STRING(s, str, match_head) \
#endif
#define CLEAR_HASH(s) \
#ifdef FASTEST
#else
#endif
#ifdef GZIP
#endif
#ifdef GZIP
#endif
#ifdef FASTEST
#else
#endif
#ifdef GZIP
#endif
#ifdef GZIP
#endif
#ifdef GZIP
#endif
#ifdef MAXSEG_64K
#else
#endif /* MAXSEG_64K */
#ifdef GZIP
#endif
#ifndef FASTEST
#ifdef ASMV
#endif
#endif
#ifndef FASTEST
#ifndef ASMV
#ifdef UNALIGNED_OK
#else
#endif
#if (defined(UNALIGNED_OK) && MAX_MATCH == 258)
#else /* UNALIGNED_OK */
#endif /* UNALIGNED_OK */
#ifdef UNALIGNED_OK
#else
#endif
#endif /* ASMV */
#else /* FASTEST */
#endif /* FASTEST */
#ifdef DEBUG
#else
#  define check_match(s, start, match, length)
#endif /* DEBUG */
#ifndef FASTEST
#endif
#if MIN_MATCH != 3
#endif
#define FLUSH_BLOCK_ONLY(s, last) { \
#define FLUSH_BLOCK(s, last) { \
#ifndef FASTEST
#endif
#if MIN_MATCH != 3
#endif
#ifndef FASTEST
#if TOO_FAR <= 32767
#endif
#endif /* FASTEST */
