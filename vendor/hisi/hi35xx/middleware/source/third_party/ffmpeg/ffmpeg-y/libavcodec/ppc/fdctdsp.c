#include "config.h"
#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "libavutil/ppc/cpu.h"
#include "libavutil/ppc/util_altivec.h"
#include "libavcodec/fdctdsp.h"
#include "fdct.h"
#if HAVE_ALTIVEC
#define vs16(v)   ((vector signed short) (v))
#define vs32(v)     ((vector signed int) (v))
#define  vu8(v)  ((vector unsigned char) (v))
#define vu16(v) ((vector unsigned short) (v))
#define vu32(v)   ((vector unsigned int) (v))
#define C1     0.98078528040323044912618224 /* cos(1 * PI / 16) */
#define C2     0.92387953251128675612818319 /* cos(2 * PI / 16) */
#define C3     0.83146961230254523707878838 /* cos(3 * PI / 16) */
#define C4     0.70710678118654752440084436 /* cos(4 * PI / 16) */
#define C5     0.55557023301960222474283081 /* cos(5 * PI / 16) */
#define C6     0.38268343236508977172845998 /* cos(6 * PI / 16) */
#define C7     0.19509032201612826784828487 /* cos(7 * PI / 16) */
#define W0 -(2 * C2)
#define W1  (2 * C6)
#define W2 (M_SQRT2 * C6)
#define W3 (M_SQRT2 * C3)
#define W4 (M_SQRT2 * (-C1 + C3 + C5 - C7))
#define W5 (M_SQRT2 *  (C1 + C3 - C5 + C7))
#define W6 (M_SQRT2 *  (C1 + C3 + C5 - C7))
#define W7 (M_SQRT2 *  (C1 + C3 - C5 - C7))
#define W8 (M_SQRT2 *  (C7 - C3))
#define W9 (M_SQRT2 * (-C1 - C3))
#define WA (M_SQRT2 * (-C3 - C5))
#define WB (M_SQRT2 *  (C5 - C3))
#define LD_W0 vec_splat(cnsts0, 0)
#define LD_W1 vec_splat(cnsts0, 1)
#define LD_W2 vec_splat(cnsts0, 2)
#define LD_W3 vec_splat(cnsts0, 3)
#define LD_W4 vec_splat(cnsts1, 0)
#define LD_W5 vec_splat(cnsts1, 1)
#define LD_W6 vec_splat(cnsts1, 2)
#define LD_W7 vec_splat(cnsts1, 3)
#define LD_W8 vec_splat(cnsts2, 0)
#define LD_W9 vec_splat(cnsts2, 1)
#define LD_WA vec_splat(cnsts2, 2)
#define LD_WB vec_splat(cnsts2, 3)
#define FDCTROW(b0, b1, b2, b3, b4, b5, b6, b7) /* {{{ */           \
#define FDCTCOL(b0, b1, b2, b3, b4, b5, b6, b7) /* {{{ */           \
#define MERGE_S16(hl, a, b) vec_merge ## hl(vs16(a), vs16(b))
#undef MERGE_S16
#define CTF0(n)                                                    \
#undef CTF0
#define CTFX(x, b)                                  \
#undef CTFX
#define CTS(n)                                                  \
#undef CTS
#endif /* HAVE_ALTIVEC */
#if HAVE_ALTIVEC
#endif /* HAVE_ALTIVEC */
