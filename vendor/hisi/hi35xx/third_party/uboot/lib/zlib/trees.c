#include "deflate.h"
#ifdef DEBUG
#  include <ctype.h>
#endif
#define MAX_BL_BITS 7
#define END_BLOCK 256
#define REP_3_6      16
#define REPZ_3_10    17
#define REPZ_11_138  18
#define Buf_size (8 * 2*sizeof(char))
#define DIST_CODE_LEN  512 /* see definition of array dist_code below */
#if defined(GEN_TREES_H) || !defined(STDC)
#else
#  include "trees.h"
#endif /* GEN_TREES_H */
#ifdef GEN_TREES_H
#endif
#ifndef DEBUG
#  define send_code(s, c, tree) send_bits(s, tree[c].Code, tree[c].Len)
#else /* DEBUG */
#  define send_code(s, c, tree) \
#endif
#define put_short(s, w) { \
#ifdef DEBUG
#else /* !DEBUG */
#define send_bits(s, value, length) \
#endif /* DEBUG */
#if defined(GEN_TREES_H) || !defined(STDC)
#ifdef NO_INIT_GLOBAL_POINTERS
#endif
#  ifdef GEN_TREES_H
#  endif
#endif /* defined(GEN_TREES_H) || !defined(STDC) */
#ifdef GEN_TREES_H
#  ifndef DEBUG
#    include <stdio.h>
#  endif
#  define SEPARATOR(i, last, width) \
#endif /* GEN_TREES_H */
#ifdef DEBUG
#endif
#define SMALLEST 1
#define pqremove(s, tree, top) \
#define smaller(tree, n, m, depth) \
#ifdef DUMP_BL_TREE
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef FORCE_STORED
#else
#endif
#ifdef FORCE_STATIC
#else
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef TRUNCATE_BLOCK
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
