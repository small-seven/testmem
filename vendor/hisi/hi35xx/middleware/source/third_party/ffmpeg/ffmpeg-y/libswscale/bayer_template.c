#if defined(BAYER_BGGR) || defined(BAYER_GBRG)
#define BAYER_R       0
#define BAYER_G       1
#define BAYER_B       2
#endif
#if defined(BAYER_RGGB) || defined(BAYER_GRBG)
#define BAYER_R       2
#define BAYER_G       1
#define BAYER_B       0
#endif
#if defined(BAYER_8)
#define BAYER_READ(x) (x)
#define BAYER_SIZEOF  1
#define BAYER_SHIFT   0
#endif
#if defined(BAYER_16LE)
#define BAYER_READ(x) AV_RL16(&(x))
#define BAYER_SIZEOF  2
#define BAYER_SHIFT   8
#endif
#if defined(BAYER_16BE)
#define BAYER_READ(x) AV_RB16(&(x))
#define BAYER_SIZEOF  2
#define BAYER_SHIFT   8
#endif
#define S(y, x) BAYER_READ(src[(y)*src_stride + BAYER_SIZEOF*(x)])
#define T(y, x) (unsigned int)S(y, x)
#define R(y, x) dst[(y)*dst_stride + (x)*3 + BAYER_R]
#define G(y, x) dst[(y)*dst_stride + (x)*3 + BAYER_G]
#define B(y, x) dst[(y)*dst_stride + (x)*3 + BAYER_B]
#if defined(BAYER_BGGR) || defined(BAYER_RGGB)
#define BAYER_TO_RGB24_COPY \
#define BAYER_TO_RGB24_INTERPOLATE \
#else
#define BAYER_TO_RGB24_COPY \
#define BAYER_TO_RGB24_INTERPOLATE \
#endif
#define rgb24toyv12_2x2(src, dstY, dstU, dstV, luma_stride, src_stride, rgb2yuv) \
#undef S
#undef T
#undef R
#undef G
#undef B
#undef BAYER_TO_RGB24_COPY
#undef BAYER_TO_RGB24_INTERPOLATE
#undef BAYER_RENAME
#undef BAYER_R
#undef BAYER_G
#undef BAYER_B
#undef BAYER_READ
#undef BAYER_SIZEOF
#undef BAYER_SHIFT
#if defined(BAYER_BGGR)
#undef BAYER_BGGR
#endif
#if defined(BAYER_RGGB)
#undef BAYER_RGGB
#endif
#if defined(BAYER_GBRG)
#undef BAYER_GBRG
#endif
#if defined(BAYER_GRBG)
#undef BAYER_GRBG
#endif
#if defined(BAYER_8)
#undef BAYER_8
#endif
#if defined(BAYER_16LE)
#undef BAYER_16LE
#endif
#if defined(BAYER_16BE)
#undef BAYER_16BE
#endif
