#include "eaidct.h"
#include "libavutil/common.h"
#define ASQRT 181 /* (1/sqrt(2))<<8 */
#define A4    669 /* cos(pi/8)*sqrt(2)<<9 */
#define A2    277 /* sin(pi/8)*sqrt(2)<<9 */
#define A5    196 /* sin(pi/8)<<9 */
#define IDCT_TRANSFORM(dest,s0,s1,s2,s3,s4,s5,s6,s7,d0,d1,d2,d3,d4,d5,d6,d7,munge,src) {\
#define MUNGE_NONE(x) (x)
#define IDCT_COL(dest,src) IDCT_TRANSFORM(dest,0,8,16,24,32,40,48,56,0,8,16,24,32,40,48,56,MUNGE_NONE,src)
#define MUNGE_8BIT(x) av_clip_uint8((x)>>4)
#define IDCT_ROW(dest,src) IDCT_TRANSFORM(dest,0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,MUNGE_8BIT,src)
