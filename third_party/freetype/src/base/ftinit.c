#include <ft2build.h>
#include FT_CONFIG_CONFIG_H
#include FT_INTERNAL_OBJECTS_H
#include FT_INTERNAL_DEBUG_H
#include FT_MODULE_H
#undef  FT_COMPONENT
#define FT_COMPONENT  init
#undef  FT_USE_MODULE
#ifdef __cplusplus
#define FT_USE_MODULE( type, x )  extern "C" const type  x;
#else
#define FT_USE_MODULE( type, x )  extern const type  x;
#endif
#include FT_CONFIG_MODULES_H
#undef  FT_USE_MODULE
#define FT_USE_MODULE( type, x )  (const FT_Module_Class*)&(x),
#include FT_CONFIG_MODULES_H
#ifdef FT_CONFIG_OPTION_ENVIRONMENT_PROPERTIES
#define MAX_LENGTH  128
#else
#endif
