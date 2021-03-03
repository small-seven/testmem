#define JPEG_INTERNALS
#include "jinclude.h"
#include "jpeglib.h"
#include "jdct.h"		/* Private declarations for DCT subsystem */
#ifdef DCT_FLOAT_SUPPORTED
#if DCTSIZE != 8
#endif
#endif /* DCT_FLOAT_SUPPORTED */
