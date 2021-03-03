#include "zip_file.h"
#include <cassert>
#include <cstring>
#include <limits>
#include <ostream>
#include "log.h"
#include "securec.h"
#include "zlib.h"
#define ZIPPOS_ADD_AND_CHECK_OVERFLOW(first, second, sum)                               \
