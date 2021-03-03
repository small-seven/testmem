#include "deflate.h"
#ifdef ZLIB_DEBUG
#  include <ctype.h>
#endif
#define MAX_BL_BITS 7
#define END_BLOCK 256
#define REP_3_6      16
#define REPZ_3_10    17
#define REPZ_11_138  18
#define DIST_CODE_LEN  512 /* see definition of array dist_code below */
#if defined(GEN_TREES_H) || !defined(STDC)
#else
#  include "trees.h"
#endif /* GEN_TREES_H */
#ifdef GEN_TREES_H
#endif
#ifndef ZLIB_DEBUG
#  define send_code(s, c, tree) send_bits(s, tree[c].Code, tree[c].Len)
#else /* !ZLIB_DEBUG */
#  define send_code(s, c, tree) \
#endif
#define put_short(s, w) { \
#ifdef ZLIB_DEBUG
#else /* !ZLIB_DEBUG */
#define send_bits(s, value, length) \
#endif /* ZLIB_DEBUG */
#if defined(GEN_TREES_H) || !defined(STDC)
#ifdef NO_INIT_GLOBAL_POINTERS
#endif
#  ifdef GEN_TREES_H
#  endif
#endif /* defined(GEN_TREES_H) || !defined(STDC) */
#ifdef GEN_TREES_H
#  ifndef ZLIB_DEBUG
#    include <stdio.h>
#  endif
#  define SEPARATOR(i, last, width) \
#endif /* GEN_TREES_H */
#ifdef ZLIB_DEBUG
#endif
#define SMALLEST 1
#define pqremove(s, tree, top) \
#define smaller(tree, n, m, depth) \
#ifdef DUMP_BL_TREE
#endif
#ifdef ZLIB_DEBUG
#endif
#ifdef ZLIB_DEBUG
#endif
#ifdef FORCE_STORED
#else
#endif
#ifdef FORCE_STATIC
#else
#endif
#ifdef ZLIB_DEBUG
#endif
#ifdef ZLIB_DEBUG
#endif
#ifdef ZLIB_DEBUG
#endif
#ifdef TRUNCATE_BLOCK
#endif
#ifdef ZLIB_DEBUG
#endif
