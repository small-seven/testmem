#include "tfloat.h"
#define SAFE_FREE(p) { if (p) { free(p); (p)=NULL; } }
