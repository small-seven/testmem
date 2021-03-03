#include "hos_types.h"
#include <securec.h>
#include "hctest.h"
#include "utils_file.h"
#define QUERY_TIMES    50
#define FILE_SEEK_OFFSET_10 10
#define FILE_SEEK_OFFSET_20 20
#define FILE_SEEK_OFFSET_50 50
#define FILE_SEEK_OFFSET_MINUS_10 (-10)
#define FILE_SEEK_OFFSET_MINUS_20 (-20)
#define FILE_SEEK_OFFSET_MINUS_50 (-50)
#define LENGTH_OF_READ_BUF 36
