#include <errno.h>
#include <sys/timex.h>
#include "tst_test.h"
#define SET_MODE (ADJ_OFFSET | ADJ_FREQUENCY | ADJ_MAXERROR | ADJ_ESTERROR | \
