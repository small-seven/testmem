#include <openssl/camellia.h>
#include "cmll_local.h"
#include <string.h>
#include <stdlib.h>
#define RightRotate(x, s) ( ((x) >> (s)) + ((x) << (32 - s)) )
#define LeftRotate(x, s)  ( ((x) << (s)) + ((x) >> (32 - s)) )
#define GETU32(p)   (((u32)(p)[0] << 24) ^ ((u32)(p)[1] << 16) ^ ((u32)(p)[2] <<  8) ^ ((u32)(p)[3]))
#define PUTU32(p,v) ((p)[0] = (u8)((v) >> 24), (p)[1] = (u8)((v) >> 16), (p)[2] = (u8)((v) >>  8), (p)[3] = (u8)(v))
#define SBOX1_1110 Camellia_SBOX[0]
#define SBOX4_4404 Camellia_SBOX[1]
#define SBOX2_0222 Camellia_SBOX[2]
#define SBOX3_3033 Camellia_SBOX[3]
#define Camellia_Feistel(_s0,_s1,_s2,_s3,_key) do {\
#define RotLeft128(_s0,_s1,_s2,_s3,_n) do {\
