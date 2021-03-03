#include "ecma-builtin-helpers.h"
#include "ecma-globals.h"
#include "ecma-helpers.h"
#include "test-common.h"
#define MS_PER_DAY ((ecma_number_t) 86400000)
#define MS_PER_YEAR ((ecma_number_t) 365 * MS_PER_DAY)
#define START_OF_GREGORIAN_CALENDAR ((ecma_number_t) (-1970 * MS_PER_YEAR \
