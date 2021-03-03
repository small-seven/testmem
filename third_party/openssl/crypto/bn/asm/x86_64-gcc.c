#include "../bn_local.h"
#if !(defined(__GNUC__) && __GNUC__>=2)
# include "../bn_asm.c"         /* kind of dirty hack for Sun Studio */
#else
# undef mul
# undef mul_add
# define mul_add(r,a,word,carry) do {   \
# define mul(r,a,word,carry) do {       \
# undef sqr
# define sqr(r0,r1,a)                   \
# ifndef SIMICS
# else
#  define BN_MASK2 0xffffffffffffffffL
# endif
# if 0
#  define mul_add_c(a,b,c0,c1,c2)       do {    \
#  define mul_add_c2(a,b,c0,c1,c2)      do {    \
#  define sqr_add_c(a,i,c0,c1,c2)       do {    \
# else
#  define mul_add_c(a,b,c0,c1,c2) do {  \
#  define sqr_add_c(a,i,c0,c1,c2) do {  \
#  define mul_add_c2(a,b,c0,c1,c2) do { \
# endif
# define sqr_add_c2(a,i,j,c0,c1,c2)      \
#endif
