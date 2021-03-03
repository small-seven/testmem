#include <stdint.h>
#include "mathops.h"
#define times4(x) x, x, x, x
#define times256(x) times4(times4(times4(times4(times4(x)))))
