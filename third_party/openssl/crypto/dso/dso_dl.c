#include "dso_local.h"
#ifdef DSO_DL
# include <dl.h>
# define DSO_MAX_TRANSLATED_SIZE 256
#endif                          /* DSO_DL */
