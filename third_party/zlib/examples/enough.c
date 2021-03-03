#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define local static
typedef unsigned long long big_t;   /* type for code counting */
typedef unsigned long long code_t;  /* type for bit pattern counting */
struct tab {                        /* type for been here check */
    size_t len;         /* length of bit vector in char's */
    char *vec;          /* allocated bit vector */
};
#define INDEX(i,j,k) (((size_t)((i-1)>>1)*((i-2)>>1)+(j>>1)-1)*(max-1)+k-1)
