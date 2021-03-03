#include <math.h>
#include <stdio.h>
#define GEN_INT_TEST(EXPR) printf("check_int (\"%s\", %s, %d);\n", #EXPR, #EXPR, EXPR);
#define GEN_DBL_TEST(EXPR) printf("check_double (\"%s\", %s, %.20E);\n", #EXPR, #EXPR, EXPR);
