#include "faanidct.h"
#include "libavutil/common.h"
typedef float FLOAT;

#define B0 1.0000000000000000000000
#define B1 1.3870398453221474618216 // cos(pi*1/16)sqrt(2)
#define B2 1.3065629648763765278566 // cos(pi*2/16)sqrt(2)
#define B3 1.1758756024193587169745 // cos(pi*3/16)sqrt(2)
#define B4 1.0000000000000000000000 // cos(pi*4/16)sqrt(2)
#define B5 0.7856949583871021812779 // cos(pi*5/16)sqrt(2)
#define B6 0.5411961001461969843997 // cos(pi*6/16)sqrt(2)
#define B7 0.2758993792829430123360 // cos(pi*7/16)sqrt(2)

#define A4 0.70710678118654752438 // cos(pi*4/16)
#define A2 0.92387953251128675613 // cos(pi*2/16)

static const FLOAT prescale[64]={
B0*B0/8, B0*B1/8, B0*B2/8, B0*B3/8, B0*B4/8, B0*B5/8, B0*B6/8, B0*B7/8,
B1*B0/8, B1*B1/8, B1*B2/8, B1*B3/8, B1*B4/8, B1*B5/8, B1*B6/8, B1*B7/8,
B2*B0/8, B2*B1/8, B2*B2/8, B2*B3/8, B2*B4/8, B2*B5/8, B2*B6/8, B2*B7/8,
B3*B0/8, B3*B1/8, B3*B2/8, B3*B3/8, B3*B4/8, B3*B5/8, B3*B6/8, B3*B7/8,
B4*B0/8, B4*B1/8, B4*B2/8, B4*B3/8, B4*B4/8, B4*B5/8, B4*B6/8, B4*B7/8,
B5*B0/8, B5*B1/8, B5*B2/8, B5*B3/8, B5*B4/8, B5*B5/8, B5*B6/8, B5*B7/8,
B6*B0/8, B6*B1/8, B6*B2/8, B6*B3/8, B6*B4/8, B6*B5/8, B6*B6/8, B6*B7/8,
B7*B0/8, B7*B1/8, B7*B2/8, B7*B3/8, B7*B4/8, B7*B5/8, B7*B6/8, B7*B7/8,
};
