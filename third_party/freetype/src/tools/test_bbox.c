#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_BBOX_H
#include <time.h>    /* for clock() */
#if defined(__sun__) && !defined(SVR4) && !defined(__SVR4)
#include <sys/param.h>
#define CLOCKS_PER_SEC HZ
#endif
#define  XSCALE    65536
#define  XX(x)     ((FT_Pos)(x*XSCALE))
#define  XVEC(x,y)  { XX(x), XX(y) }
#define  XVAL(x)   ((x)/(1.0*XSCALE))
#if 1
#else
#endif
#define REPEAT  1000000L
