#include "pwf.h"
#include <pthread.h>
#include <unsupported_api.h>
#define FIX(x) (pw->pw_##x = pw->pw_##x-line+buf)
