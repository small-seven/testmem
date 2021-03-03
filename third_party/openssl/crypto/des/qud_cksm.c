#include "des_local.h"
#define Q_B0(a) (((DES_LONG)(a)))
#define Q_B1(a) (((DES_LONG)(a))<<8)
#define Q_B2(a) (((DES_LONG)(a))<<16)
#define Q_B3(a) (((DES_LONG)(a))<<24)
#define NOISE   ((DES_LONG)83653421L)
