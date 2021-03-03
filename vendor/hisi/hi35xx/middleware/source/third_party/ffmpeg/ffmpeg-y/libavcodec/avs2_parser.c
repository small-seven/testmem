#include "parser.h"
#define SLICE_MAX_START_CODE    0x000001af
#define ISPIC(x)  ((x) == 0xB3 || (x) == 0xB6)
#define ISUNIT(x) ((x) == 0xB0 || (x) == 0xB1 || (x) == 0xB2 || ISPIC(x))
