#include "app_demo_i2s.h"
#ifndef I2S_TEST_DEBUG
#define i2s_print(ftm...) do {printf(ftm);} while (0);
#else
#define i2s_print(ftm...)
#endif
