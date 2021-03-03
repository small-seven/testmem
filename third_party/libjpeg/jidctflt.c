#define JPEG_INTERNALS
#include "jinclude.h"
#include "jpeglib.h"
#include "jdct.h"		/* Private declarations for DCT subsystem */
#ifdef DCT_FLOAT_SUPPORTED
#if DCTSIZE != 8
#endif
#define DEQUANTIZE(coef,quantval)  (((FAST_FLOAT) (coef)) * (quantval))
#endif /* DCT_FLOAT_SUPPORTED */
