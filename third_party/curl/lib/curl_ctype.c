#include "curl_setup.h"
#ifndef CURL_DOES_CONVERSIONS
#undef _U
#define _U (1<<0) /* upper case */
#undef _L
#define _L (1<<1) /* lower case */
#undef _N
#define _N (1<<2) /* decimal numerical digit */
#undef _S
#define _S (1<<3) /* space */
#undef _P
#define _P (1<<4) /* punctuation */
#undef _C
#define _C (1<<5) /* control */
#undef _X
#define _X (1<<6) /* hexadecimal letter */
#undef _B
#define _B (1<<7) /* blank */
#endif /* !CURL_DOES_CONVERSIONS */
