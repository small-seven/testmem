#include <string.h>
#include <stdint.h>
#define F(x,y,z) (z ^ (x & (y ^ z)))
#define G(x,y,z) (y ^ (z & (y ^ x)))
#define H(x,y,z) (x ^ y ^ z)
#define I(x,y,z) (y ^ (x | ~z))
#define FF(a,b,c,d,w,s,t) a += F(b,c,d) + w + t; a = rol(a,s) + b
#define GG(a,b,c,d,w,s,t) a += G(b,c,d) + w + t; a = rol(a,s) + b
#define HH(a,b,c,d,w,s,t) a += H(b,c,d) + w + t; a = rol(a,s) + b
#define II(a,b,c,d,w,s,t) a += I(b,c,d) + w + t; a = rol(a,s) + b
#define KEY_MAX 30000
#define SALT_MAX 8
