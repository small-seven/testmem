#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#define Ch(x,y,z)  (z ^ (x & (y ^ z)))
#define Maj(x,y,z) ((x & y) | (z & (x | y)))
#define S0(x)      (ror(x,28) ^ ror(x,34) ^ ror(x,39))
#define S1(x)      (ror(x,14) ^ ror(x,18) ^ ror(x,41))
#define R0(x)      (ror(x,1) ^ ror(x,8) ^ (x>>7))
#define R1(x)      (ror(x,19) ^ ror(x,61) ^ (x>>6))
#define KEY_MAX 256
#define SALT_MAX 16
#define ROUNDS_DEFAULT 5000
#define ROUNDS_MIN 1000
#define ROUNDS_MAX 9999999
#if 1
#else
#endif
