#include <string.h>
#include "apps.h"
#include "progs.h"
#include <openssl/bn.h>
typedef enum OPTION_choice {
    OPT_ERR = -1, OPT_EOF = 0, OPT_HELP,
    OPT_HEX, OPT_GENERATE, OPT_BITS, OPT_SAFE, OPT_CHECKS
} OPTION_CHOICE;
