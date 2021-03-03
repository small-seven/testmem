#define PNG_EXPORTA(ordinal, type, name, args, attributes)\
#define PNG_REMOVED(ordinal, type, name, args, attributes)\
#define PNG_EXPORT_LAST_ORDINAL(ordinal)\
#include "pnglibconf.h.prebuilt"
#include "../png.h"
#define PNG_BENIGN_ERRORS_SUPPORTED
#define PNG_ERROR_NUMBERS_SUPPORTED
#define PNG_READ_BIG_ENDIAN_SUPPORTED  /* should do nothing! */
#define PNG_INCH_CONVERSIONS_SUPPORTED
#define PNG_READ_16_TO_8_ACCURATE_SCALE_SUPPORTED
#define PNG_SET_OPTION_SUPPORTED
#undef PNG_H
#include "../png.h"
#undef  PNG_FLOATING_POINT_SUPPORTED /* Exposes 'fixed' APIs */
#undef  PNG_ERROR_TEXT_SUPPORTED     /* Exposes unsupported APIs */
#undef PNG_H
#include "../png.h"
