#include <ft2build.h>
#include FT_INTERNAL_DEBUG_H
#include FT_ERRORS_H
#if defined( FT_CONFIG_OPTION_ERROR_STRINGS ) || \
#undef FTERRORS_H_
#define FT_ERROR_START_LIST     switch ( FT_ERROR_BASE( error_code ) ) {
#define FT_ERRORDEF( e, v, s )    case v: return s;
#define FT_ERROR_END_LIST       }
#include FT_ERRORS_H
#endif /* defined( FT_CONFIG_OPTION_ERROR_STRINGS ) || ... */
