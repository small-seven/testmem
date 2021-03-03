#include "common.h"
#include "pca.h"
typedef struct PCA{
    int count;
    int n;
    double *covariance;
    double *mean;
    double *z;
}PCA;
#define ROTATE(a,i,j,k,l) {\
