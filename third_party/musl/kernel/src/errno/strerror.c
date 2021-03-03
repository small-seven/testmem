#include <errno.h>
#include <string.h>
#include "locale_impl.h"
#ifdef __cplusplus
#endif
#define E(a,b) ((unsigned char)a),
#include "__strerror.h"
#undef E
#define E(a,b) b "\0"
#include "__strerror.h"
#ifdef __cplusplus
#endif
