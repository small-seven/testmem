#include "curl_setup.h"
#ifndef HAVE_STRTOK_R
#include <stddef.h>
#include "strtok.h"
#endif /* this was only compiled if strtok_r wasn't present */
