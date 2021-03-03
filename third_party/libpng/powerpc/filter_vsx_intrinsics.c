#include <stdio.h>
#include <stdint.h>
#include "../pngpriv.h"
#ifdef PNG_READ_SUPPORTED
#if PNG_POWERPC_VSX_IMPLEMENTATION == 1 /* intrinsics code from pngpriv.h */
#include <altivec.h>
#if PNG_POWERPC_VSX_OPT > 0
#ifndef __VSX__
#  error "This code requires VSX support (POWER7 and later). Please provide -mvsx compiler flag."
#endif
#define vec_ld_unaligned(vec,data) vec = vec_vsx_ld(0,data)
#define vec_st_unaligned(vec,data) vec_vsx_st(vec,0,data)
#define vsx_declare_common_vars(row_info,row,prev_row,offset) \
#ifdef __LITTLE_ENDIAN__
#elif defined(__BIG_ENDIAN__)
#endif
#define vsx_char_to_short(vec,offset,bpp) (vector unsigned short)vec_perm((vec),VSX_CHAR_ZERO,VSX_CHAR_TO_SHORT##offset##_##bpp)
#define vsx_short_to_char(vec,offset,bpp) vec_perm(((vector unsigned char)(vec)),VSX_CHAR_ZERO,VSX_SHORT_TO_CHAR##offset##_##bpp)
#ifdef PNG_USE_ABS
#  define vsx_abs(number) abs(number)
#else
#  define vsx_abs(number) (number > 0) ? (number) : -(number)
#endif
#define if_then_else(c,t,e) vec_sel(e,t,c)
#define vsx_paeth_process(rp,pp,a,b,c,pa,pb,pc,bpp) {\
#endif /* PNG_POWERPC_VSX_OPT > 0 */
#endif /* PNG_POWERPC_VSX_IMPLEMENTATION == 1 (intrinsics) */
#endif /* READ */
