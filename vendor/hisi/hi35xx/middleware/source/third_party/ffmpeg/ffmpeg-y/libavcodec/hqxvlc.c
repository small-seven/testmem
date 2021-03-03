#include "hqx.h"
#define RPT_2(a, b, c)    { a, b, c }, { a, b, c }
#define RPT_4(a, b, c)    RPT_2(  a, b, c), RPT_2(  a, b, c)
#define RPT_8(a, b, c)    RPT_4(  a, b, c), RPT_4(  a, b, c)
#define RPT_16(a, b, c)   RPT_8(  a, b, c), RPT_8(  a, b, c)
#define RPT_32(a, b, c)   RPT_16( a, b, c), RPT_16( a, b, c)
#define RPT_64(a, b, c)   RPT_32( a, b, c), RPT_32( a, b, c)
#define RPT_128(a, b, c)  RPT_64( a, b, c), RPT_64( a, b, c)
#define RPT_256(a, b, c)  RPT_128(a, b, c), RPT_128(a, b, c)
#define RPT_512(a, b, c)  RPT_256(a, b, c), RPT_256(a, b, c)
#define RPT_1024(a, b, c) RPT_512(a, b, c), RPT_512(a, b, c)
#define INIT_DC_TABLE(idx, name)                                              \
